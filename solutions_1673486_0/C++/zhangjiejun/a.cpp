#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main() {
    int t, a, b;
    static double p[200];

    cin >> t;
    for (int curt = 0; curt < t; ++curt) {
        printf("Case #%d: ", curt + 1);
        cin >> a >> b;
        for (int i = 0; i < a; ++i) {
            cin >> p[i];
        }
        double ans = 1 + b + 1;
        for (int i = 0; i <= a; ++i) {
            double prob = 1;
            for (int j = 0; j < a - i; ++j) {
                prob *= p[j];
            }
            double stroke = prob * (i + i + (b - a) + 1);
            stroke += (1 - prob) * (i + i + (b - a) + 1 + b + 1);
            ans = min(ans, stroke);
        }
        printf("%.7f\n", ans);
    }
    return 0;
}
