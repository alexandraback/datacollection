#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct PP {
    int i, j, k;
    PP(){}
    PP(int i,int j,int k):i(i),j(j),k(k){}
}vt[111];

int a, b, c, n;

bool vis[111];
int cnt[4][4][4];
int ans;
bool path[111];


void dfs(int dep, int sum, int tot) {
    if(dep == tot) {
        if(sum > ans) {
            ans = sum;
            for(int i = 0;i < dep; i++) path[i] = vis[i];
        }
        return ;
    }
    dfs(dep+1, sum, tot);
    int i = vt[dep].i, j = vt[dep].j, k = vt[dep].k;
    if(cnt[i][j][0]<n && cnt[i][0][k]<n && cnt[0][j][k]<n) {
        cnt[i][j][0]++; cnt[i][0][k]++; cnt[0][j][k]++;
        vis[dep] = 1;
        dfs(dep+1, sum+1, tot);
        cnt[i][j][0]--; cnt[i][0][k]--; cnt[0][j][k]--;
        vis[dep] = 0;
    }
}

void solve() {
    if(n >= c) {
        printf(" %d\n", a*b*c);
        for(int i = 1;i <= a; i++) {
            for(int j = 1;j <= b; j++) {
                for(int k = 1;k <= c; k++)
                    printf("%d %d %d\n", i, j, k);
            }
        }
        return ;
    }
    int tot = 0;
    for(int i = 1;i <= a; i++) {
        for(int j = 1;j <= b; j++) {
            for(int k = 1;k <= c; k++) {
                vt[tot++] = PP(i, j, k);
            }
        }
    }
    ans = 0;
    memset(cnt, 0, sizeof(cnt));
    memset(vis, 0, sizeof(vis));
    dfs(0, 0, tot);
    printf(" %d\n", ans);
    for(int i = 0;i < tot; i++) if(path[i]) {
        printf("%d %d %d\n", vt[i].i, vt[i].j, vt[i].k);
    }
}

int main() {
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
    int t, cas = 0;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d%d", &a, &b, &c, &n);
        printf("Case #%d:", ++cas);
        solve();
    }
    return 0;
}
