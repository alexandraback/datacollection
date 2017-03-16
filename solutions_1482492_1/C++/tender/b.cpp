/*
 * Author: tender
 * Created Time:  2012/5/6 18:34:16
 * File Name: b.cpp
 */
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <set>

using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-7;
int sgn(const double &t) {
    return t > eps ? 1 : (t < -eps ? -1 : 0);
}
const int maxn = 2000;
double t[maxn + 5], x[maxn + 5], v[maxn + 5];
int main() {
    int cas;
    freopen("bl.in", "r", stdin);
    freopen("2.txt", "w", stdout);
    scanf("%d", &cas);
    for (int ii = 1; ii <= cas; ii++) {
        printf("Case #%d:\n", ii);
        double D;
        int n, A;
        scanf("%lf%d%d", &D, &n, &A);
        for (int i = 0; i < n; i++) scanf("%lf%lf", &t[i], &x[i]);
        int tmp = n - 1;
        while(sgn(x[tmp] - D) >= 0) tmp--;
        t[tmp + 1] = (D - x[tmp]) * (t[tmp + 1] - t[tmp]) / (x[tmp + 1] - x[tmp]) + t[tmp];
        x[tmp + 1] = D;
        n = tmp + 2;
        //for (int i = 0; i < n; i++)
            //printf("%.6lf %.6lf\n", t[i], x[i]);
        //printf("\n");
        x[0] = 0;
        for (int i = 1; i < n; i++) v[i] = (x[i] - x[i - 1]) / (t[i] - t[i - 1]);
        while(A--) {
            double a;
            scanf("%lf", &a);
            if (n == 1) {
                printf("%.6lf\n", sqrt(2 * D / a));
                continue;
            }
            double vv = 0, ans = 0;
            for (int i = 1; i < n; i++) {
                //printf("i = %d vv = %.6lf\n", i, vv);
                double tt = t[i] - t[i - 1];
                double l = x[i - 1] + vv * tt + 0.5 * a * tt * tt;
                //printf("l = %.6lf x[i] = %.6lf\n", l, x[i]);
                if (sgn(l - x[i]) >= 0) {
                    double v1 = sqrt(2 * a * x[i]);
                    if (sgn(v[i] - v1) >= 0) {
                        vv = v[i];
                        ans += tt;
                    }
                    else {
                        vv = v1;
                        ans = t[i];
                    }
                }
                else {
                    double vt = sqrt(vv * vv + 2 * a * (x[i] - x[i - 1]));
                    //printf("vt = %.6lf\n", vt);
                    ans += (vt - vv) / a;
                    vv = vt;
                }
            }
            printf("%.10lf\n", ans);
        }
    }
    return 0;
}
