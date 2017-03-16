#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OUTPUT_STRING "Case #%d: %s\n"
#define YES "YES"
#define NO "NO"
#define MAX(a,b) ((a)>(b))?(a):(b)

int nCase;
int n, m;
int g[101][101];
int xmax[101];
int ymax[101];

void PrintResult(int cn, const char* res)
{
    printf(OUTPUT_STRING, cn, res);
}

int main()
{
    //freopen("B.txt", "r", stdin);

    scanf("%d", &nCase);

    for (int cn=1; cn<=nCase; ++cn)
    {
        bool resultFound = false;
        scanf("%d%d", &n, &m);
        memset(xmax, 0, sizeof(xmax));
        memset(ymax, 0, sizeof(ymax));
        for (int i=0; i<n; ++i)
        {
            memset(g[i], 0, sizeof(g[i]));
            for (int j=0; j<m ;++j)
            {
                scanf("%d", &g[i][j]);
                xmax[i] = MAX(xmax[i], g[i][j]);
                ymax[j] = MAX(ymax[j], g[i][j]);
            }
        }

        for (int i=0; i<n && !resultFound; ++i)
        {
            for (int j=0; j<m && !resultFound; ++j)
            {
                if ((g[i][j] < xmax[i]) && (g[i][j] < ymax[j]))
                {
                    PrintResult(cn, NO);
                    resultFound = true;
                }
            }
        }

        if (resultFound) continue;

        PrintResult(cn, YES);
    }

    return 0;
}