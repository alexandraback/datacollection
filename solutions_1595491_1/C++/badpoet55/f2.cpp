//GCJ Q p2 f2

#include <iostream>
#include <cstdio>

using namespace std;

int ans, a[31], n, t, s, p, k;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        for (int i = 0; i <= 30; i++) a[i] = 0;
        cin >> n >> s >> p;
        for (int i = 0; i < n; i++)
        {
            cin >> k;
            a[k]++;
        }
        if (!p) ans = n;
        else
        {
            ans = 0;
            for (int i = (p - 1) * 3 + 1; i <= 30; i++) ans += a[i];
            if (p > 1)
            {
                k = a[(p - 1) * 3] + a[(p - 1) * 3 - 1];
                ans += (k > s ? s : k);
            }
        }
        printf("Case #%d: %d\n", tc, ans);
    }
    return 0;
}
