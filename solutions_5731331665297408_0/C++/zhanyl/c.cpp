#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn=55;

int n,m,u,v;
vector<int> end[maxn];
string s[maxn];
int in[maxn];
string ans,x;
bool vis[maxn];
int fa[maxn];
int now;
bool can[maxn];

void work(int u)
{
    if(can[u])return;
    can[u]=1;
    for(int i=end[u].size()-1;i>=0;i--)
        if(!vis[end[u][i]])work(end[u][i]);
}

bool solve(int u)
{
    for(int i=1;i<=n;i++)
        in[i]=end[i].size();
    x="";
    now=u;
    x+=s[u];
    memset(fa,-1,sizeof(fa));
    memset(vis,0,sizeof(vis));
    vis[u]=1;
    for(int num=1;num<n;num++)
    {
        //printf("%d:%d\n",num,now);
        int r=-1,ss;
        bool flag=false;
        for(int i=now;i!=-1;i=fa[i])
        {
            memset(can,0,sizeof(can));
            for(int j=fa[i];j!=-1;j=fa[j])
                work(j);
            for(int j=end[i].size()-1;j>=0;j--){
                if((!vis[end[i][j]])&&(r==-1||s[r]>s[end[i][j]]))
                {
                    ss=i;
                    r=end[i][j];
                }
                if(!vis[end[i][j]]&&!can[end[i][j]])flag=true;
            }
            if(flag)break;
        }
        if(r==-1)return false;
        vis[r]=1;
        fa[r]=ss;
        x+=s[r];
        now=r;
    }
    return true;
}

int main()
{
    freopen("C-small-attempt3.in","r",stdin);
    freopen("c-ans.txt","w",stdout);
    int t;
    cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
        ans="9";
        ans[0]++;
        for(int i=0;i<maxn;i++)
        {
            end[i].clear();
            in[i]=0;
            s[i]="";
        }
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            cin>>s[i];
        for(int i=0;i<m;i++)
        {
            cin>>u>>v;
            end[u].push_back(v);
            end[v].push_back(u);
        }
        for(int i=1;i<=n;i++)
        {
            //printf("%d\n",i);
            if(!solve(i))continue;
            if(x<ans)ans=x;
        }
        printf("Case #%d: %s\n",cas,ans.c_str());
        //if(ans.size()!=n*5)puts("WA");
    }
    return 0;
}
