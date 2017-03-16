#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>

using namespace std;

#define type_assign(a, b) \
    typeof(b) a = b
#define iterate(a, b) \
    for (type_assign(a, b.begin()); a != b.end(); ++a)

double C, F, X;

bool solve(double t) {
    double f = 2, i = 0, sx = 0;
    while (i < t) {
        if (f * (t - i) + sx >= X) return true;
        if (sx >= C) {
            int n = int(sx / C);
            f += n * F;
            sx -= n * C;
        } else {
            i += (C - sx) / f;
            sx = C;
        }
    }
    return false;
}

int main() {
    int i, j, k, t, nc = 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%lf%lf%lf", &C, &F, &X);
        double l = 0, r = 100000;
        for (i = 0; i < 60; ++i) {
            double mid = (l + r) / 2;
            if (solve(mid)) r = mid;
            else l = mid;
        }
        printf("Case #%d: %.7lf\n", ++nc, l);
    }
    return 0;
}
