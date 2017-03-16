#include<stdio.h>
#include<algorithm>
using namespace std;
FILE*f1=fopen("A-largexx.in","r");
FILE*f2=fopen("out.out","w");
double ar[210];
double cp[210];
int main()
{
    int i,k,a,t,n,cn;
    fscanf(f1,"%d",&t);
    double sm=0,og,z;
    for(a=0;a<t;a++)
    {
     fscanf(f1,"%d",&n); 
     cn=n;
     sm=0;
      for(i=0;i<n;i++)
      {
       fscanf(f1,"%lf",&ar[i]);
       cp[i]=ar[i];
       sm+=ar[i];
      }
      og=sm;
      sort(cp,cp+n);
      z=2*sm/cn;
      for(k=n-1;k>0&&cp[k] > z;k--)
      {
       cn--;
       sm-=cp[k];
       z=(sm+og)/cn;
      }
      printf("%d %d\n",a+1,k);
      fprintf(f2,"Case #%d:",a+1);
      for(i=0;i<n;i++)
      {
       if(ar[i] <= cp[k])
       {
        printf("cmp %lf %lf %lf\n",ar[i],cp[k],sm);        
        fprintf(f2," %lf",((z-ar[i])/og)*100);
        //fprintf(f2," %lf",(2/)(2*sm-ar[i]*cn)/(cn*sm)*100);
       }
       else
       fprintf(f2," 0.000000");
      }
       fprintf(f2,"\n");
    }
    //scanf("%*d");
}
