#include<stdio.h>
#include<string.h>
long long int gcd(long long int n,long long int m)
{
    if(m%n==0)
    return n;
    else
    return gcd(m%n,n);
}
int powcheck(long long int m)
{
    if(m==1)
    return 0;
    else
    if(m%2==1)
    return 1;
    else
    return powcheck(m/2);
}

long long int llg(long long int m)
{
    long long int count=1;
    while(m!=1)
    {
        m=m/2;
        count++;
    }
    return count;
}
int main()
{
   long long int T,i,j,k,m,n,p,q,r,s,flag,res;
   scanf("%lld",&T);
   for(k=1;k<=T;k++)
   {
       scanf("%lld/%lld",&n,&m);

       p=gcd(n,m);

       n=n/p;
       m=m/p;
      flag=powcheck(m);




    if(flag==1)
        printf("Case #%lld: impossible\n",k);
        else
        {
            r=m/n;

            if(m%n!=0)
            r=r+1;
            res= llg(r);
            if(r!=1&&powcheck(r)==0)
            res=res-1;

            printf("Case #%lld: %lld\n",k,res);
        }

    }
}
