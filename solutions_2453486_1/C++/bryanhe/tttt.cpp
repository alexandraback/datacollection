#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    cin >> T;
    char board[4][4];

    for (int counter = 1; counter <= T; counter++) {

        for (int r = 0; r < 4; r++) {
            for (int c = 0; c < 4; c++) {
                cin >> board[r][c];
            }
        }

        bool XWin = false;
        bool OWin = false;

        for (int r = 0; r < 4; r++) {
            int X = 0;
            int O = 0;
            int T = 0;
            for (int c = 0; c < 4; c++) {
                if (board[r][c] == 'X') {
                    X++;
                }
                else if (board[r][c] == 'O') {
                    O++;
                }
                else if (board[r][c] == 'T') {
                    T++;
                }
            }
            if (X + T == 4) {
                XWin = true;
                break;
            }
            else if (O + T == 4) {
                OWin = true;
                break;
            }
        }

        if (!(XWin || OWin)) {
            for (int c = 0; c < 4; c++) {
                int X = 0;
                int O = 0;
                int T = 0;
                for (int r = 0; r < 4; r++) {
                    if (board[r][c] == 'X') {
                        X++;
                    }
                    else if (board[r][c] == 'O') {
                        O++;
                    }
                    else if (board[r][c] == 'T') {
                        T++;
                    }
                }
                if (X + T == 4) {
                    XWin = true;
                    break;
                }
                else if (O + T == 4) {
                    OWin = true;
                    break;
                }
            }

            if (!(XWin || OWin)) {
                int X = 0;
                int O = 0;
                int T = 0;
                for (int n = 0; n < 4; n++) {
                    if (board[n][n] == 'X') {
                        X++;
                    }
                    else if (board[n][n] == 'O') {
                        O++;
                    }
                    else if (board[n][n] == 'T') {
                        T++;
                    }
                }
                if (X + T == 4) {
                    XWin = true;
                }
                else if (O + T == 4) {
                    OWin = true;
                }


                X = 0;
                O = 0;
                T = 0;
                for (int n = 0; n < 4; n++) {
                    if (board[n][3 - n] == 'X') {
                        X++;
                    }
                    else if (board[n][3 - n] == 'O') {
                        O++;
                    }
                    else if (board[n][3 - n] == 'T') {
                        T++;
                    }
                }
                if (X + T == 4) {
                    XWin = true;
                }
                else if (O + T == 4) {
                    OWin = true;
                }
            }
        }

        int count = 0;
        for (int r = 0; r < 4; r++) {
            for (int c = 0; c < 4; c++) {
                if (board[r][c] != '.') {
                    count++;
                }
            }
        }

        cout << "Case #" << counter << ": ";

        if (XWin) {
            cout << "X won";
        }
        else if (OWin) {
            cout << "O won";
        }
        else if (count == 16) {
            cout << "Draw";
        }
        else {
            cout << "Game has not completed";
        }

        cout << "\n";

    }

    return 0;

}

