#include <iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int len,A[20],a,b,l;
typedef long long LL;
LL ans;
void trans(long long  x)
{
    len=0;
    while(x)
    {
        A[len++]=x%10;x/=10;
    }
    a=A[len-1],b=A[0];
}
LL rev(long long  x)
{
    l=0;
    int B[20];
    while(x)
    {
        B[l++]=x%10;x/=10;
    }
    LL res=0;
    for(int i=0;i<l;i++)
    {
        res*=10;
        res+=B[i];
    }
    l=0;
    int tp=res;
    while(res)
    {
        l++;
        res/=10;
    }
    return tp;
}
int dp[1000100];
int main()
{
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    int T,n;
    scanf("%d",&T);
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<=1000000;i++)
    {
        dp[i]=dp[i-1]+1;
        trans(i);
        if(rev(i)<i&&l==len)
            dp[i]=min(dp[i],dp[(int)rev(i)]+1);
    }
    for(int kase=1;kase<=T;kase++)
    {
        scanf("%d",&n);
        printf("Case #%d: %d\n",kase,dp[n]);
    }
    return 0;
}
