#include<cstdio>
#include<algorithm>
using namespace std;
int dp[1001000];
int main()
{
    int t,n,i,j,counter,rev,temp;
    dp[1]=1;
    for(i=2;i<1001000;i++)
    {
        j=i;
        rev=0;
        while(j)
        {
            rev=10*rev+j%10;
            j/=10;
        }
        dp[i]=1+dp[i-1];
        if(rev<i&&i%10!=0)
        {
            dp[i]=min(dp[i],1+dp[rev]);
        }
    }
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        printf("Case #%d: %d\n",i,dp[n]);
    }
    return 0;
}
