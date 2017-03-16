#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int T,n,A;
double D;
double t[2011],x[2011];
int main()
{
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B-small-attempt1.out","w",stdout);
    int i,j,k;
    int p,q,r;
    double d,dd,ddd,v;
    double in;
    scanf("%d",&T);
    for(int ii=0;ii<T;ii++)
     {
       scanf("%lf",&D);
       scanf("%d %d",&n,&A);
       for(i=0;i<n;i++)
        {
          scanf("%lf %lf",&t[i],&x[i]);
        }
       printf("Case #%d:\n",ii+1);
       for(i=0;i<A;i++)
        {
          scanf("%lf",&in);
          ddd=(2*D)/in;
          d=sqrt(ddd);
          //printf(">> %lf %lf\n",d,ddd);
          /*dd=(D-x[0])/(x[1]-x[0]);
          dd*=t[1];*/
          if(n==2)
          {
          dd=(D-x[0])*t[1];
          dd/=(x[1]-x[0]);
          }
          else dd=-1;
          //printf("%lf %lf\n",d,dd);
          if(d<dd)printf("%lf",dd);
          else printf("%lf",d);
          if(i<A-1)printf("\n");
        }
       if(ii<T-1)printf("\n");
     }
    
    
    scanf(" ");
    return 0;
}

