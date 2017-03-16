#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <cassert>
#include <ctime>
#include <queue>
#include <map>
#include <set>
#include <climits>
using namespace std;

typedef long long LL;

int R, C, M;
char board[100][100];
char visited[100][100];
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool inRange(int r, int c) {
    return r >= 0 && r < R && c >= 0 && c < C;
}
bool isZero(int r, int c) {
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (inRange(r + i, c + j) &&
                    board[r + i][c + j] == '*')
                return false;
        }
    }

    return true;
}
void dfs(int startR, int startC) {
    visited[startR][startC] = 1;

    if (!isZero(startR, startC)) {
        return;
    }

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int nextR = startR + i;
            int nextC = startC + j;
            if (inRange(nextR, nextC) && !visited[nextR][nextC]) {
                dfs(nextR, nextC);
            }
        }
    }
}
bool validate() {
    int cnt = 0;
    int startR = -1;
    int startC = -1;
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j] == '*') {
                cnt++;
            } else if (board[i][j] == 'c') {
                startR = i;
                startC = j;
            }
        }
    }

    if (cnt != M) throw "Error";

    if (startR == -1) throw "Not click.";

    dfs(startR, startC);

    cnt = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (visited[i][j] == 0) cnt++;
        }
    }

    return cnt == M;
}
void solve() {
    cin >> R >> C >> M;

    memset(board, 0, sizeof(board));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            board[i][j] = '*';
        }
    }

    int slots = R * C - M;
    for (int i = 1; i <= max(R, C); i++) {
        int area = min(i, R) * min(i, C);
        int nextArea = min(i + 1, R) * min(i + 1, C);
        if (slots == area) {
            for (int r = 0; r < min(i, R); r++) {
                for (int c = 0; c < min(i, C); c++) {
                    board[r][c] = '.';
                }
            }
            break;
        } else if (slots > area && slots < nextArea) {
            int fillR = min(i, R);
            int fillC = min(i, C);
            for (int r = 0; r < min(i, R); r++) {
                for (int c = 0; c < min(i, C); c++) {
                    board[r][c] = '.';
                }
            }

            slots -= area;
            int pending = 0;
            if (fillR == R) {
                pending = fillR;
            } else if (fillC == C) {
                pending = fillC;
            } else {
                pending = fillR + fillC + 1;
            }

            if (fillR != R) {
                for (int r = 0; r < fillC; r++) {
                    board[fillR][r] = '.';
                }
            }

            if (fillC != C) {
                for (int r = 0; r < fillR; r++) {
                    board[r][fillC] = '.';
                }
            }

            slots = pending - slots;

            if (fillR != R && fillC != C) {
                board[fillR][fillC] = '*';
                slots--;
            }
            int curR = fillR - 1;
            int curC = fillC - 1;
            while (slots) {
                if (curR > 1 && board[curR][fillC] == '.') {
                    board[curR--][fillC] = '*';
                    slots--;
                } else if (curC > 1 && board[fillR][curC] == '.') {
                    board[fillR][curC--] = '*';
                    slots--;
                } else {
                    break;
                }
            }

            if (slots >= 2) {
                if (fillC != C) {
                    board[curR--][fillC] = '*';
                    board[curR--][fillC] = '*';
                    slots -= 2;
                } else if (fillR != R) {
                    board[fillR][curC--] = '*';
                    board[fillR][curC--] = '*';
                    slots -= 2;
                }
            }

            if (slots == 1) {
                board[fillR - 1][fillC - 1] = '*';
                slots--;
            }

            if (slots != 0) { throw "Error"; }

            break;
        }
    }

    if (board[0][0] != '.') {
        printf("Impossible\n");
        return;
    }

    board[0][0] = 'c';

    if (!validate()) {
        printf("Impossible\n");
    } else {
        for (int i = 0; i < R; i++) {
            printf("%s\n", board[i]);
        }
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        printf("Case #%d:\n", t);
        solve();
    }
}


