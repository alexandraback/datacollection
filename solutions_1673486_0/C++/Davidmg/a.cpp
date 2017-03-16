#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

double p, t, ans;
int T, a, b;

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        scanf("%d%d", &a, &b);
        p = 1;
        ans = min(2.0 + b, 1.0 + a + b);
        for (int i = 1; i <= a; i++)
        {
            scanf("%lf", &t);
            p *= t;
            ans = min(ans, p * ((a - i) * 2 + b - a + 1) + (1 - p) * ((a - i) * 2 + 2 * b - a + 2));
        }
        printf("Case #%d: %.6lf\n", cas, ans);
    }  
    return 0;
}
