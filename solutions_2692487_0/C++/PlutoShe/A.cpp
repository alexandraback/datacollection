#include <iostream>
#include <cstdio>
#include <cstring>
#include <string.h>
#include <algorithm>
#include <cstdlib>
using namespace std;

typedef long long LL;
long long f[200][30][200];
int a[200];

int max(int a, int b) {
    return (a > b ? a : b);
}


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int test, tt, m, n;
    scanf("%d", &test);
    for (int tt = 1; tt <= test; tt++) {
        scanf("%d%d", &m, &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);

        }
        sort(a + 1, a + 1 + n);
        int ans = n;
        for (int k = 0; k <= n; k++) {
            int now = 0, w = m;
            for (int i = 1; i <= n - k; i++) {
                while  (a[i] >= w) {
                    w = w * 2  - 1;
                    now++;
                    if (now > n) break;
                }
                if (w > a[i]) { w += a[i];} else break;
            }
            if (now  + k < ans) ans = now + k;
        }
        printf("Case #%d: %d\n", tt, ans);
    }
    return 0;
}
