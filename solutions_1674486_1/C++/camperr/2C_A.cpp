#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<iostream>
using namespace std;
bool vis[1007];
vector<int> cn[1007];
bool yes;
int n;
void dfs(int u){
    if(vis[u]) {
        yes=true;
        return;
    }
    vis[u]=true;
    int si=cn[u].size();
    for(int i=0;i<si;i++){
        if(!yes) dfs(cn[u][i]);
    }
}
int main(){
    int t,i,j,k,x,s;
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    //freopen("in.txt","r",stdin);
    scanf("%d",&t);
    for(j=0;j<t;j++){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&s);
            for(k=0;k<s;k++){
                scanf("%d",&x);
                cn[i].push_back(x-1);
            }
        }
        yes=false;
        for(i=0;i<n;i++){
            memset(vis,0,sizeof(vis));
            dfs(i);
            if(yes) break;
        }
        if(yes) printf("Case #%d: Yes\n",j+1);
        else printf("Case #%d: No\n",j+1);
        for(i=0;i<n;i++) cn[i].clear();
    }
}
