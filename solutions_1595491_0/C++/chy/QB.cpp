#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <utility>
#include <sstream>
#include <algorithm>
using namespace std;
#define ll long long
const long long LINF = ~(((long long)0x1)<<63)/2;
const int INF=0X3F3F3F3F;
const double eps=1e-7;
int dp[110][110];
int ok[110][2];
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int T,i,j,k,n,s,p,t,cas=1,po;
    cin>>T;
    for(cas=1;cas<=T;cas++)
    {
        scanf("%d%d%d",&n,&s,&p);
        memset(ok,-1,sizeof(ok));
        for(i=0;i<n;i++)
        {
            scanf("%d",&po);
            for(j=0;j<=10;j++)
                for(k=0;k<=10;k++)
                    if(j+k<=po)
                    {
                        int c=po-j-k;

                        if(abs(j-k)<=2&&abs(j-c)<=2&&abs(c-k)<=2)
                        {
                            if(abs(j-k)==2||abs(j-c)==2||abs(c-k)==2)
                            {
                                if(max(max(k,j),c)>=p)
                                    ok[i][0]=1;
                                else
                                    ok[i][0]=0;
                            }
                            else
                            {
                                if(max(max(k,j),c)>=p)
                                    ok[i][1]=1;
                                else
                                    ok[i][1]=0;
                            }
                        }
                    }
        }
        memset(dp,-1,sizeof(dp));
        dp[0][0]=0;
        for(i=0;i<n;i++)
            for(j=0;j<=s;j++)
                if(dp[i][j]!=-1)
                {
                    if(ok[i][0]==1)
                        dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+1);
                    if(ok[i][0]==0)
                        dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]);
                    if(ok[i][1]==1)
                        dp[i+1][j]=max(dp[i+1][j],dp[i][j]+1);
                    if(ok[i][1]==0)
                        dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
                }
        printf("Case #%d: %d\n",cas,dp[n][s]);
    }
    return 0;
}
