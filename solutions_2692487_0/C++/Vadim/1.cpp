#include <cstdio>
#include <memory.h>
#include <iostream>
#include <algorithm>

using namespace std;

int tttt, now, n, a[1111111], ans, cur;

int main()
{
        freopen("1.in", "r", stdin);
        freopen("1.txt", "w", stdout);
        scanf("%d", &tttt);
        for (int test = 1; test <= tttt; test++)
        {
                memset(a, 0, sizeof(a));
                now = n = 0;
                ans = 2000000000;
                printf("Case #%d: ", test);
                scanf("%d%d", &now, &n);
                for (int i = 1; i<=n; i++) scanf("%d", &a[i]);
                if (now == 1)
                {
                        cout << n << endl;
                        continue;
                }                
                sort(a+1, a+n+1);
                cur = 0;
                for (int i = 1; i<=n; i++)
                        if (a[i] < now) now += a[i]; else
                        {
                                ans = min(ans, cur+(n-i+1));
                                while (now <= a[i])
                                {
                                        cur++;
                                        now += now-1;
                                }
                                now += a[i];
                        }
                ans = min(ans, cur);
                cout << ans << endl;
        }
        return 0;
}
