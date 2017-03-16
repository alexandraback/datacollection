#include <stdio.h>
#include <algorithm>
#include <utility>
#include <cstring>
#include <iostream>

using namespace std;

int e[50][50];
long long d[50];

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("BBBBlarge.txt","w",stdout);
    int T;
    cin >> T;
    for (int iT  = 1; iT <= T; iT++)
    {
        for (int i = 0; i < 50; i++)
            for (int j = 0; j < 50; j++) e[i][j] = 0;

    int n;
    long long m;
    cin >> n >> m;
    d[0] = 1;
    d[1] = 1;
    e[0][1] = 1;
    for (int i = 2; i < n - 1; i++)
    {
        d[i] = d[i - 1] * 2;
        for (int j = 0; j < i; j++) e[j][i] = 1;
    }
    if (n == 2 || m == d[n - 2] * 2) { m--; e[0][n - 1] = 1; }
    for (int i = 1; i < n - 1; i++)
        if (d[i] <= m && (d[i] & m))
        {
                m -= d[i]; e[i][n - 1] = 1;
        }

    printf("Case #%d:", iT);
    if (m == 0)
    {
         printf(" POSSIBLE\n");
         for (int i = 0; i < n; i++)
         {
             for (int j = 0; j < n; j++) printf("%d", e[i][j]);
             printf("\n");
         }
    }
    else printf(" IMPOSSIBLE\n");
    }
    return 0;
}
