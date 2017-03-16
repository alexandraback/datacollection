#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

double t[2005], x[2005], y[255];

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int icase, tt = 0, n, a, i;
    double d, res, tmp, te;
    scanf("%d", &icase);
    while (icase--) {
        scanf("%lf%d%d", &d, &n, &a);
        for (i = 0; i < n; i++) scanf("%lf%lf", &t[i], &x[i]);
        double yy;
        printf("Case #%d:\n", ++tt);
        for (i = 0; i < a; i++) {
            scanf("%lf", &yy);
            if (x[0] > d) {
                res = sqrt(2.0 * d / yy);
            } else {
                tmp = (double)((x[1] - x[0])/(t[1] - t[0]));
                te = (d - x[0]) / tmp;
                res = sqrt(2.0 * d / yy);
                res = max(res, te);
            }
            printf("%lf\n", res);
        }
    }
    return 0;
}
