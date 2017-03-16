#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int T;
    long long r, t;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas)
    {
        scanf("%lld%lld", &r, &t);
        int ans = 0;
        while (t > 0)
        {
            t -= (r + 1) * (r + 1) - r * r;
            if (t >= 0)
            {
                ++ ans;
                r += 2;
            }
            else
            {
                break;
            }
        }
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
