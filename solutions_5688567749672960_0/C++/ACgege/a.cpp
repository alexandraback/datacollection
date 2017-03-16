#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#define eps 1e-8
#define db double
#define rt return
#define cn const
#define op operator
#define N 1000009
using namespace std;
#define LL long long

LL dp[N];

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("a.out","w",stdout);
    int T;
    scanf("%d",&T);

    for(int ca=1;ca<=T;ca++)
    {
        LL n;
        scanf("%lld",&n);

        for(int i=0;i<=n;i++) dp[i]=i;

        for(int i=12;i<=n;i++)
        {
             LL m=0,a=i;
            while(a)
            {
                m=m*10 + a%10;
                a/=10;
            }

            dp[i+1] = min(dp[i+1],dp[i]+1);
            if(m<=n)
            dp[m] = min(dp[m],dp[i]+1);
        }

        printf("Case #%d: %lld\n",ca,dp[n]);


    }
    return 0;
}
