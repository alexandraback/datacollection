#include <cstdio>
#include <iostream>
using namespace std;

double C, F, X;

void solve() {
    scanf("%lf%lf%lf", &C, &F, &X);
    C = (long long)(C * 1e5 + 1e-3) * 1e-5;
    F = (long long)(F * 1e5 + 1e-3) * 1e-5;
    X = (long long)(X * 1e5 + 1e-3) * 1e-5;
    double ans = X / 2.0;
    double cnt = 0;
    double speed = 2;
    while (true) {
        cnt += C / (speed + 0.0);
        speed += F;
        double spend = cnt + X / (speed + 0.0);
        if (spend >= ans) {
            break;
        }
        ans = spend;
    }
    printf("%.7f\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int caseId = 1; caseId <= T; ++caseId) {
        printf("Case #%d: ", caseId);
        solve();
    }
}
