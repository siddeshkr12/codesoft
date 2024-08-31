#include <iostream>
#include <string>
using namespace std;

string pl1, pl2;
int game(int);
int check(char[3][3]);
void display(char[3][3]);
int roundno = 1;

int main() {
    int i, p1 = 0, p2 = 0, r, d = 0, j = 0;

    cout << "Enter first player name: ";
    cin >> pl1;
    cout << "Enter second player name: ";
    cin >> pl2;

    do {
        r = game(j++);
        if (r == 1) {
            p1++;
            cout << pl1 << " has won this round..." << endl;
        } else if (r == 2) {
            p2++;
            cout << pl2 << " has won this round..." << endl;
        } else {
            d++;
            cout << "This round is draw..." << endl;
        }

        cout << "Current score:\n" << pl1 << " = " << p1 << "\n" << pl2 << " = " << p2 << endl;
        cout << "Enter 1 to play again or enter 0 to end the game: ";
        cin >> i;
    } while (i == 1);

    cout << "Final result:\n" << pl1 << " = " << p1 << "\n" << pl2 << " = " << p2 << endl;
    if (p1 != p2) {
        cout << "The winner is " << (p1 > p2 ? pl1 : pl2) << endl;
    } else {
        cout << "The game is draw..." << endl;
    }

    return 0;
}

int game(int j) {
    char board[3][3];
    int a, c, moveCount = 0;

    // Initialize the board
    for (int i = 0; i < 3; i++) {
        for (int k = 0; k < 3; k++) {
            board[i][k] = '1' + i * 3 + k;
        }
    }

    display(board);
    cout << "Round " << roundno++ << endl;

    if (j % 2 == 0) {
        cout << "x for " << pl1 << " and o for " << pl2 << endl;
    } else {
        cout << "o for " << pl1 << " and x for " << pl2 << endl;
    }

    while (moveCount < 9) {
        if ((j % 2 == 0 && moveCount % 2 == 0) || (j % 2 != 0 && moveCount % 2 != 0)) {
            cout << pl1 << ", enter the element number to write " << (j % 2 == 0 ? 'x' : 'o') << ": ";
        } else {
            cout << pl2 << ", enter the element number to write " << (j % 2 == 0 ? 'o' : 'x') << ": ";
        }

        cin >> a;
        a--;

        if (a < 0 || a > 8 || board[a / 3][a % 3] == 'x' || board[a / 3][a % 3] == 'o') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        board[a / 3][a % 3] = ((j % 2 == 0 && moveCount % 2 == 0) || (j % 2 != 0 && moveCount % 2 != 0)) ? 'x' : 'o';
        moveCount++;

        display(board);
        c = check(board);
        if (c == 1) return (j % 2 == 0 && moveCount % 2 == 0) || (j % 2 != 0 && moveCount % 2 != 0) ? 1 : 2;
    }

    return 0;  // Draw
}

int check(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;
    return 0;
}

void display(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "|" << board[i][j];
        }
        cout << "|" << endl;
    }
}
