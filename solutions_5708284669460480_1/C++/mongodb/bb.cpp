#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define LL long long
#define MAXN 1000005

vector<int>g[MAXN];
vector<int>fin[MAXN];
int a[MAXN];
bool v[MAXN];
int e[MAXN];
int tot;
vector<int>te;
void dfs(int x)
{
    for(int i = 0;i < g[x].size(); i++)
    {
        e[tot]++;
        if(v[g[x][i]])   continue;
        fin[tot].push_back(g[x][i]);
        v[g[x][i]]=1;
        dfs(g[x][i]);
    }
}
bool cmp(int x,int y)
{
    return a[x]<a[y];
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int cas = 1;cas <= t; cas++)
    {
        int n,m,k;
        tot=0;
        scanf("%d%d%d",&n,&m,&k);
        for(int i = 1;i <= n; i++)    scanf("%d",a+i);
        for(int i = 0;i < m; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        memset(v,0,sizeof(v));
        memset(e,0,sizeof(e));
        for(int i = 1;i <= n; i++)
        {
            if(v[i])    continue;
            v[i]=1;
            fin[tot].push_back(i);
            dfs(i);
            tot++;
        }
        for(int i=0;i<tot;i++)  sort(fin[i].begin(),fin[i].end(),cmp);
        int temp=0;
        long long all=0;
        for(int i=0;i<tot;i++)
        {
            temp+=e[i]/2-(fin[i].size()-1);
            all+=a[fin[i][0]];
        }
        if(temp>=k) printf("Case #%d: %lld\n",cas,all);
        else
        {
            for(int i=0;i<tot;i++)  for(int j=1;j<fin[i].size();j++)  te.push_back(fin[i][j]);
            sort(te.begin(),te.end(),cmp);
            for(int i=0;i<k-temp;i++)   all+=a[te[i]];
            printf("Case #%d: %lld\n",cas,all);
        }
        te.clear();
        for(int i=0;i<tot;i++)  fin[i].clear();
        for(int i=1;i<=n;i++)   g[i].clear();
    }
}
