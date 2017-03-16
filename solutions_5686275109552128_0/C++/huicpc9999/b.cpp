#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

int d, p[2000];

int main()
{
    //freopen("B-small-attempt4.in", "r", stdin);
    //freopen("B-small-attempt4.out", "w", stdout);
    int T; scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas)
    {
        scanf("%d", &d);
        int maxp = 0;
        for (int i = 0; i < d; ++i)
        {
            scanf("%d", &p[i]);
            maxp = max(maxp, p[i]);
        }
        int ans = maxp;
        for (int i = 1; i <= maxp; ++i)
        {
            int tmp = i;
            for (int k = 0; k < d; ++k) tmp += (p[k]-1)/i;
            ans = min(tmp, ans);
        }
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
