#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
typedef long long ll;

ll C, V; int D;
ll a[105];

int main()
{
    int TestCases; scanf("%d", &TestCases);
    for (int testcase = 1; testcase <= TestCases; testcase++) {
        scanf("%lld%d%lld", &C, &D, &V);
        for (int d = 0; d < D; d++) scanf("%lld", &a[d]);
        std::sort(a, a+D);
        ll cur = 1ll; int i = 0, ans = 0;
        while (cur <= V) {
            while (i < D && a[i] <= cur && cur <= V) {
                cur += a[i]*C;
                i++;
            }
            if (cur > V) break;
            ans++;
            cur += cur*C;
        }
        printf("Case #%d: ", testcase);
        printf("%d\n", ans);
    }
}

