#include <iostream>
#include <cstdio>
#include <cstring>
#define LL long long
using namespace std;
LL a[110], A[110], b[110], B[110], n, m, ans;
void dfs(LL deep, LL sum, LL last, LL now)
{
    //printf("%lld %lld %lld %lld\n", deep, sum , last, now);
    if (sum + last <= ans) return;
    ans = max(ans, sum);
    if (deep == n + 1) return;
    dfs(deep + 1, sum, last - a[deep], now);
    LL nowa = a[deep];
    for (LL i = now; i <= m; ++i)
        if (A[deep] == B[i])
        {
            LL delta = min(b[i], nowa);
            nowa -= delta;
            b[i] -= delta;
            sum += delta;
            if (!b[i])
                dfs(deep + 1, sum, last - a[deep], i + 1);
            else
                dfs(deep + 1, sum, last - a[deep], i);
            b[i] += delta;
            if (!nowa) break;
        }
}
int main()
{
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    LL T;
    scanf("%lld", &T);
    for (LL ca = 1; ca <= T; ++ca)
    {
        ans = 0;
        scanf("%lld%lld", &n, &m);
        for (LL i = 1; i <= n; ++i)
            scanf("%lld%lld", &a[i], &A[i]);
        for (LL i = 1; i <= m; ++i)
            scanf("%lld%lld", &b[i], &B[i]);
        LL s = 0;
        for (LL i = 1; i <= n; ++i)
            s += a[i];
        dfs(1, 0, s, 1);
        printf("Case #%lld: %lld\n", ca, ans);
    }
    return 0;
}
