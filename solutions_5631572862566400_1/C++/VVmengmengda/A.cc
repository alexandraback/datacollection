#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int a[1005], num[1005];
bool fg[1005], vis[1005];
vector<int> vv[1005];
int ans;

void ok(int len){
    if(len==1) return;
    for(int i=2;i<len;i++){
        if(a[num[i]]!=num[i-1] && a[num[i]]!=num[i+1]) return;
    }
    if(a[num[1]]!=num[2] && a[num[1]]!=num[len]) return;
    if(a[num[len]]!=num[1] && a[num[len]]!=num[len-1]) return;
    ans=max(len, ans);
}

void dfs(int u, int dep){
    vis[u]=1;
    num[dep]=u;
    if(!vis[a[u]]){
        dfs(a[u], dep+1);
    }
    for(int i=0;i<vv[u].size();i++){
        int v=vv[u][i];
        if(!vis[v]){
            dfs(v, dep+1);
        }
    }
    ok(dep);
    return;
}

int main(){
    freopen("C-small-attempt1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    int t,n,i,cas=1;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(i=1;i<=n;i++) vv[i].clear();
        for(i=1;i<=n;i++){
            scanf("%d", &a[i]);
            vv[a[i]].push_back(i);
        }
        ans=2;
        for(i=1;i<=n;i++){
            memset(vis, 0, sizeof(vis));
            dfs(i, 1);
        }
        printf("Case #%d: %d\n", cas++, ans);
    }
    return 0;
}
