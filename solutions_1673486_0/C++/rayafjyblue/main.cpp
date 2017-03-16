#include <iostream>
#include <stdio.h>

using namespace std;

int a, b;
double p[5];

double f1() {
    return min((double)b + 2, b * p[0] + (1 - p[0]) * (2 * b + 1));
}

double f2() {
    double t1, t2, t3;
    t1 = p[0] * p[1] * (b - 1) + (1 - p[0] * p[1]) * 2 * b;
    t2 = p[0] * (b + 1) + (1 - p[0]) * 2 * (b + 1);
    t3 = b + 2;
    return min(min(t1, t2), t3);
}

double f3() {
    double t1, t2, t3;
    t1 = p[0] * p[1] * p[2] * (b - 2) + (1 - p[0] * p[1] * p[2]) * (2 * b - 1);
    t2 = p[0] * p[1] * b + (1 - p[0] * p[1]) * (2 * b + 1);
    t3 = b + 2;
    return min(min(t1, t2), t3);
}

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int i, tt = 0, icase;
    scanf("%d", &icase);
    while (icase--) {
        scanf("%d%d", &a, &b);
        for (i = 0; i < a; i++) scanf("%lf", &p[i]);
        double res;
        if (a == 1) res = f1();
        else if (a == 2) res = f2();
        else res = f3();
        printf("Case #%d: %lf\n", ++tt, res);
    }
    return 0;
}
