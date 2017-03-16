/*
 * Author: WHHeV
 * Created Time:  2012/4/28 10:26:37
 * File Name: a.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

double p[100010];
double sum[100010];
int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int T, tc;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; ++tc) {
        int a, b;
        scanf("%d%d", &a, &b);
        for (int i = 0; i < a; ++i) {
            scanf("%lf", &p[i]);
        }
        double pp = 1.0;
        for (int i = 0; i < a; ++i) {
            pp *= p[i];
            sum[i] = pp;
        }
        double ans = pp * (b - a + 1) + (1.0 - pp) * (b - a + 2 + b);
        //printf("%.6lf\n", ans);
        ans = min(ans, (double)(b + 2));
        for (int i = 1; i < a; ++i) {
            if (a - i - 1 >= 0) {
                pp = sum[a - i - 1] * (b - a + 1 + i * 2) + (1.0 - sum[a - i - 1]) * (b - a + 2 + i * 2 + b);
            }
            ans = min(ans, pp);
        }
        ans = min(ans, double(a + b + 1));
        printf("Case #%d: %.6lf\n", tc, ans);
    }
    return 0;
}

