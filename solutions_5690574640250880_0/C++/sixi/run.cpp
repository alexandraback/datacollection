#include <iostream>
#include <vector>
using namespace std;

void printOutput(int idx, string text) {
    cout << "Case #" << idx << ": " << text << endl;
}

void printBoard(vector<vector<char> > &board) {
    for (int i = 0; i < board.size(); ++i) {
        vector<char> row = board[i];
        for (int j = 0; j < row.size(); ++j) {
            cout << row[j];
        }
        cout << endl;
    }
}

void handleCase(int idx) {
    cout << "Case #" << idx << ":" << endl;
    int r, c, m;
    cin >> r >> c >> m;
    // cout << r << ' ' << c << ' ' << m << endl;
    vector<vector<char> > board(r, vector<char>(c, '*'));
    int empty = r * c - m;
    if (empty == 1) {
        board[0][0] = 'c';
        printBoard(board);
    } else if (r == 1 or c == 1) {
        board[0][0] = 'c';
        if (r == 1) {
            for (int i = 1; i < empty; ++i) {
                board[0][i] = '.';
            }
        } else {
            for (int i = 1; i < empty; ++i) {
                board[i][0] = '.';
            }
        }
        printBoard(board);
    } else if (empty == 2 or empty == 3) {
        cout << "Impossible" << endl;
    } else if (empty == 5 or empty == 7) {
        cout << "Impossible" << endl;
    } else if (r == 2 or c == 2) {
        if (empty % 2 == 1) {
            cout << "Impossible" << endl;
        } else {
            if (r == 2) {
                for (int i = 0; i < empty / 2; ++i) {
                    board[0][i] = '.';
                    board[1][i] = '.';
                }
            } else {
                for (int i = 0; i < empty / 2; ++i) {
                    board[i][0] = '.';
                    board[i][1] = '.';
                }
            }
            board[0][0] = 'c';
            printBoard(board);
        }
    } else {
        int threshold = (r << 1) + (c << 1) - 3;
        if (empty >= threshold) {
            for (int i = 0; i < r; ++i) {
                board[i][0] = '.';
                board[i][1] = '.';
            }
            empty -= r << 1;
            for (int i = 0; i < r; ++i) {
                for (int j = 2; j < c; ++j) {
                    board[i][j] = '.';
                    --empty;
                    if (empty == 0) {
                        break;
                    }
                }
                if (empty == 0) {
                    break;
                }
            }
            board[0][0] = 'c';
            printBoard(board);
        } else {
            board[0][0] = 'c';
            board[0][1] = '.';
            board[1][0] = '.';
            board[1][1] = '.';
            empty -= 4;
            if (empty > 0) {
                board[0][2] = '.';
                board[1][2] = '.';
                empty -= 2;
            }
            if (empty > 0) {
                board[2][0] = '.';
                board[2][1] = '.';
                empty -= 2;
            }
            if (empty > 0) {
                if (empty % 2 == 1) {
                    board[2][2] = '.';
                    empty -= 1;
                }
                for (int i = 3; i < c && empty > 0; ++i) {
                    board[0][i] = '.';
                    board[1][i] = '.';
                    empty -= 2;
                }
                for (int i = 3; i < r && empty > 0; ++i) {
                    board[i][0] = '.';
                    board[i][1] = '.';
                    empty -= 2;
                }
            }
            printBoard(board);
        }
    }
    // cout << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        handleCase(i);
    }
}
