#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=1010;
vector <int> g[N];
vector <int> ans;
bool used[N];
bool f=false;
void dfs(int v)
{
    used[v]=true;
    for(int i=0;i<g[v].size();i++)
        if (!used[g[v][i]])
            dfs(g[v][i]);
    ans.push_back(v);
}
ll dp[N];
void df(int v)
{
    used[v]=true;
    if (dp[v]>=2)
        f=true;
    for(int i=0;i<g[v].size();i++)
        dp[g[v][i]]+=dp[v];
    for(int i=0;i<g[v].size();i++)
        if (!used[g[v][i]])
            df(g[v][i]);
        else if (dp[g[v][i]]>=2)
            f=true;
}
int main()
{
    freopen("A-small-attempt2.in","r",stdin);
    freopen("answer.txt","w",stdout);
    int t,n;
    scanf("%d",&t);
    for(int q=1;q<=t;q++)
    {
        scanf("%d",&n);
        int m;
        f=false;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&m);
            g[i].clear();
            int x;
            for(int j=0;j<m;j++)
            {
                scanf("%d",&x);
                g[i].push_back(--x);
            }
            used[i]=false;
            dp[i]=0;
        }
        ans.clear();
        for(int i=0;i<n;i++)
            if (!used[i])
                dfs(i);
        reverse(ans.begin(),ans.end());
        for(int i=0;i<n && !f;i++)
        {
            memset(used,false,n);
            memset(dp,0,n*8);
            dp[ans[i]]=1;
            df(ans[i]);
        }
        printf("Case #%d: ",q);
        if (f)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
