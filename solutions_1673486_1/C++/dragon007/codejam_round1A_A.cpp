#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

int t, a, b;
double p[100010];

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A2.out", "w", stdout);
    scanf("%d", &t);
    for (int i = 1; i <= t; i ++ ) {
        scanf("%d%d", &a, &b);
        for (int j = 0; j < a; j ++ )
            scanf("%lf", &p[j]);
        double ans = b + 2, pn = 1;
        for (int j = 0; j < a; j ++ ) {
            double ansj;
            ansj = ((a - j) * 2 + b - a + 1) + (1 - pn) * (b + 1);
            ans = min(ans, ansj);
            pn *= p[j];
        }
        double ansj = b - a + 1 + (1 - pn) * (b + 1);
        ans = min(ans, ansj);
        printf("Case #%d: %.6lf\n", i , ans);
    }
}
