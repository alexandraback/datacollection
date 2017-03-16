#include <cstdio>
#include <set>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;
double p[1000010];
static const double eps = 1e-7;
double inner_solve();
double calc(int, int, int, bool);

double calc(int n, int h, int y, bool right)
{
    double a = 0.0, b = 0.0;
    p[0] = 1.0;
    for (int i = 1; i <= n; i ++)
        p[i] = p[i - 1] * (double)i;
    for (int l = 0; l <= n; l ++)
        if (l <= h && n - l <= h)
        {
            int r = n - l;
            if (right)
            {
                if (r > y) a += p[n] / p[l] / p[r];
                b += p[n] / p[l] / p[r];
            }
            else
            {
                if (l > y) a += p[n] / p[l] / p[r];
                b += p[n] / p[l] / p[r];
            }
        }
    return a / b;
}

double inner_solve()
{
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    int l = 0;
    for (;;)
    {
        if (n - l * 2 - l * 2 - 1 >= 0)
        {
            n = n - l * 2 - l * 2 - 1;
            ++l;
        }
        else break;
    }
    int w = l * 2 - 1;
    int needed = l * 2;
    if (abs(x) + abs(y) <= w) return 1.0;
    if (abs(x) + abs(y) > w + 2) return 0.0;
    if (!x) return 0.0;
    return calc(n, needed, y, x > 0);
}

void solve(int tc)
{
    printf("Case #%d: %lf\n", tc, inner_solve());
}


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t  = 0;
    scanf("%d", &t);
    for(int i = 1; i <= t; ++i)
        solve(i);
    return 0;
}
