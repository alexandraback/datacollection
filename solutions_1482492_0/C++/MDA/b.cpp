#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <memory>

using namespace std;

#define PROBLEM_NUM "b"
#define ATTEMPT "0"

#if 1
#   define SIZE "small"
#else
#   define SIZE "large"
#endif

#if 1
#   define PATH PROBLEM_NUM "."
#else
#   define PATH "C:/Downloads/" PROBLEM_NUM "-" SIZE "-attempt" ATTEMPT "."
#endif

double t[1000], x[1000];

void solve(int num) {
    printf("Case #%d:\n", num);
    double d;
    int n, as;
    scanf("%lf%d%d", &d, &n, &as);
    for (int i = 0; i < n; ++i) {
        double tcur, xcur;
        scanf("%lf%lf", &t[i], &x[i]);
        if (x[i] > d) {
            if (i > 0)
                t[i] = t[i-1] + (d - x[i-1]) / (x[i] - x[i-1]) * (t[i] - t[i-1]);
            x[i] = d;
        }
    }
    for (int i = 0; i < as; ++i) {
        double a;
        scanf("%lf", &a);
        double xprev = 0, tprev = 0, maxvprev = 0;
        for (int j = 0; j < n; ++j) {
            double dist = x[j] - xprev;
            double dt = (sqrt(maxvprev * maxvprev + 2 * a * dist) - maxvprev) / a;
            if (t[j]  > tprev + dt) {
                maxvprev = dist / (t[j] - tprev) -  a * (t[j] - tprev) / 2;
                if (maxvprev >= 0)
                    maxvprev = maxvprev + a * (t[j] - tprev);
                else
                    maxvprev = sqrt(2 * dist);
            } else
                maxvprev = maxvprev + a * dt;
            tprev = std::max(t[j], tprev + dt);
            xprev = x[j];
        }
        printf("%.7lf\n", tprev);
    }
}

int main() {
    freopen(PATH "in", "r", stdin);
    freopen(PATH "out", "w", stdout);
    int t;
    scanf("%d\n", &t);
    for (int i = 0; i < t; ++i) 
        solve(i + 1);
}
