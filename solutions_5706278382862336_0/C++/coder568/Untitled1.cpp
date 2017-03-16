#include<stdio.h>
#include<stdlib.h>
long long int ar[100];
double ar1[100];
int main()
{
    long long int i,j,l,t,p,q;
    double m,n,a,b,k;
    ar[0]=1;
    for(i=1;i<40;i++)
    ar[i]=ar[i-1]*2;
    for(i=0;i<40;i++)
    {
       n=ar[i];
       ar1[i]=(1/n);
    }
    scanf("%lld",&t);
    //printf("a");
    for(j=0;j<t;j++)
    {
                    scanf("%lld/%lld",&p,&q);
                    l=0;
                    for(i=0;i<40;i++)
                    {
                        if(ar[i]==q)
                        l=1;
                    }
                   // printf("b");
                    if(p%2==0||l==0)
                    printf("Case #%lld: impossible\n",j+1);
                    else
                    {
                    	a=p;
                    	b=q;
                      k=a/b;
                      //printf("%lf\n",k);
                      for(i=0;i<40;i++)
                      {
                                       if(ar1[i+1]<=k&&ar[i]>k)
                                       {
                                                               printf("Case #%lld: %lld\n",j+1,i+1);
                                                               break;
                                       }
                      }
                    }
    }
    return(0);
}  
