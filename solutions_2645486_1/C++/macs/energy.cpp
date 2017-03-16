#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
using namespace std;
#define p(x) cout<<#x<<":"<<x<<"\n"
#define lim 10001
#define ll long long

ll cs,c,e,r,n,i,j,f,res,a,s,mx;
ll A[lim],b[2*lim],R[lim];

int main()
{
  scanf("%lld",&cs);
  for(c=1;c<=cs;c++)
  {
    scanf("%lld%lld%lld",&e,&r,&n);
    r=min(r,e);
    for(i=1;i<=n;i++)
      scanf("%lld",&A[i]);
    for(j=0,b[0]=e;j<n;j++)
    {
      if(j)
        b[j]=b[j-1]+r;
      b[n+j]=b[j]+r-e;
    }
    memcpy(R,b,n*sizeof(ll));
    R[n]=e+n*r;
    sort(b,b+2*n);
    for(i=f=res=0;i<2*n;i++)
    {
      if(i)
        a=b[i-1]+1;
      else
        a=1;
      if(a>b[i])
        continue;
      if(b[i]<=e)
        s=0;
      else
        s=(b[i]-e-1)/r+1;
      while(f<n && R[f]-a+1<=e)
        f++;
      if(f<=s)
        p(i);
      for(j=s+1,mx=0;j<=f;j++)
        mx=max(mx,A[j]);
      res+=mx*(b[i]-a+1);
    }
    printf("Case #%lld: %lld\n",c,res);
  }
  return 0;
}
