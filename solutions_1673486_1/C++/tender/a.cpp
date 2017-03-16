/*
 * Author: tender
 * Created Time:  2012/4/28 10:24:50
 * File Name: a.cpp
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
const int maxn = 100000;
const double inf = 1e100;
double p[maxn + 5];
int A, B;
double f1() {
    double tmp = 1;
    for (int i = 1; i <= A; i++) tmp *= p[i];
    return tmp * (B - A + 1) + (1 - tmp) * (2 * B - A + 2);
}
double f2() {
    double res = inf, pp = 1;
    for (int i = 1; i <= A; i++) {
        pp *= p[i];
        //res = min(res, -pp * (B + 1) - i);
        res = min(res, pp * (A + B - 2 * i + 1) + (1 - pp) * (A + 2 * B - 2 * i + 2));
    }
    return res;
}
int main() {
    int cas;
    //freopen("al.in", "r", stdin);
    //freopen("2.txt", "w", stdout);
    scanf("%d", &cas);
    for (int ii = 1; ii <= cas; ii++) {
        printf("Case #%d: ", ii);
        scanf("%d%d", &A, &B);
        for (int i = 1; i <= A; i++) scanf("%lf", &p[i]);
        double ans = inf;
        ans = min(ans, f1());
        ans = min(ans, (double)B + 2);
        ans = min(ans, f2());
        printf("%.10lf\n", ans);
    }
    return 0;
}
