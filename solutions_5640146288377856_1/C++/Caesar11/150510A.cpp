#include<cstdio>
#include<cstring>
#include<algorithm>
#include<climits>
#define N 25
using namespace std;

int dp[N][2];
char mark[N][2];
int r,c,w;

void dfs(int l, int p)
{
    if (mark[l][p]) return;

    dp[l][p] = INT_MAX;
    if (p==0)
    {
        if (l<w)
        {
            dp[l][p]=0;
        }
        else
        {
            for (int i=0;i<l;i++)
            {
                int left = i;
                int right = l-i-1;
                dfs(left, 0);
                dfs(right, 0);
                dp[l][p] = min(dp[l][p],dp[left][0]+dp[right][0]+1);
            }
        }
    }
    else
    {
        if (l==w)
        {
            dp[l][p]=w;
        }
        else
        {
            dp[l][p]=INT_MAX;
            for (int i=0;i<l;i++)
            {
                int left = i;
                int right = l-i-1;
                dfs(left,0); dfs(right,0);
                int temp=0;

                if (i==0||i==l-1)
                    temp=max(temp,w);
                else
                    temp=max(temp,w+1);

                if (left>=w)
                {
                    dfs(left,1);
                    temp=max(temp,dp[left][1]+dp[right][0]+1);
                }
                if (right>=w)
                {
                    dfs(right,1);
                    temp=max(temp,dp[left][0]+dp[right][1]+1);
                }

                dp[l][p]=min(dp[l][p],temp);
            }
        }
    }
    //printf("dp[%d][%d]=%d\n",l,p,dp[l][p]);
    mark[l][p] = 1;
}
int main()
{
    int t,ys=0;

    freopen("A-large.in","r",stdin);
    freopen("dataA.out","w",stdout);
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d%d",&r,&c,&w);
        memset(mark,0,sizeof(mark));
        dfs(c,1);
        dfs(c,0);
        int ans = dp[c][1] + dp[c][0] * (r-1);
        //printf("%d %d\n",dp[2][1],dp[1][0]);
        printf("Case #%d: %d\n",++ys,ans);
    }

    return 0;
}

