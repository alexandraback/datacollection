#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <stack>
#include <bitset>
#define INF 0x3f3f3f3f
#define eps 1e-8
#define FI first
#define SE second
using namespace std;
typedef long long ll;
#define C_UE 10
#define V2V_UE 10
#define maxn 10000000
#define mod 1000000007
stack<int>s;
vector<int>g[maxn];
int dfn[maxn];
int low[maxn];
bool instack[maxn];

int con[maxn];
int tot;
int all;
void tarjan(int x)
{
    s.push(x);
    instack[x]=1;
    low[x]=dfn[x]=tot++;
    for(int i=0;i<g[x].size();i++)
    {
        int j=g[x][i];
        if(dfn[j]==0)
        {
            tarjan(j);
            if(low[j]<low[x])   low[x]=low[j];
        }
        else if(instack[j]&&low[j]<low[x])
        {
            low[x]=low[j];
        }
    }
    if(low[x]==dfn[x])
    {
        int j;
        all++;
        do
        {
            j=s.top();
            s.pop();
            instack[j]=0;
            con[j]=all;
        }while(x!=j);
    }
}

vector<int>fin[maxn];
int main()
{
    freopen("C-small-attempt0.txt", "r", stdin);;
    freopen("C-small-attempt0.out", "w", stdout);
    int t;
    scanf("%d",&t);
    for(int cas=1; cas<=t;cas++)
    {
        memset(dfn,0,sizeof(dfn));
        memset(low,0,sizeof(low));
        memset(instack,0,sizeof(instack));
        memset(con,0,sizeof(con));
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            g[i].push_back(x);
        }
        for(int i=1;i<=n;i++)
        {
            if(dfn[i]==0)
            {
                tarjan(i);
            }
        }
        for(int i=1;i<=n;i++) fin[con[i]].push_back(i);
        int ans=2;
        for(int i=1;i<=all;i++)
        {
            if(fin[i].size()==1) continue;
            if(fin[i].size()>2) ans=max(ans,fin[i]);
            else
            {
                ans=max(ans,qq[fin[i][0]);
                ans=max(ans,qq[fin[i]][1]);
            }
        }
    }
    return 0;
}
