# include <iostream>

using namespace std;

long long n,m,i,j;
long long a[101],b[101],A[101],B[101];
long long dp[101][101];

long long func(int i,int j)
{
    if(i>=n || j>=m) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(A[i]==B[j])
    {
        int sub = min(a[i],b[j]);
        a[i] -= sub;
        b[j] -= sub;
        if(b[j]==0)
        {
            dp[i][j] =  sub+func(i,j+1);
            return dp[i][j];
        }
        else
        {
            dp[i][j] =  sub+func(i+1,j);
            return sub+func(i+1,j);
        }
    }
    else
    {
        dp[i][j] =  max(func(i+1,j),func(i,j+1));
        return dp[i][j];    
    }
}

int main()
{
    int t,cnt=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&m);
        memset(dp,-1,sizeof(dp));
        for(i=0;i<n;i++)
            scanf("%lld %lld",&a[i],&A[i]);
        for(i=0;i<m;i++)
            scanf("%lld %lld",&b[i],&B[i]);
        printf("Case #%d: %lld\n",cnt++,func(0,0));
    }    
}
