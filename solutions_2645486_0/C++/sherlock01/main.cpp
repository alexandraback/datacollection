#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cstring>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<cmath>

using namespace std;
const double INF=1e9;
const double eps=1e-6;
const double PI=acos(-1.0);
const int N=105;
int dp[N][N];
int a[N];
int main()
{
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    int T;
    cin>>T;
    for(int w=1;w<=T;++w)
    {
        int E,R,n;
        cin>>E>>R>>n;
        for(int i=1;i<=n;++i)
        cin>>a[i];
        memset(dp,-1,sizeof(dp));
        dp[0][E]=0;
        for(int i=0;i<n;++i)
        for(int j=0;j<=E;++j)
        if(dp[i][j]!=-1)
        {
            for(int l=0;l<=j;++l)
            {
                int k=(j-l)+R;
                k=min(k,E);
                int v=(l*a[i+1])+dp[i][j];
                //cout<<v<<endl;
                dp[i+1][k]=max(dp[i+1][k],v);
            }
        }
        int sum=0;
        for(int j=0;j<N;++j)
        sum=max(sum,dp[n][j]);
        printf("Case #%d: %d\n",w,sum);
    }
    return 0;
}
