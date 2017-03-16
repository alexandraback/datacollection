#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<cmath>
#include<queue>
#include<set>
#define PII pair<int,int>
#define f first
#define s second
#define VI vector<int>
#define LL long long
#define MP make_pair
#define LD long double
#define PB push_back
#define ALL(V) V.begin(),V.end()
#define abs(x) max((x),-(x))
#define PDD pair<LD,LD> 
#define VPII vector< PII > 
#define siz(V) ((int)V.size())
#define FOR(x, b, e)  for(int x=b;x<=(e);x++)
#define FORD(x, b, e) for(int x=b;x>=(e);x--)
#define REP(x, n)     for(int x=0;x<(n);x++)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
using namespace std;
#define int LL
int n,a,b,c;
int dp[1000004];
int odwroc(int x)
  {
  int ret=0;
  while(x)
    {
    ret=ret*10+x%10;
    x/=10;
    }
  return ret;
  }
void solve()
  {
  scanf("%lld",&n);
  FOR(i,1,n)dp[i]=1e9;
  FOR(i,0,n)
    {
    mini(dp[i+1],dp[i]+1);
    mini(dp[odwroc(i)],dp[i]+1);
    }
  printf("%d\n",dp[n]);
  }
main()
{
int z;
scanf("%lld",&z);
FOR(iii,1,z)
  {
  printf("Case #%lld: ",iii);
  solve();
  }
}
