#include <iostream>
#include <stdio.h>
#define N 100001

using namespace std;

double p[N], P[N], ans[N];

int main()
{
    int t;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &t);
    for (int cases = 1; cases <= t; cases++) {
        int a, b;
        scanf("%d%d", &a, &b);
        P[0] = 1;
        for (int i = 1; i <= a; i++) scanf("%lf", &p[i]), P[i] = P[i - 1] * p[i];
        double best = b + 2.0;
        for (int j = 0; j <= a; j++) {
            double ans = P[a] * (j + b - a + j + 1);
            for (int i = a; i >= 1; i--)
                if (j >= a - i + 1) ans += (j + b - a + j + 1) * P[i - 1] * (1 - p[i]);
                else ans += (j + b - a + j + 1 + b + 1) * P[i - 1] * (1 - p[i]);
            best = min(best, ans);
        }
        printf("Case #%d: %.6lf\n", cases, best);
    }
    return 0;
}
