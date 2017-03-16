#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long llong;

void solve(int tc)
{
    llong a, n;
    scanf("%lld %lld", &a, &n);
    vector<llon> V(n);
    for (int i = 0; i < n; i++)
        scanf("%lld", &V[i]);
    sort(V.begin(), V.end());
    int ans = 1e9;
    for (int q = 0; q <= n; q++)
    {
        llong cur = a;
        int cnt = q;
        for (int j = 0; j < n - q; j++)
        {
            while (cur <= V[j])
            {
                cur += cur - 1, cnt++;
                if (cnt > 100)
                    goto next;
            }
            cur += V[j];
        }
        ans = min(ans, cnt);
        next:;
    }
    printf("Case #%d: %d\n", tc, ans);
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        solve(i + 1);
}
