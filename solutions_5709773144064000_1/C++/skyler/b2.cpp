#include <iostream>
#include <cstdio>
using namespace std;

#define rep(i, n) for(int i=0; i<n; i++)
double EPS = 0.00000000001;
int t;
double c, f, x, ans;
void solve() {
    double sp = 2.0, used = 0.0;
    while (used-ans<=EPS) {
        double tmp = x/sp;
        ans = min(ans, tmp+used);

        double ti = c/sp;
        used += ti;
        sp += f;
    }

    return;
}

int main() {
    scanf("%d", &t);
    rep(i, t) {
        scanf("%lf%lf%lf", &c, &f, &x);
        ans = 1e8;
        solve();
        printf("Case #%d: %.7lf\n", i+1, ans);
    }
    return 0;
}


