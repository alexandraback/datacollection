#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>

using namespace std;

double pp[100005];
double rp[100005];
double wp[100005];
int a, b;
int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca) {
        scanf("%d%d", &a, &b);
        for (int i = 0; i < a; ++i)
            scanf("%lf", &pp[i]);
        rp[0] = pp[0];
        wp[0] = 1.0 - pp[0];
        for (int i = 1; i < a; ++i) {
            rp[i] = rp[i - 1] * pp[i];
            wp[i] = wp[i - 1] + rp[i - 1] * (1.0 - pp[i]);
        }
        double ans = b + 2;
        double tt = rp[a - 1] * (b - a + 1) + wp[a - 1] * (b - a + 1 + b + 1);
        ans = min(ans, tt);
        for (int i = 1; i < a; ++i) {
            tt = rp[a - 1 - i] * (i + (b - (a - i)) + 1) +
                wp[a - 1 - i] * (i + (b - (a - i)) + 1 + b + 1);
            if (tt < ans) ans = tt;
        }
        printf("Case #%d: %.6lf\n", ca, ans);
    }
    return 0;
}
