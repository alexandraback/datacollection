#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int a[100][100], n, m;

int main(void)
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int T, i, j, k;
    scanf("%d", &T);
    for(int U = 1; U <= T; ++U)
    {
        scanf("%d%d", &n, &m);
        for(i = 0; i < n; ++i)
            for(j = 0; j < m; ++j)
                scanf("%d", &a[i][j]);
        bool flag = true;
        for(i = 0; i < n; ++i)
            for(j = 0; j < m; ++j)
            {
                int maxx = 1, maxy = 1;
                for(k = 0; k < n; ++k)
                    maxx = max(maxx, a[k][j]);
                for(k = 0; k < m; ++k)
                    maxy = max(maxy, a[i][k]);
                if (a[i][j] < maxx && a[i][j] < maxy)
                    flag = false;
            }
        printf("Case #%d: ", U);
        puts(flag?"YES":"NO");
    }
    return 0;
}
