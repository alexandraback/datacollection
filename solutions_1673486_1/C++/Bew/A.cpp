#include<stdio.h>
#include<stdlib.h>
int T;
int A,B;
double p[100111];
double ans;
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int i,j,k;
    int q,r,t,tt,ttt;
    double d,dd,ddd;
    scanf("%d",&T);
    for(int ii=0;ii<T;ii++)
     {
       scanf("%d %d",&A,&B);
       for(i=1;i<=A;i++)
        {
          scanf("%lf",&p[i]);
        }
       ans=1+B+1;
       d=1;
       for(i=1;i<=A;i++)
        {
          d*=p[i];
          dd=d*(B-i+1+(A-i));
          dd+=(1-d)*(B-i+1+(A-i)+B+1);
          if(dd<ans)ans=dd;
        }
       printf("Case #%d: %lf",ii+1,ans);
       if(ii<T-1)printf("\n");
     }
    
    
    scanf(" ");
    return 0;
}
