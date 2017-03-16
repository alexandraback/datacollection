#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define p(x) cout<<#x<<":"<<x<<"\n"

int cs,c,a,b,i;
double mn,p;
double A[100001];

int main()
{
  scanf("%d",&cs);
  for(c=1;c<=cs;c++)
  {
    scanf("%d%d",&a,&b);
    for(i=0;i<a;i++)
      scanf("%lf",&A[i]);
    for(i=0,p=1,mn=b+2;i<=a;p*=A[i++])
      mn=min(mn,p*(a-2*i+b+1)+(1-p)*(a-2*i+2*b+2));
    printf("Case #%d: %.10lf\n",c,mn);
  }
  return 0;
}
