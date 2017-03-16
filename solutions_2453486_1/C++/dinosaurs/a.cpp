#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

const int MAXN = 11;

int T, rowcount[MAXN][2], colcount[MAXN][2], diagcount[2][2], tcount;
char board[MAXN][MAXN];

int main() {
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        tcount = 0;
        diagcount[0][0] = diagcount[0][1] = diagcount[1][0] = diagcount[1][1] = 0;
        for (int i = 0; i < 4; i++) {
            rowcount[i][0] = rowcount[i][1] = 0;
            colcount[i][0] = colcount[i][1] = 0;
        }

        bool owon = false, xwon = false;
        for (int i = 0; i < 4; i++) {
            scanf("%s", board[i]);
            for (int j = 0; j < 4; j++) {
                if (board[i][j] == 'O' || board[i][j] == 'T') {
                    rowcount[i][0]++;
                    colcount[j][0]++;
                    if (i == j) {
                        diagcount[0][0]++;
                    }
                    if (i + j == 3) {
                        diagcount[1][0]++;
                    }
                }
                if (board[i][j] == 'X' || board[i][j] == 'T') {
                    rowcount[i][1]++;
                    colcount[j][1]++;
                    if (i == j) {
                        diagcount[0][1]++;
                    }
                    if (i + j == 3) {
                        diagcount[1][1]++;
                    }
                }
                if (board[i][j] != '.') {
                    tcount++;
                }
                if (rowcount[i][0] == 4 || colcount[j][0] == 4 || diagcount[0][0] == 4 || diagcount[1][0] == 4) {
                    owon = true;
                }
                if (rowcount[i][1] == 4 || colcount[j][1] == 4 || diagcount[0][1] == 4 || diagcount[1][1] == 4) {
                    xwon = true;
                }
            }
        }

        if (owon) {
            printf("Case #%d: O won\n", t);
        } else if (xwon) {
            printf("Case #%d: X won\n", t);
        } else if (tcount == 16) {
            printf("Case #%d: Draw\n", t);
        } else {
            printf("Case #%d: Game has not completed\n", t);
        }
    }

    return 0;
}
