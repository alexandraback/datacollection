#include<iostream>
using namespace std;
int T,i,j,e,r,n,v[100],k,dp[100][100];
int f(int i, int j)
{
    if( i == n+1)
    {
        return 0;
    }
    int &ans = dp[i][j];
    if(ans != -1)
    {
        return ans;
    }
    for( int k = 0; k <= j; k++)
    {
        ans = max( ans , k*v[i]+f(i+1, min(e,j+r-k)));
    }
    return ans;
}
int main()
{
    scanf("%d",&T);
    for( i = 1; i <= T; i++)
    {
        scanf("%d%d%d",&e,&r,&n);
        for(int p = 0; p <= 10; p++)
        {
            for(int q = 0; q <= 10; q++)
            {
                dp[p][q] = -1;
            }
        }
        for( j = 1; j <= n; j++)
        {
            scanf("%d",&v[j]);
        }
        printf("Case #%d: %d\n",i,f(1,e));
    }
}
