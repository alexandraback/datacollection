#include <iostream>
#include <cstdio>

using namespace std;

int res[4][4][4][11];
bool a[4][4][4][11][4][4][4];

int main()
{
    freopen("2.txt", "r", stdin);

    int n, m, k, t;
    while (scanf("%d%d%d%d", &n, &m, &k, &t) == 4)
    {
                    scanf("%d", &res[n][m][k][t]);
                    for (int i = 0; i < res[n][m][k][t]; i++)
                    {
                        int x, y, z;
                        scanf("%d%d%d", &x, &y, &z);
                        a[n][m][k][t][x][y][z] = true;
                    }
                }

    fclose(stdin);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int cntTests;
    scanf("%d", &cntTests);
    for (int i = 1; i <= cntTests; i++)
    {
        int n, m, k, t;
        scanf("%d%d%d%d", &n, &m, &k, &t);
        printf("Case #%d: %d\n", i, res[n][m][k][t]);

        for (int x = 1; x <= n; x++)
            for (int y = 1; y <= m; y++)
                for (int z = 1; z <= k; z++)
                    if (a[n][m][k][t][x][y][z]) printf("%d %d %d\n", x, y, z);
    }
}
