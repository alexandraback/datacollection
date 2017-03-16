#include <bits/stdc++.h>

using namespace std;

int n, m, a[11][11], b[11];

void solve() {
    memset(a, 0, sizeof(a));
    if((1<<n-2) < m) {
        puts(" IMPOSSIBLE");
        return ;
    }
    puts(" POSSIBLE");
    for(int i = 1;i < n; i++) {
        for(int j = i+1;j < n; j++)
            a[i][j] = 1;
    }
    for(int i = 2;i <= n; i++) b[i] = 1<<i-2;
    b[1] = 1;
    for(int i = n-1;i >= 1; i--) if(m >= b[i]) {
        a[i][n] = 1;
        m -= b[i];
    }
    for(int i = 1;i <= n; i++) {
        for(int j = 1;j <= n; j++) printf("%d", a[i][j]); puts("");
    }
}

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int t, cas = 0;
    scanf("%d" ,&t);
    while(t--) {
        scanf("%d%d", &n, &m);
        printf("Case #%d:", ++cas);
        solve();
    }
    return 0;
}
