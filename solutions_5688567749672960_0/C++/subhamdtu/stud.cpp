#include<bits/stdc++.h>
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define p(n) printf("%d\n",n)
#define ll long long
#define pb push_back
#define mp make_pair

#define LN 21
ll mod=1000000007;
using namespace std;

ll rever(ll num)
{
    int tmp[15];
    int dig = 0;
    while(num>0)
    {
      tmp[dig++]=num%10;
      num=num/10;
    }
    ll ans=0;
    for(int i=0;i<dig;++i)
    ans=ans*10+tmp[i];

    return ans;
}
ll countdig(ll va)
{
int dig = 0;
while(va>0)
{
    va/=10;
    dig++;
}
return dig;
}
int main()
{

   int t,i,p,j;
   ll n ;
   cin>>t;

   for(p = 1 ;p<=t;++p)
   {
    cin>>n;
    printf("Case #%d: ",p);
    ll ans = 0;
     ll dp[n+1];
     dp[0]= 0;
     for(i = 1;i<=n;++i)
     {
        if(i<=9)
            dp[i] = i;
        else
        {
            dp[i] = dp[i-1]+1;
            ll  va = rever(i);
            if(va<i && (countdig(va)==countdig(i)))
                dp[i] = min(dp[i],dp[va]+1);
         }
     }
     ans = dp[n];
         cout<<ans<<endl;
    }



    return 0;
}
