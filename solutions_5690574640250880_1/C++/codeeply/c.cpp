#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>

using namespace std;

#define type_assign(a, b) \
    typeof(b) a = b
#define iterate(a, b) \
    for (type_assign(a, b.begin()); a != b.end(); ++a)
#define clr(a, c) memset(a, c, sizeof(a))

const int N = 55;
int R, C, m;
bool g[N][N];

void output(int work, int nc) {
    printf("Case #%d:\n", nc);
    if (!work) {
        printf("Impossible\n");
        return;
    }

    int i, j;
    for (i = 0; i < R; ++i) {
        for (j = 0; j < C; ++j) {
            char c;
            if (i == 0 && j == 0) {
                c = 'c';
            } else if (g[i][j]) {
                c = '.';
            } else {
                c = '*';
            }

            printf("%c", c);
            if (j == C - 1) printf("\n");
        }
    }
}

int main() {
    int i, j, k, t, nc = 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &R, &C, &m);
        int n = R * C - m;
        clr(g, 0);
        int work = 0;
        if (n == 1) {
            g[0][0] = 1;
            work = 1;
        } else if (R == 1) {
            for (i = 0; i < n; ++i) {
                g[0][i] = 1;
            }
            work = 1;
        } else if (C == 1) {
            for (i = 0; i < n; ++i) {
                g[i][0] = 1;
            }
            work = 1;
        } else {
            for (i = 2; i <= R; ++i) {
                for (j = 2; j <= C; ++j) {
                    if (i * j >= n && (i + j) * 2 - 4 <= n) {
                        work = 1;
                    }
                    if (!work) continue;
                    
                    int x, y;
                    for (x = 0; x < R; ++x) for (y = 0; y < C; ++y) {
                        if (x >= i || y >= j) continue;
                        if (x >= 2 && y >= 2) continue;
                        g[x][y] = 1;
                    }
                    x = y = 2;
                    int rem = n - ((i + j) * 2 - 4);
                    while (rem > 0) {
                        if (y < j) {
                            g[x][y] = 1;
                            y++;
                            rem--;
                        } else {
                            y = 2;
                            x++;
                        }
                    }
                    break;
                }
                if (j <= C) break;
            }
        }
        output(work, ++nc);
    }
    return 0;
}
