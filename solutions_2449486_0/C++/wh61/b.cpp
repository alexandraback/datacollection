#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int a[110][110];
int r[110], c[110];
int n, m;

int main()
{
    freopen("in.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T, ca = 0;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d", &n, &m);
        memset(r, 0 ,sizeof(r));
        memset(c, 0 ,sizeof(c));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                scanf("%d", &a[i][j]);
                r[i] = max(r[i], a[i][j]);
                c[j] = max(c[j], a[i][j]);
            }
        int ans = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                if (r[i] > a[i][j] && c[j] > a[i][j]) ans = 0;
            }
        if (ans)
            printf("Case #%d: YES\n", ++ca);
        else
            printf("Case #%d: NO\n", ++ca);
    }
    return 0;
}
