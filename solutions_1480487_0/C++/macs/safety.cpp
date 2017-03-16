#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <numeric>
using namespace std;
#define p(x) cout<<#x<<":"<<x<<"\n"

int cs,c,i,j,k,n,s;
double ll,rr,m,z;
int S[201];

int main()
{
  scanf("%d",&cs);
  for(c=1;c<=cs;c++)
  {
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&S[i]);
    printf("Case #%d:",c);
    s=accumulate(S,S+n,0);
    for(i=0;i<n;i++)
    {
      for(ll=j=0,rr=1;j<333;j++)
      {
        m=(ll+rr)/2;
        for(z=k=0;k<n;k++)
          if(k!=i)
            z+=max((S[i]+m*s-S[k])/s,0.);
        if(z+m<1)
          ll=m;
        else
          rr=m;
      }
      printf(" %.10lf",100*ll);
    }
    printf("\n");
  }
  return 0;
}
