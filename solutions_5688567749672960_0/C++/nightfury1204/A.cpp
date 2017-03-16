//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<set>
#include <iostream>
#include<stack>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#define N 1000000
#define sn scanf
#define pf printf
#define pb push_back

typedef long long int ll;
using namespace std;
struct T{
int a;
};
ll bigmod(ll a,ll b,ll mod)
{
    if(b==0)return 1;
    if(b%2==0)
    {
        ll hh=bigmod(a,b/2,mod);
        return (hh*hh)%mod;
    }
    else
    {
       return (a*bigmod(a,b-1,mod))%mod;
    }
}
int dp[1000005];
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
  #ifdef O_judge
    freopen("A.in","r",stdin);
    freopen("out.txt","w",stdout);
  #endif
      sn("%d",&t);
      for(i=1;i<=1000000;i++)
        dp[i]=i;
      for(i=1;i<=1000000;i++)
      {
          u=0;a=i;
          while(a>0)
          {
              u=u*10+a%10;
              a/=10;
          }
          dp[u]=min(dp[u],dp[i]+1);
          dp[i+1]=min(dp[i+1],dp[i]+1);
      }
      while(t--)
      {
          sn("%d",&n);
          pf("Case #%d: %d\n",cs++,dp[n]);
      }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/
