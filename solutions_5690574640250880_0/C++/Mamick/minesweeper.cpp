#include <iostream>
#include <vector>
#include <cstring>

char board[55][55];
bool boardVis[55][55];

using namespace std;
int rsize, csize;

int countAdjMines(int r, int c) {
    int cum = 0;
    for (int dr = -1; dr <= 1; dr++) {
        for (int dc = -1; dc <= 1; dc++) {
            if (dr + r >= 0 && dr + r < rsize && dc + c >= 0 && dc + c < csize && board[dr + r][dc + c] == '*') {
                cum ++;
            }
        }
    }
    return cum;
}

int flood(int r, int c) {
    if (boardVis[r][c]) return 0;
    int cum = 1;
    boardVis[r][c] = true;
    for (int dr = -1; dr <= 1; dr++) {
        for (int dc = -1; dc <= 1; dc++) {
            if (dr + r >= 0 && dr + r < rsize && dc + c >= 0 && dc + c < csize && board[dr + r][dc + c] != '*' && countAdjMines(r, c) == 0) {
                cum += flood(dr + r, dc + c);
            }
        }
    }
    return cum;
}

int main() {
    int n;
    cin >> n;
    for (int count = 1; count <= n; count ++) {
        int m, r, c;
        cin >> r >> c >> m;
        rsize = r; csize = c;
        int size = 0;
        int numPlaced = 0;
        memset(board, 0, sizeof(board));
        memset(boardVis, 0, sizeof(boardVis));
        while (numPlaced < m) {
            // for (int i = 0; i <= size; i++) {
            //     if (i < r && size - i < c && numPlaced < m) {
            //         board[i][size - i] = '*';
            //         numPlaced++;
            //     }
            // }
            if (size < r - 3) {
                for (int i = 0; i < csize; i++) {
                    if (m - numPlaced == 1 && i == csize - 2) break;
                    if (numPlaced < m) {
                        board[size][i] = '*';
                        numPlaced++;
                    }
                }
            } else if (numPlaced < m) {
                int j;
                for (j = 0; j < csize; j++) {
                    if (m - numPlaced == 2 && !(rsize <= 2)) break;
                    for (int i = (rsize - 3 < 0 ? 0 : rsize - 3); i < rsize; i++) {
                        if (numPlaced < m) {
                            board[i][j] = '*';
                            numPlaced++;
                        }
                    }
                }
                if (numPlaced < m) {
                    board[(rsize - 3 < 0 ? 0 : rsize - 3)][j] = '*';
                    if (j + 1 >= csize) {
                        board[rsize - 2][j] = '*';
                    } else {
                        board[rsize - 3][j + 1] = '*';
                    }
                    numPlaced += 2;
                }
            }
            size++;
        }


        cout << "Case #" << count << ":" << endl;
        if (board[r-1][c-1] == '*') cout << "Impossible" << endl;
        else {
            int num = flood(r-1, c-1);
            // cout << num << endl;
            if ((num + m == r * c)) {
                for (int i = 0; i < r; i++) {
                    for (int j = 0; j < c; j++) {
                        if (i == r - 1 && j == c - 1) cout << 'c';
                        else {
                            cout << (board[i][j] == '*' ? '*' : '.');
                        }
                    }
                    cout << endl;
                }
            } else {
                cout << "Impossible" << endl;
            }
        }
    }
}