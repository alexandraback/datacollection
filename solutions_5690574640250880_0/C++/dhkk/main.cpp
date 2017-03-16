#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int N = 55;
int n, m, k;
bool g[N][N];

int main()
{
    freopen("C-small-attempt2.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int _, cas = 0;
    scanf("%d", &_);
    while (_--)
    {
        scanf("%d%d%d", &n, &m, &k);
        printf("Case #%d:\n", ++cas);
        if (k == n*m-1)
        {
            printf("c");
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (!i && !j) continue;
                    printf("*");
                }
                puts("");
            }
        }
        else if (n == 1 || m == 1)
        {
            printf("c");
            int cnt = n*m-k-1;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (!i && !j) continue;
                    if (!cnt) printf("*");
                    else cnt--, printf(".");
                }
                puts("");
            }
        }
        else if (k > n*m-4 || k == n*m-5 || k == n*m-7)
        {
            puts("Impossible");
        }
        else if (n == 2 || m == 2)
        {
            if (k&1)
            {
                puts("Impossible");
                continue;
            }
            memset(g, 1, sizeof(g));
            if (n == 2)
            {
                for (int i = 0; i < (n*m-k)/2; i++)
                {
                    g[0][i] = g[1][i] = 0;
                }
            }
            else
            {
                for (int i = 0; i < (n*m-k)/2; i++)
                {
                    g[i][0] = g[i][1] = 0;
                }
            }
            printf("c");
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (!i && !j) continue;
                    if (g[i][j]) printf("*");
                    else printf(".");
                }
                puts("");
            }
        }
        else
        {
            memset(g, 1, sizeof(g));
            //g[0][0] = g[0][1] = g[1][0] = g[1][1] = g[2][0] g[2][1] = 0;
            int cnt = n*m-k, i, j;
            for (i = 0; i < n-1; i += 2)
            {
                for (j = 0; j < m; j++)
                {
                    cnt -= 2;
                    g[i][j] = g[i+1][j] = 0;
                    if (cnt < 2) break;
                }
                if (cnt < 2) break;
            }
            if (i == n-1 && cnt != 1)
            {
                for (int l = 0; l < cnt; l++)
                {
                    g[i][l] = 0;
                }
            }
            if (!j)
            {
                g[i+1][j] = 1;
                for (int l = 0; l < cnt+2; l++)
                {
                    g[i][l] = 0;
                }
            }
            else if (cnt)
            {
                if (!i)
                {
                    g[i][j] = g[i+1][j] = 1;
                    for (int l = 0; l < cnt+2; l++)
                    {
                        g[i+2][l] = 0;
                    }
                }
                else if (j == m-1)
                {
                    g[i+1][j] = 1;
                    g[i+2][0] = g[i+2][1] = 0;
                }
                else
                {
                    g[i][j+1] = 0;
                }
            }
            printf("c");
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (!i && !j) continue;
                    else if (g[i][j]) printf("*");
                    else printf(".");
                }
                puts("");
            }
        }
    }
    return 0;
}
