#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1000 + 10;

int smax;
int a[maxn];
char str[maxn];

void solve() {
    scanf("%d", &smax);
    scanf("%s", str);
    for (int i = 0; i <= smax; ++i) {
        a[i] = (int)(str[i] - '0');
    }
    int l = 0, r = smax, ans = smax;
    while (l <= r) {
        int m = (l + r) / 2;
        int ok = 1;
        int cnt = a[0] + m;
        for (int i = 1; i <= smax; ++i) {
            if (cnt >= i) {
                cnt += a[i];
            } else {
                ok = 0;
                break;
            }
        }
        if (ok) {
            ans = min(ans, m);
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    printf("%d\n", ans);
}

int main() {
    //freopen("A.in", "r", stdin);
    //freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-large.in", "r", stdin);
    freopen("A.out", "w", stdout);

    int testCount;
    scanf("%d", &testCount);
    for (int testId = 1; testId <= testCount; ++testId) {
        printf("Case #%d: ", testId);
        solve();
    }
}
