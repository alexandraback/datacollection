#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 10005;
int f[N],cir[N];
int res,n;
bool vis[N];
void init(){
    memset(vis,0,sizeof(vis));
    res = 0;
}
void dfs(int dep = 0){
    if(dep >= 2 && dep > res){
        int tc = 0;
        for(int i = 0 ; i < dep ; i ++){
            int u = cir[i];
            if((f[u] == cir[(i + dep - 1) % dep]) || (f[u] == cir[(i + 1) % dep]))
                tc ++;
        }
        if(tc == dep) res = dep;
    }
    if(dep >= 3){
        int tc = 0;
        for(int i = 1 ; i < dep - 1 ; i ++){
            int u = cir[i];
            if((f[u] == cir[(i + dep - 1) % dep]) || (f[u] == cir[(i + 1) % dep]))
                tc ++;
        }
        if(tc < dep - 2) return;
    }
    for(int i = 1 ; i <= n ; i ++){
        if(vis[i]) continue;
        vis[i] = 1;
        cir[dep] = i;
        dfs(dep + 1);
        vis[i] = 0;
    }
}
void solve(){
    init();
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i ++){
        scanf("%d",&f[i]);
    }
    dfs();
    printf("%d\n",res);
}
int main(){
    freopen("C-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int _,txt = 1;
    scanf("%d",&_);
    _ = 10;
    while(_--){
        printf("Case #%d: ",txt ++);
        solve();
    }
    return 0;
}
