#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[1002][1003];
vector<int>pre[1002];
vector<int>nxt[1002];
int main()
{
    freopen("as.in","r",stdin);
    freopen("as.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int c=1; c<=T; c++)
    {
        printf("Case #%d: ",c);
        int n;
        memset(dp,0,sizeof(dp));
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            pre[i].clear();
            nxt[i].clear();
        }
        int t;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&t);
            int d;
            for(int j=0; j<t; j++)
            {
                scanf("%d",&d);
                d--;
                dp[i][d]=1;
                nxt[i].push_back(d);
                pre[d].push_back(i);
            }
        }
        for(int i=0;i<n;i++)
        {
            //printf("%d\n",i);
            for(int j=0;j<pre[i].size();j++)
            {
                for(int k=0;k<nxt[i].size();k++)
                {
                    int a=pre[i][j],b=nxt[i][k];
                    int o=dp[a][b];
                    dp[a][b]+=dp[a][i]*dp[i][b];
                    if(dp[a][b]!=0&&o==0)
                    {
                        nxt[a].push_back(b);
                        pre[b].push_back(a);
                    }
                    //printf("%d %d %d\n",a,b,dp[a][b]);
                }
            }
        }
        int f=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                //printf("%d %d %d\n",i,j,dp[i][j]);
                if(dp[i][j]>=2)
            f=1;}

        }
        if(f)printf("Yes\n");
        else printf("No\n");
    }


    return 0;
}
