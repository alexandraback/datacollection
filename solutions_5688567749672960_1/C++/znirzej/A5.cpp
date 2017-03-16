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
LL n,m,a,b,c,d;
char ch;/*
int odwroc(int x)
  {
  int ret=0;
  while(x)
    {
    ret=ret*10+x%10;
    x/=10;
    }
  if(ret>n)return 0;
  return ret;
  }*/
LL odwroc2(LL x)
  {
  if(x%10==0)return 1e15;
  LL ret=0;
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
  LL res=1;
  while(n)
    {
//    cerr<<n<<endl;
    int dalej=0;
    FOR(i,1,sqrt(n))
      {
      if(i<=n&&odwroc2(n-i)+i<odwroc2(n-dalej)+dalej-1)dalej=i;
      }
    if(odwroc2(n)>=n||dalej)
      {
      maxi(dalej,1LL);
      res+=dalej;
      n-=dalej;
      continue;
      }
    res++;
//    cerr<<"skok "<<n<<" "<<odwroc2(n)<<endl;
    n=odwroc2(n);
    }
  printf("%lld\n",res-1);
    
  }
main()
{
LL z;
scanf("%lld",&z);
FOR(iii,1,z)
  {
  printf("Case #%lld: ",iii);
  solve();
  }
}
