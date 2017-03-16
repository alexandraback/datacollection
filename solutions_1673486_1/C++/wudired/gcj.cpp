#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
double p[100000];
void checkmin(double &a,double b)
{
     if (a>b)
     a=b;
}
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A.out","w",stdout);
    int cs,i,j,k,n,m,q=0;
    double ans;
    scanf("%d",&cs);
    while (cs--)
    {

          scanf("%d%d",&n,&m);ans=n+m+1;
          checkmin(ans,m+2);
          for (i = 1;i<=n;i++)
          scanf("%lf",&p[i]);
          double t1=1;
          for (i=1;i<=n;i++)
          {
              t1*=p[i];
              checkmin(ans,n-i+m-i+1+(1-t1)*(m+1));
          }
          printf("Case #%d: %.7f\n",++q,ans);

    }
}
