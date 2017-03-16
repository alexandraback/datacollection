#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int a, b;
double p[100000];

double f1() {
    int i;
    double t = 1;
    for (i = 0; i < a; i++) t *= p[i];
    return t * (b - a + 1) + (1 - t) * (2 * b + 2 - a);
}

double f2() {
    int i;
    double t = 1;
    for (i = 0; i < a - 1; i++) t *= p[i];
    return t * (b + 3 - a) + (1 - t) * (2 * b + 4 - a);
}

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int i, tt = 0, icase = 0;
    scanf("%d", &icase);
    while (icase--) {
        scanf("%d%d", &a, &b);
        for (i = 0; i < a; i++) scanf("%lf", &p[i]);
        double res;
        res = min((double)b + 2, min(f1(), f2()));
        printf("Case #%d: %lf\n", ++tt, res);
    }
    return 0;
}
