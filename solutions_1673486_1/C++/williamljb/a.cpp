#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int   maxn = 100000 + 10;
int         n, m;
double      p[maxn], f[2][maxn];

void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%lf", p + i);
    f[0][1] = p[1];
    f[1][1] = 1 - p[1];
    for (int i = 2; i <= n; ++i)
    {
        f[0][i] = f[0][i - 1] * p[i];
        f[1][i] = 1 - f[0][i];
    }
    double ans = f[0][n] * (m - n + 1) + f[1][n] * (m - n + 1 + m + 1);
    for (int i = 1; i < n; ++i)
    {
        double tmp = f[0][n - i] * (m - n + 1 + i + i) + f[1][n - i] * (m - n + 1 + i + i + m + 1);
        if (ans > tmp)
            ans = tmp;
    }
    double tmp = 1 + m + 1;
    if (ans > tmp)
        ans = tmp;
    printf("%.6lf\n", ans);
}

int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int times;
    scanf("%d", &times);
    for (int i = 1; i <= times; ++i)
    {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}
