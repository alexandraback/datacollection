#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100010;
const int EPS = 1e-8;

int T, n, a, b;
double p[MAXN];
double ans;

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("out.out", "w", stdout);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas)
    {
        ans = 1e100;
        scanf("%d%d", &a, &b);
        for (int i = 1; i <= a; ++i) scanf("%lf", p + i);
        ans = min(ans, 1.0 * (b + 2));

        double pp = 1;
        for (int i = 1; i <= a; ++i)
        {
            int n = a - i;
            pp *= p[i];
            double tmp;
            tmp = 1.0 * n + pp * (b - a + n + 1) + (1.0 - pp) * (b - a + n + 1 + b + 1);
            ans = min(ans, tmp);
        }
        printf("Case #%d: %.7f\n", cas, ans);
    }
    return 0;
}