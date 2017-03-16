#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

double t[3000], x[3000];

int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int q;
    cin >> q;
    for (int tt = 1; tt <= q; tt++)
    {
        double d, m;
        int n, a;
        cin >> d >> n >> a;
        for (int i = 1; i <= n; i++)
            cin >> t[i] >> x[i];
        if (n == 1)
        {
            t[2] = t[1];
            x[2] = x[1];
        }
        printf("Case #%d:\n", tt);
        for (int i = 1; i <= a; i++)
        {
            cin >> m;
            double v = (x[2] - x[1]) / (t[2] - t[1]);
            double ans = (2 * v + sqrt(4 * v * v + 8 * x[1] * m)) / (2 * m);
            if (ans <= ((d - x[1]) / v + t[1])) printf("%.11f\n", t[1] + (d - x[1]) / v); else printf("%.11f\n", sqrt(2 * d / m));
        }
    }
    return 0;
}
