#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<iostream>
using namespace std;
const int maxn=1000+5;
map<string,int>MA,MB;
struct Max_Match
{
    int n,m;
    vector<int> g[maxn];
    bool vis[maxn];
    int left[maxn];

    void init(int n,int m)
    {
        this->n=n;
        this->m=m;
        memset(left,-1,sizeof(left));
    }

    bool match(int u)
    {
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i];
            if(!vis[v])
            {
                vis[v]=true;
                if(left[v]==-1 || match(left[v]))
                {
                    left[v]=u;
                    return true;
                }
            }
        }
        return false;
    }

    int solve()
    {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            memset(vis,0,sizeof(vis));
            if(match(i)) ++ans;
        }
        return ans;
    }
}MM;

int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int n,m,cas=0;
    int T;
    cin>>T;
    while(T--)
    {
        MA.clear();
        MB.clear();
        n=m=0;
        int c;
        scanf("%d",&c);
        for (int i=0;i<c;i++) {
            string a,b;
            cin>>a>>b;
            if (!MA.count(a)) {MA[a]=++n;MM.g[n].clear();}
            if (!MB.count(b)) MB[b]=++m;
            MM.g[MA[a]].push_back(MB[b]);
        }
        MM.init(n,m);
        printf("Case #%d: %d\n",++cas, c-(n+m-MM.solve()));
    }
    return 0;
}
