#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
int a[105][55];
int cnt[2505];
int Cas;
int main() {
    freopen("t.in", "r", stdin);
    freopen("t.out", "w", stdout);
    int t, n, k, m;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        memset(cnt, 0, sizeof(cnt));
        m = 0;
        printf("Case #%d: ", ++Cas);
        for(int i = 0; i < (2 * n - 1)*n; i++) {
            scanf("%d", &k);
            cnt[k]++;
            m = max(m, k);
        }
        for(int i = 0; i <= m; i++) {
            if(cnt[i] % 2) {
                printf("%d ", i);
            }
        }
        puts("");
    }
    return 0;
}
