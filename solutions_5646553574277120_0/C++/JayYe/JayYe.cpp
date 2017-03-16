#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int ans;
bool vis[33], dp[33];

int c, d, v;

void dfs(int dep) {
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = 1;i <= v; i++) if(vis[i]){
        for(int j = v;j >= i; j--) {
            if(dp[j-i]) dp[j] = 1;
        }
    }
    bool flag = true;
    for(int i = 1;i <= v; i++) if(!dp[i]) {
        flag = false;
        break;
    }
    if(flag) {
        ans = min(ans, dep);
    }
    if(ans <= dep)  return ;
    if(dep == 4) return ;
    for(int i = 1;i <= 30; i++) if(!vis[i]) {
        vis[i] = 1;
        dfs(dep+1);
        vis[i] = 0;
    }
}

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    int t,cas = 1;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &c, &d, &v);
        memset(vis, 0, sizeof(vis));
        int x;
        for(int i = 0;i < d; i++) {
            scanf("%d", &x);
            vis[x] = 1;
        }
        ans = 5;
        dfs(0);
        printf("Case #%d: %d\n", cas++, ans);
    }
    return 0;
}
