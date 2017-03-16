#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
int a[55][55];
ll b[55], m;


void solve() {
    memset(a, 0, sizeof(a));
    if((1ll<<n-2) < m) {
        puts(" IMPOSSIBLE");
        return ;
    }
    puts(" POSSIBLE");
    for(int i = 1;i < n; i++) {
        for(int j = i+1;j < n; j++)
            a[i][j] = 1;
    }
    for(int i = 2;i <= n; i++) b[i] = 1ll<<i-2;
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
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int t, cas = 0;
    scanf("%d" ,&t);
    while(t--) {
        scanf("%d%I64d", &n, &m);
        printf("Case #%d:", ++cas);
        solve();
    }
    return 0;
}
