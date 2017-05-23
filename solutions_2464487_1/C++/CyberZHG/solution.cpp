#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    //freopen("A-small-attempt0.in", "r", stdin);
    //freopen("A-small-attempt0.out", "w", stdout);
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int T;
    long long r, t;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas)
    {
        scanf("%lld%lld", &r, &t);
        long long ans = 0;
        long long left = 1, right = t / 2 / r;
        right = min(right, (long long)sqrt(t * 0.5));
        while (left < right)
        {
            long long mid = (left + right) >> 1;
            long long sum = 2 * mid * r + 2 * mid * mid - mid;
            if (sum <= t)
            {
                ans = max(ans, mid);
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        printf("Case #%d: %lld\n", cas, ans);
    }
    return 0;
}
