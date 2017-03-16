#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

int M, R, C;
char board[100][100];

void makeAns(int r, int c, int k, int l) {
    fill(board[0], board[55], '*');
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            board[i][j] = '.';
        }
    }
    for (int i = 0; i < k; ++i) {
        board[i][c] = '.';
    }
    for (int i = 0; i < l; ++i) {
        board[r][i] = '.';
    }
    board[0][0] = 'c';
}

int solve() {
    int dest = R * C - M;
    if (R == 1 || C == 1 || (R * C - 1 == M)) {
        fill(board[0], board[55], '*');
        int count = 0;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                board[i][j] = '.';
                if (++count == dest) {
                    board[0][0] = 'c';
                    return 1;
                }
            }
        }
    }

    for (int i = 2; i <= R; ++i) {
        for (int j = 2; j <= C; ++j) {
            for (int k = 0; k <= i; ++k) {
                if (k == 1) {
                    continue;
                }
                if (k > 0 && j == C) {
                    continue;
                }
                for (int l = 0; l <= j; ++l) {
                    if (l == 1) {
                        continue;
                    }
                    if (l > 0 && i == R) {
                        continue;
                    } 
                    if (i * j + k + l == dest) {
                        makeAns(i, j, k, l);
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}


int main() {
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        printf("Case #%d:\n", cs);
        scanf("%d %d %d", &R, &C, &M);
        if (solve()) {
            for (int i = 0; i < R; ++i) {
                for (int j = 0; j < C; ++j) {
                    printf("%c", board[i][j]);
                }
                printf("\n");
            }
        } else {
            printf("Impossible\n");
        }
    }
    return 0;
}

