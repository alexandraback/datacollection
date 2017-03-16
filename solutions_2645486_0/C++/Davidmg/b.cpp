#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int T, e, r, n;
int v[20], f[20][20];
int ans, x;

int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("2.txt", "w", stdout);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas)
    {
        scanf("%d%d%d", &e, &r, &n);
        for (int i = 1; i <= n; ++i) scanf("%d", &v[i]);
        memset(f, -1, sizeof(f));
        f[0][e] = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 0; j <= e; ++j)
            {
                if (f[i - 1][j] == -1) continue;
                for (int l = 0; l <= j; ++l)
                {
                    x = min(j - l + r, e);
                    f[i][x] = max(f[i][x], f[i - 1][j] + l * v[i]);
                }
            }
        ans = 0;
        for (int i = 0; i <= e; ++i) ans = max(ans, f[n][i]);
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
