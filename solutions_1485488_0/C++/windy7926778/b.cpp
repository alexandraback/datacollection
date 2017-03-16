#include <stdio.h>
#include <map>
#include <algorithm>

using namespace std;

int c[128][128] = { 0 }, f[128][128] = { 0 }, a[128][128] = { 0 };
bool u[128][128] = { 0 };

int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);

    int kk[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int h = 0, n = 0, m = 0, cc = 0, o = 0, i = 0, j = 0, k = 0, x = 0, y = 0, now = 0, our = 0;
    scanf("%d", &cc);
    for (o = 1; o <= cc; o ++) {
        scanf("%d%d%d", &h, &n, &m);
        for (i = 0; i < n; i ++) {
            for (j = 0; j < m; j ++) {
                scanf("%d", c[i] + j);
            }
        }
        for (i = 0; i < n; i ++) {
            for (j = 0; j < m; j ++) {
                scanf("%d", f[i] + j);
                a[i][j] = 1000000000;
            }
        }
        memset(u, 0, sizeof(u));
        a[0][0] = 0;
        while (true) {
            x = -1;
            y = -1;
            for (i = 0; i < n; i ++) {
                for (j = 0; j < m; j ++) {
                    if (!u[i][j]) {
                        if (x == -1 || a[i][j] < a[x][y]) {
                            x = i;
                            y = j;
                        }
                    }
                }
            }
            if (x == n - 1 && y == m - 1) {
                break;
            }
            u[x][y] = true;
            for (k = 0; k < 4; k ++) {
                i = x + kk[k][0];
                j = y + kk[k][1];
                if (i >= 0 && i < n && j >= 0 && j < m) {
                    if (u[i][j]) {
                        continue;
                    }
                    if (f[x][y] > c[i][j] - 50) {
                        continue;
                    }
                    if (c[x][y] < f[i][j] + 50) {
                        continue;
                    }
                    if (f[i][j] > c[i][j] - 50) {
                        continue;
                    }
                    now = h - (c[i][j] - 50);
                    if (a[x][y] > now) {
                        now = a[x][y];
                    }
                    if (now > 0) {
                        if (h - now >= f[x][y] + 20) {
                            our = now + 10;
                        }
                        else {
                            our = now + 100;
                        }
                    }
                    else {
                        our = 0;
                    }
                    if (our < a[i][j]) {
                        a[i][j] = our;
                    }
                }
            }
        }
        printf("Case #%d: %.12lf\n", o, a[n-1][m-1] * .1);
    }
    return 0;
}


        

