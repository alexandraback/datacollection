#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
#define mp make_pair
#define pb push_back
#define MOD 1000000007

int main() {
    int n, T, TC = 1, m, i;
    double ans, pp, p;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        ans = n + m + 1; pp = 1;
        for (i=0; i<n; i++) {
            scanf("%lf", &p);
            pp *= p;
            //printf("%lf\n", ans);
            ans = min(ans, pp*((n-1-i) + (m - i)) + (1-pp)*((n-1-i) + (m - i) + m + 1));
            //printf("%lf\n", pp*((n-1-i) + (m - i)) + (1-pp)*((n-1-i) + (m - i) + m + 1));
        }
        if (n != m) {
            ans = min(m + 2.0, ans);
        }
        printf("Case #%d: %.6lf\n", TC++, ans);
    }
}
