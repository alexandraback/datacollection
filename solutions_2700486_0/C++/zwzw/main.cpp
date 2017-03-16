#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 1000005;
int size[N];
int main()
{
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    int T;
    scanf("%d", &T);
    //printf("%d\n", T);
    for (int cas = 1; cas <= T; cas ++)
    {
        int n, x, y;
        scanf("%d%d%d", &n, &x, &y);
        if (x < 0) x = -x;
        int k = 1;
        while (k * (k + 1) / 2 <= n) k += 2;
        k -= 2;

        double ans = 0;
        int right;
        if (x + y <= k - 1)
            ans = 1;
        else if ((k * (k + 1) / 2) < n && x + y == k + 1 && x != 0)
        {
            n -= (k + 1) * k / 2;
            right = y  + 1;
            for (int j = right; j <= min(x + y + 1, n); j ++)
            {
                double p = 1;
                for (int i = 0; i < j; i ++)
                    p = p * (n - i) / (i + 1);
                for (int i = 0; i < n; i ++)
                    p /= 2;
                ans += p;
            }
        }
        printf("Case #%d: %lf\n", cas, ans);
    }
    return 0;
}
