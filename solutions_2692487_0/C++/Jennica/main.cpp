#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int a[110], d[110], m;

int main() {
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    int T, t, i, j, n, ans;
    scanf("%d", &T);
    for (t = 1; t <= T; ++t) {
        scanf("%d%d", &m, &n);
        for (i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        sort(a + 1, a + 1 + n);
        d[0] = 0;
        ans = n;
        if (m == 1)
            goto L;
        for (i = 1; i <= n; ++i) {
            d[i] = d[i - 1];
            while (m <= a[i]) {
                m += m - 1;
                ++d[i];
            }
            m += a[i];
            if (d[i] + n - i < ans)
                ans = d[i] + n - i;
        }
L:
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}