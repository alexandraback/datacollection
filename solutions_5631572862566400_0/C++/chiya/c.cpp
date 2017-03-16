#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<cmath>
#include<bitset>
#define rep(i,a,b) for(int i=a,_b=b;i<=_b;i++)
#define per(i,a,b) for(int i=a,_b=b;i>=_b;i--)
#define For(i,b) for(int i=0,_b=b;i<_b;i++)
#define upmax(a,b) if ((a)<(b)) (a)=(b)
#define upmin(a,b) if ((a)>(b)) (a)=(b)
using namespace std;

int T,n,a1,a2,fa[1200],vis[1200],dep[1200],mdep[1200],ask[1200];
vector<int> e[1200];

void dfs(int u){
    vis[u]=ask[u]=1;
    mdep[u]=dep[u];
    For(i,e[u].size()){
        int v=e[u][i];
        if (!vis[v]){
            dep[v]=dep[u]+1;
            dfs(v);
            upmax(mdep[u],mdep[v]);
        }
        else upmax(a1,dep[u]);
    }
}

void check(int u){
    int x1=0;
    int x2=0;
    For(i,e[u].size()){
        int v=e[u][i];
        if (fa[u]==v) x1=mdep[v]-1;
        else {upmax(x2,mdep[v]);}
    }
    a2+=(x1+x2);
}

int ringg(int u,int uu){
    ask[u]=1;
    For(i,e[u].size()){
        int v=e[u][i];
        if (v==uu) return 1;
        if (ringg(v,uu)) return 1;
    }
    return 0;
}

int main(){
//freopen("C.in","r",stdin);
//freopen("C.out","w",stdout);
    cin>>T;
    rep(ca,1,T){
        cin>>n;
        a1=a2=0;
        rep(i,1,n) e[i].clear();
        rep(i,1,n){
            cin>>fa[i];
            e[fa[i]].push_back(i);
            vis[i]=ask[i]=dep[i]=0;
        }
        rep(i,1,n) if (!ask[i]){
            if (!ringg(i,i)) continue;
            dep[i]=1;
            dfs(i);
            if (fa[fa[i]]==i) check(i);
        }
        cout<<"Case #"<<ca<<": "<<max(a1,a2)<<endl;
        //cout<<a1<<' '<<a2<<endl;
        
    }
}