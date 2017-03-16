#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main() {
    int t, a, b;
    static double p[200000], prefix[200000];

    cin >> t;
    for (int curt = 0; curt < t; ++curt) {
        printf("Case #%d: ", curt + 1);
        scanf("%d%d", &a, &b);
        for (int i = 0; i < a; ++i) {
            scanf("%lf", &p[i]);
        }
        prefix[0] = 1;
        for (int i = 0; i < a; ++i) {
            prefix[i + 1] = prefix[i] * p[i];
        }
        double ans = 1 + b + 1;
        for (int i = 0; i <= a; ++i) {
            double prob = prefix[a - i];
            double stroke = prob * (i + i + (b - a) + 1);
            stroke += (1 - prob) * (i + i + (b - a) + 1 + b + 1);
            ans = min(ans, stroke);
        }
        printf("%.7f\n", ans);
    }
    return 0;
}
