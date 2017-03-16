#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
    char g[50][50];
    int T;
    scanf("%d", &T);
    int r, c, m;
    for (int t = 1; t <= T; t++) {
        scanf("%d %d %d", &r, &c, &m);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++)
                g[i][j] = '*';
        }
        g[0][0] = 'c';
        printf("Case #%d:\n", t);
        if (r == 1) {
            for (int i = 1; i < c - m; i++)
                g[0][i] = '.';
        }
        else if (c == 1) {
            for (int i = 1; i < r - m; i++)
                g[i][0] = '.';
        }
        else {
            int nom = r * c - m;
            if (nom == 2 || nom == 3 || nom == 5 || nom == 7) {
                printf("Impossible\n");
                continue;
            }
            if ((r == 2 || c == 2) && nom & 1 && nom > 2) {
                printf("Impossible\n");
                continue;
            }
            nom--;
            if (nom > 0) {
                g[1][0] = '.';
                nom -= 1;
            }
            int nc = 1;
            while (nc < c && nom > 2) {
                g[0][nc] = '.';
                g[1][nc] = '.';
                nom -= 2;
                nc++;
            }
            int nr = 0;
            if (nc == c) {
                nc = 0;
                nr = 2;
                while (nom > 2) {
                    if (nom > c) {
                        for (int i = 0; i < c; i++)
                            g[nr][i] = '.';
                        nom -= c;
                        nr++;
                    }
                    else {
                        for (int i = 0; i < nom; i++)
                            g[nr][i] = '.';
                        nom = 0;
                    }
                }
                if (nom == 1) {
                    g[nr][0] = '.';
                    g[nr][1] = '.';
                    if (nr == 2) {
                        g[0][c - 1] = '*';
                        g[1][c - 1] = '*';
                        g[nr][2] = '.';
                    }
                    else {
                        g[nr - 1][c - 1] = '*';
                    }
                }
                else if (nom == 2) {
                    g[nr][0] = '.';
                    g[nr][1] = '.';
                }
            }
            else {
                if (nom == 2) {
                    g[0][nc] = '.';
                    g[1][nc] = '.';
                }
                else if (nom == 1) {
                    g[2][0] = '.';
                    g[2][1] = '.';
                    g[2][2] = '.';
                    g[0][nc - 1] = '*';
                    g[1][nc - 1] = '*';
                }
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++)
                putchar(g[i][j]);
            putchar('\n');
        }
    }
    return 0;
}
