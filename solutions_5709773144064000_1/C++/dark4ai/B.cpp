#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cassert>
#include<cstdio>
#include<cstring>
#include<ctime>

#define DEBUGLEVEL
#ifdef DEBUGLEVEL
#define printf_debug(fmt, args...) fprintf(stderr, fmt, ##args)
#else
#define printf_debug(fmt, args...)
#endif

typedef long long llong;

using namespace std;

const int MAXN = 200000;

long double C, F, X;
long double a[MAXN];

int main() {
#ifdef DEBUG
    freopen("B-large.in", "r", stdin);
    freopen("B.out", "w", stdout);
#endif
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t) {
        cin >> C >> F >> X;
        a[0] = 0.0;
        for(int i = 1; i < MAXN; ++i) {
            a[i] = a[i - 1] + C / (2.0 + F * (i - 1.0));
        }
        // for(int i = 0; i < 10; ++i) {
        //     printf_debug("%.6f ", a[i]);
        // }
        // printf_debug("\n");
        long double mn = X / 2.0;
        for(int i = 1; i < MAXN; ++i) {
            // if(mn > a[i] + X / (2.0 + F * i)) {
            //     printf_debug("i  = %d\n", i);
            //     printf_debug("%f %f\n", a[i], X / (2.0 + F * i));
            // }
            mn = min(mn, a[i] + X / (2.0 + F * i));
        }
        printf("Case #%d: %.7f\n", t, (double)mn);
    }
    return 0;
}