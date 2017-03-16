#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define p(x) cerr<<#x<<":"<<x<<"\n"
#define ll long long
ll cs,c,a,b,K;
ll M[31][2][2][2];
ll solve(ll i,ll j,ll k,ll p)
{
  if(i==-1)
    return 1;
  ll &res=M[i][j][k][p],x,y,z;
  if(res==-1)
  {
    x=a&1<<i;
    y=b&1<<i;
    z=K&1<<i;
    res=solve(i-1,j&&(!x),k&&(!y),p&&(!z));//00
    if(!k || y)
      res+=solve(i-1,j&&(!x),k,p&&(!z));//01
    if(!j || x)
      res+=solve(i-1,j,k&&(!y),p&&(!z));
    if((!j || x) && (!k || y) && (!p || z))//11
      res+=solve(i-1,j,k,p);
    //printf("%lld %lld %lld %lld %lld \n",i,j,k,p,res);
  }
  return res;
}
int main()
{
  scanf("%lld",&cs);
  for(c=1;c<=cs;c++)
  {
    scanf("%lld%lld%lld",&a,&b,&K);
    a--;
    b--;
    K--;
    memset(M,-1,sizeof M);
    printf("Case #%lld: %lld\n",c,solve(30,1,1,1));
  }
	return 0;
}
