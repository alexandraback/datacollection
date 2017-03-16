#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int n,t,a,ans,vis[1111],bff[1111],ss;
vector<vector<int> > adj;
void dfs(int pre,int ind,int cc){
vis[ind]=1;
int ok =0;
int u=bff[ind];
if(u==ss){ans=max(ans,cc);}
if(!vis[u]){
        ok=1;
    dfs(ind,u,cc+1);
}
if(pre==bff[ind]){
        ans=max(ans,cc);
 for(int i=0;i<adj[ind].size();i++){
        int v=adj[ind][i];
        if(v==ss){ans=max(ans,cc);}

        if(!vis[v]){
                ok=1;
            dfs(ind,v,cc+1);
        }
    }

}

}
void dfs2(int ind,int cc){
vis[ind]=1;
int ok =0;
int u=bff[ind];
if(u==ss){ans=max(ans,cc);}
 for(int i=0;i<adj[ind].size();i++){
        int v=adj[ind][i];
        if(!vis[v]){
                ok=1;
            dfs2(v,cc+1);
        }
    }

}


int main()
{
  // freopen("in.txt","r",stdin);
     // freopen("out.txt","w",stdout);
scanf("%d",&t );
for(int tt=1;tt<=t;tt++){
        scanf("%d",&n);
adj.clear();
adj.resize(1111);
ans=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        bff[i]=a;
      adj[a].push_back(i);
    }
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
            ss=i;
     vis[i]=1;
     dfs(-1,i,1);
        memset(vis,0,sizeof(vis));
dfs2(i,1);
    }
    printf("Case #%d: %d\n",tt,ans);
}    return 0;
}
