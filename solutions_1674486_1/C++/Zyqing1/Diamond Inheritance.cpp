#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int maxn=1010;

vector<int>  maz[maxn];
int n,m;
int ru[maxn];
bool vis[maxn];

bool dfs(int u)
{
    vis[u]=true;
    int sz=maz[u].size();
    //printf("");
    for(int i=0;i<sz;i++){
        int v=maz[u][i];
        if(vis[v]) return true;
        if(dfs(v))
            return true;
    }
    return false;
}
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int t,y;
    cin>>t;
    for(int cas=1;cas<=t;cas++){
        cin>>n;
        memset(ru,0,sizeof(ru));
        for(int i=1;i<=n;i++){
           cin>>m;
           maz[i].clear();
           for(int j=0;j<m;j++){
                cin>>y;
                ru[y]++;
                maz[i].push_back(y);
           }
        }
        bool flag=true;
        for(int i=1;i<=n;i++)
            if(ru[i]==0){
                memset(vis,0,sizeof(vis));
                if(dfs(i)){
                    //printf("%d\n",i);
                    flag=false;
                    break;
                }
            }
        if(flag)
            printf("Case #%d: No\n",cas);
        else
            printf("Case #%d: Yes\n",cas);
    }
    return 0;
}
