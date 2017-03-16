#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;

int run;

void solve() {
    double C, F, X;
    scanf("%lf%lf%lf", &C, &F, &X);
    double cost = 0, res = 1e50, per = 2;
    while (cost < res) {
        res = min(res, cost+X/per);
        cost += C/per;
        per += F;
    }
    printf("Case #%d: %.7f\n", run, res);
}

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int test;
    scanf("%d", &test);
    for (run = 1; run <= test; run++) {
        solve();
    }
    return 0;
}
