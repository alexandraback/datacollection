#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int rev(int x) {
    int t = 0;
    while (x) {
        t = t * 10 + x % 10;
        x /= 10;
    }
    return t;
}
long long g(long long x) {
    char c[20];
    sprintf(c, "%lld", x);
    int n = strlen(c);
    long long t = 1, r = 0;
    for (int i = 0; i <= n - 1 - i; i++) {
        if (i == n - 1 - i) {
            r += t * (c[i] - '0');
        } else {
            r += t * (c[i] - '0' + c[n - 1 - i] - '0');
            t *= 10;
        }
    }
    return r;
}
int main(){
    int T, ri = 1;
    long long x, t, ans;
    freopen("A-large (1).in", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &T);
    while (T--) {
        scanf("%lld", &x);
        printf("Case #%d: ", ri++);
        ans = 0;
        if (x < 10) {
            printf("%lld\n", x);
            continue;
        }
        t = 10;
        ans = 10;
        while (1) {
            if (t * 10 <= x) {
                t *= 10;
                ans += g(t - 1) + 1;
                continue;
            }
            if (x == t) break;
            if (x % 10 == 0) {
                long long r = min(x - t, g(x - 1) + 2);
                r = min(r, g(rev(x - 1)) + 1);
                char c[20];
                sprintf(c, "%lld", x);
                int n = strlen(c);
                long long a[20], t = 1;
                a[0] = 0;
                for (int i = 0; i < n; i++) {
                    a[i + 1] = a[i] + (c[i] - '0') * t;
                    t *= 10;
                }
                t = 1;
                long long v = 0;
                for (int i = n - 1; i >= 0; i--) {
                    v += (c[i] - '0') * t;
                    t *= 10;
                    if (v) {
                        r = min(r, v + a[i] + 1);
                    }
                }
                ans += r;
            } else {
                ans += min(min(x - t, g(x) + 1), g(rev(x)));
            }
            break;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
