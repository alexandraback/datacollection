#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int oo = 1023456789;
int a[111];
int need(int s, int m) {
    int ret = 0;
    if (m == 0)return 0;
    if (s <= 1) return oo;

    for (int i = 0; i < m; ++i) {
        while (s <= a[i]) {
            s += s - 1;
            ++ret;
        }
        s += a[i];
    }
    //printf("%d %d %d\n", s, m, ret);
    return ret;
}

void work(int cas){
    printf("Case #%d: ", cas);
    int num, n;
    scanf("%d%d", &num, &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);
    int ans = oo;
    sort(a, a + n);
    for (int k = 0; k <= n; ++k) {
        int now = n - k ;
        now += need(num, k);
        ans = min(ans, now);
    }
    printf("%d\n", ans);
}

int main() {
    freopen("a1.in", "r", stdin);
    freopen("a1.out", "w", stdout);
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; ++i)
        work(i);
    return 0;
}
