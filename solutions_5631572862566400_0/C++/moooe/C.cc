#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int dp[1005], f[1005];
bool vis[1005];
vector<int> vi[1005];

int Cas;
int d1(int p) {
    memset(vis,0,sizeof(vis));
    int ans = 0, t1, t2;
    dp[p] = 1;
    vis[p] = 1;
    t2 = p;
    t1 = f[p];
    while(!vis[t1]) {
        vis[t1] = 1;
        dp[t1] = dp[t2] + 1;
        t2 = t1;
        t1 = f[t1];
    }
    ans = dp[t2] - dp[t1] + 1;
    return ans;
}
int d2(int p) {
    int ans = 1, tmp;
    for(int i = 0; i < vi[p].size(); i++) {
        tmp = vi[p][i];
        if(!vis[tmp]) {
            vis[tmp] = 1;
            ans = max(ans, d2(tmp) + 1);
        }
    }
    return ans;
}
int main() {
    freopen("t.in", "r", stdin);
    freopen("t.out", "w", stdout);
    // printf("%d ",++Cas);
    int T, n, a1, a2, a3;
    scanf("%d", &T);
    while(T--) {
        printf("Case #%d: ", ++Cas);
        scanf("%d", &n);
        memset(vis, 0, sizeof(vis));
        memset(dp,0,sizeof(dp));
        a1 = a2 = 0;
        for(int i = 0; i <= n; i++)
            vi[i].clear();
        for(int i = 1; i <= n; i++) {
            scanf("%d", &f[i]);
            vi[f[i]].push_back(i);
        }
        for(int i = 1; i <= n; i++) {
            if(!vis[i])
                a1 = max(a1, d1(i));
        }
        memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= n; i++) {
            if(f[f[i]] == i && !vis[i] && !vis[f[i]]) {
                vis[i] = vis[f[i]] = 1;
                a2 = a2 + d2(i) + d2(f[i]);
            }
        }//cout<<a1<<" "<<a2<<endl;
        printf("%d", max(a1, a2));
        puts("");
    }

    return 0;
}
