#include <iostream>
#include <cstdio>

using namespace std;

double P[200005]={0};

int main()
{
 long n,m,t;
 long i,j,k;
 
 freopen("a.in","r",stdin);
 freopen("a.out","w",stdout);
 
 scanf("%ld",&t);
 for(i=1;i<=t;i++)
   {
    double ans;
    
    printf("Case #%ld: ",i);
    scanf("%ld%ld",&n,&m);
    
    ans=m+2;
    
    P[0]=1;
    for(j=1;j<=n;j++)
      {
       double a;
       scanf("%lf",&a);
       P[j]=P[j-1]*a;
      }
    for(j=0;j<=n;j++)
      {
       if(P[n-j]*(m-n+2*j+1)+(1-P[n-j])*(m-n+2*j+1+m+1)<ans)
        ans=P[n-j]*(m-n+2*j+1)+(1-P[n-j])*(m-n+2*j+1+m+1);
      }
    printf("%lf\n",ans);
   }
 
 return 0;
}
