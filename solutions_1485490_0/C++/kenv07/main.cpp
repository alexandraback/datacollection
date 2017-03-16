#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

class hyj{
    public : long long x, a;
};

hyj f[110][110];

long long fa[110], fb[110], check, ans;
int a[110], b[110];

long long min(long long q, long long w)
{
    if (q > w) return w;
    return q;
}

long long max(long long q, long long w)
{
    if (q > w) return q;
    return w;
}

int main()
{
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int t, n, m;
    cin >> t;
    for (int qw = 1; qw <= t; qw ++)
    {
        memset(f, 0, sizeof(f));
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        cin >> n >> m;
        for (int i = 1; i <= n; i ++)
        {
            cin >> fa[i] >> a[i];
        }
        for (int i = 1; i <= m; i ++)
        {
            cin >> fb[i] >> b[i];
        }
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= m; j ++)
                f[i][j].a = fb[j];
        for (int i = 1; i <= n; i ++)
          for (int w = i - 1; w >= 0; w --)
            for (int j = 1; j <= m + 1; j ++)
            {
                if ((f[w][j].x > f[i][j].x) || ((f[w][j].x == f[i][j].x) && (f[w][j].a != f[i][j].a))) f[i][j] = f[w][j];
                for (int k = j - 1; k >= 0; k --)
                {
                    check = 0;
                    for (int q = k + 1; q <= j; q ++)
                        if (a[i] == b[q]) check += fb[q];
                    if (a[i] == b[k]) check += f[w][k].a;
                    if (f[i][j].x <= f[w][k].x + min(check, fa[i]))
                    {
                        f[i][j].x = f[w][k].x + min(check, fa[i]);
                        if (b[j] == a[i])
                        if (check > fa[i])
                        if (check - fa[i] < fb[j]) f[i][j].a = check - fa[i];
                    }
                }

                /*{
                    check = 0;
                    for (int q = k + 1; q <= j; q ++)
                        if (b[q] == a[i]) check += fb[q];
                    if (a[i] == b[k]) check += f
                    //f[i][j].x = max(f[i - 1][k].x + check, f[i][j].x);
                    if (f[i - 1][k].x + min(check, fa[i]) > f[i][j].x)
                    {
                        f[i][j].x = f[i - 1][k].x;
                        if ((a[i] == b[j]) && (check > fa[i] ) && (check - fa[i] < fb[j])) f[i][j].a = check - fa[i];
                            else f[i][j].a = fb[j];
                    }
                }
               f[i][j].x = max(f[i][j].x, f[i - 1][j].x);*/
            }
        ans = 0;
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= m; j ++)
                ans = max(f[i][j].x, ans);
        cout << "Case #" << qw << ": " << ans << endl;
    }
    return 0;
}
