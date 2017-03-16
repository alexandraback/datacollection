#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
vector <int> e[1010];
int vis[1010],ru[1010];
int n,flag;
void dfs(int u){
    int i,v;
    vis[u]=1;
    for (i=0;i<e[u].size();i++){
        v=e[u][i];
        if (!vis[v]) dfs(v);
        else flag=1;
    }
}
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int ca,cc=0;
    int i,j,k,v;
    scanf("%d",&ca);
    while (ca--){
        scanf("%d",&n);
        memset(ru,0,sizeof(ru));
        for (i=1;i<=n;i++){
            e[i].clear();
            scanf("%d",&k);
            for (j=0;j<k;j++){
                scanf("%d",&v);
                e[i].push_back(v);
                ru[v]++;
            }
        }
        flag=0;
        for (i=1;i<=n;i++){
            if (ru[i]==0){
                memset(vis,0,sizeof(vis));
                dfs(i);
            }
        }
        cc++;
        printf("Case #%d: ",cc);
        if (flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
