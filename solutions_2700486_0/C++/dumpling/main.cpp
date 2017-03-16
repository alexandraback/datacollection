/*
 * @author: zhenpeng.fang
 * @nickname: dumpling
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <time.h>
#include <stdlib.h>
#include <stack>
#include <queue>
using namespace std;

#define mp make_pair

//%llu
typedef unsigned long long uint64;
typedef long long int64;
typedef pair<int, int> pair2;

const double eps = 1e-8;
int T, N, X, Y;
int a[1024], cnta, co[128][128];
int MAXN = 1000010;

int f(int n) {
    return 2 * n * n - n;
}

int C(int n, int k) {
    if (2 * k > n)
        k = n - k;
    return co[n][k];
}

void precalc() {
    int n = 1;
    while ((a[cnta] = f(n)) <= MAXN)
        ++n, ++cnta;
    a[cnta] = 0x7fffffff;
    for (int i = 0; i <= 20; ++i)
        co[i][0] = co[i][i] = 1;
    for (int i = 2; i <= 20; ++i) {
        for (int j = 1; j < i; ++j)
            co[i][j] = co[i - 1][j] + co[i - 1][j - 1];
    }
}

void pos2level(int x, int y, int &n, int &c) {
    c = y + 1;
    n = (x + y) / 2 + 1;
}

int level2n(int n, int c) {
    if (c == 2 * n - 1)
        return f(n);
    return f(n - 1) + c;
}

int N2n(int N) {
    int *pos = lower_bound(a, a + cnta, N);
    return (pos - a) + 1;
}

void init() {
    scanf("%d%d%d", &N, &X, &Y);
    if (X < 0)
        X = -X;
}

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    precalc();
    int n, c, n0;
    double ans = 0;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        init();
        pos2level(X, Y, n, c);
        n0 = N2n(N);
        if (n < n0)
            printf("Case #%d: 1.0\n", t);
        else if (n > n0)
            printf("Case #%d: 0.0\n", t);
        else {
            ans = 0;
            double term = 0.5;
            int l = level2n(n, c), r = f(n) - X;
            if (N >= r) {
                printf("Case #%d: 1.0\n", t);
            } else if (N < l)
                printf("Case #%d: 0.0\n", t);
            else {
                r = N;
                int total = l - f(n - 1);
                term = pow(0.5, total);
                for (int i = l; i <= r; ++i) {
                    ans += term * C(total-1, i - l);
                    term *= 0.5;
                    ++total;
                }
                printf("Case #%d: %lf\n", t, ans);
            }
        }
    }

    return 0;
}