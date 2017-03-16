#include <bits/stdc++.h>
using namespace std;
const int MAXN=10;
int T,B,M,dp[MAXN];
bool ret;
bool out[MAXN][MAXN];
vector<int> graph[MAXN];
void gen(int u)
{
    if (ret)return;
    if (u==B)
    {
        for (int i=0;i<B;i++)dp[i]=0;
        dp[0]=1;
        for (int i=0;i<B;i++)
        {
            for (int j=0;j<graph[i].size();j++)
            {
                dp[graph[i][j]]+=dp[i];
            }
        }
        if (dp[B-1]==M)
        {
            ret=true;
            for (int i=0;i<B;i++)
            {
                for (int j=0;j<graph[i].size();j++)
                {
                    out[i][graph[i][j]]=1;
                }
            }
        }
    }
    else
    {
        int poss=B-u-1;
        poss=1<<poss;
        for (int i=0;i<poss;i++)
        {
            for (int j=u+1;j<B;j++)
            {
                if (i&(1<<(j-u-1)))
                {
                    graph[u].push_back(j);
                }
            }
            gen(u+1);
            if (ret)return;
            graph[u].clear();
        }
    }
}
int main()
{
    freopen("small2.in","r",stdin);
    freopen("small2.out","w",stdout);
    scanf("%i",&T);
    for (int t=1;t<=T;t++)
    {
        scanf("%i%i",&B,&M);
        for (int i=0;i<B;i++)
        {
            graph[i].clear();
        }
        ret=false;
        memset(out,0,sizeof(out));
        gen(0);
        if (ret)
        {
            printf("Case #%i: POSSIBLE\n",t);
            for (int i=0;i<B;i++)
            {
                for (int j=0;j<B;j++)cout<<out[i][j];
                cout<<endl;
            }
        }
        else printf("Case #%i: IMPOSSIBLE\n",t);
    }
}
