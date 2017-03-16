#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define p(x) cout<<#x<<":"<<x<<"\n"
#define ll long long

ll cs,c,r,t;

ll bs(ll i,ll j)
{
  ll k;

  if(i==j)
    return i;
  k=(i+j+1)/2;
  if(2*r+1+2*(k-1)<=t/k)
    return bs(k,j);
  return bs(i,k-1);
}
int main()
{
  scanf("%lld",&cs);
  for(c=1;c<=cs;c++)
  {
    scanf("%lld%lld",&r,&t);
    printf("Case #%lld: %lld\n",c,bs(1,500000000000000000ll));
  }
  return 0;
}
