#include<stdio.h>
#include<stdlib.h>
long long int ar[100];
double ar1[100];
long long int gcd(long long int a, long long int b)
{
  if (b == 0) {
    return a;
  }
  else {
    return gcd(b, a % b);
  }
}
int main()
{
    long long int i,j,l,t,p,q,g,f;
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
                    g=gcd(p,q);
                    p=p/g;
                    q=q/g;
                    l=0;
                    for(i=0;i<40;i++)
                    {
                        if(ar[i]==q)
                        l=1;
                    }
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
