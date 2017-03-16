#include <cstdio>
#include <cstring>
#include <iostream>
#define eps (1e-12)
using namespace std;
int a[205]={0},S;
int main()
{int T,n,m,i,j,k,l,tt=0;
 freopen("A.in","r",stdin);
 freopen("A.out","w",stdout);
 scanf("%d",&T);
 while(T--)
 {scanf("%d",&n);
  tt++;
  S=0;
  for(i=1;i<=n;i++)
  {scanf("%d",&a[i]);
   S+=a[i];
  }
  printf("Case #%d:",tt);
  for(i=1;i<=n;i++)
  {long double L,R,point;
   L=0;R=1;
   do
   {long double mid=(L+R)/2;
    point=a[i]+mid*S;
    long double s1=mid;
    for(j=1;j<=n;j++)
     if(j!=i)
     {if(a[j]<point)s1+=(point-a[j])/S;}
    if(s1<1-eps)L=mid;
    else R=mid;
   }while(L+eps<R);
   double ans=L;
   printf(" %.8lf",ans*100);
  }
  printf("\n");
 }
 return 0;
}
  
