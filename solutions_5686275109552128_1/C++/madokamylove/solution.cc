#include <cstdio>
#include <algorithm>
using namespace std;

int a[1010];

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas ++) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i ++) {
            scanf("%d", &a[i]);
        }
        int res = *max_element(a, a + n);
        for (int i = 1; i <= 1000; i ++) {
            int tot = 0;
            for (int j = 0; j < n; j ++) {
                tot += (a[j] + i - 1) / i - 1;
            }
            tot += i;
            res = min(res, tot);
        }
        printf("Case #%d: %d\n", cas, res);
        fprintf(stderr, "Case #%d: %d\n", cas, res);
    }
    return 0;
}