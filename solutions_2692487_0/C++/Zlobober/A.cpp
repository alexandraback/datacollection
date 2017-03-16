#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

void solve(int tc)
{
    int a, n;
    scanf("%d %d", &a, &n);
    vector<int> V(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &V[i]);
    sort(V.begin(), V.end());
    int ans = 1e9;
    for (int q = 0; q <= n; q++)
    {
        int cur = a;
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
