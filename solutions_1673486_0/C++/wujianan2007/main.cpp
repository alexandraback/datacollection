#include <iostream>
#include <cstdio>
using namespace std;
#define MAXN 100005
int t;
int a, b;
double p[MAXN];

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    cin >> t;
    for (int cas = 1; cas <= t; cas++) {
        cin >> a >> b;
        p[0] = 1;
        for (int i = 1; i <= a; i++) {
            cin >> p[i];
            p[i] *= p[i - 1];
        }
        double ans = 1e99;
        for (int i = 0; i <= a; i++) {
            ans = min(ans, p[a - i]*(b - a + 2 * i + 1)+(1 - p[a - i])*(2 * b - a + 2 * i + 2));
        }
        ans = min(ans, (double) (b) + 2);
        printf("Case #%d: %.10lf\n", cas, ans);
    }
}