#include <iostream>
#include <string>

using namespace std;

void doTest(int tt) {
    string board[4];
    int rr, cc;
    for (rr=0; rr<4; ++rr) {
        cin >> board[rr];
    }

    //cerr << " Board : " << endl;
    //for (rr=0; rr<4; ++rr) {
    //    cerr << board[rr] << endl;
    //}

    int numXinRow[4] = {0, 0, 0, 0};
    int numOinRow[4] = {0, 0, 0, 0};
    int numXinCol[4] = {0, 0, 0, 0};
    int numOinCol[4] = {0, 0, 0, 0};
    int numXinDiag[2] = {0, 0};
    int numOinDiag[2] = {0, 0};
    bool incompleteBoard = false;
    for (rr=0; rr<4; ++rr) {
        for (cc=0; cc<4; ++cc) {
            if (board[rr][cc] == 'X') {
                ++numXinRow[rr];
                ++numXinCol[cc];
                if (rr==cc) {
                    ++numXinDiag[0];
                } else if ((rr+cc)==3) {
                    ++numXinDiag[1];
                }
            } else if (board[rr][cc] == 'O') {
                ++numOinRow[rr];
                ++numOinCol[cc];
                if (rr==cc) {
                    ++numOinDiag[0];
                } else if ((rr+cc)==3) {
                    ++numOinDiag[1];
                }
            } else if (board[rr][cc] == 'T') {
                ++numXinRow[rr];
                ++numXinCol[cc];
                ++numOinRow[rr];
                ++numOinCol[cc];
                if (rr==cc) {
                    ++numXinDiag[0];
                    ++numOinDiag[0];
                } else if ((rr+cc)==3) {
                    ++numXinDiag[1];
                    ++numOinDiag[1];
                }
            } else if (board[rr][cc] == '.') {
                incompleteBoard = true;
            }
        }
    }
    bool XWon = false, OWon = false; 
    XWon = XWon || (numXinDiag[0] == 4);
    XWon = XWon || (numXinDiag[1] == 4);
    OWon = OWon || (numOinDiag[0] == 4);
    OWon = OWon || (numOinDiag[1] == 4);
    if (!XWon && !OWon) {
        for (rr=0; rr<4; ++rr) {
            XWon = XWon || (numXinRow[rr] == 4);
            XWon = XWon || (numXinCol[rr] == 4);
            OWon = OWon || (numOinRow[rr] == 4);
            OWon = OWon || (numOinCol[rr] == 4);
            if (XWon || OWon) break;
        }
    }

    cout << "Case #" << tt << ": ";
    if (XWon) {
        cout << "X won";
    } else if (OWon) {
        cout << "O won";
    } else if (incompleteBoard) {
        cout << "Game has not completed";
    } else {
        cout << "Draw";
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    for (int tt=1; tt<=T; ++tt) {
        doTest(tt);
    }
    return 0;
}

