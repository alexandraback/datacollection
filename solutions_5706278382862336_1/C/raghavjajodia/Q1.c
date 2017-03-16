#include<stdio.h>
long long gcd(long long a,long long b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}
int main()
{
    long long i,t,flag,j,m,n,k,flag1,g,flag2;
    char s[50];
    float a;
    scanf("%lld",&t);
    for(i=1;i<=t;i++)
    {
       flag=0;m=0;n=0;flag1=0;flag2=0;
       scanf("%s",&s);
       for(j=0;s[j]!=0;j++)
       {
            if(s[j]=='/') {flag1=1;continue;}
            if(flag1==0) m=10*m+((long long)s[j]-48);
            else n=10*n+((long long)s[j]-48);
       }
       if(m>n) g=gcd(m,n);
       else g=gcd(n,m);

       a=(float)m/n;
       n=n/g;
       for(j=1;j<=40;j++)
       {
            if(a*2 >= 1) {flag=1;break;}
            else a=2*a;
       }//printf("%d\n",n);
       for(k=1;k<=40;k++)
       {
           if((long long)pow(2,k)==n) {flag2=1;break;}

       }
       if(flag=1 && flag2==1) printf("Case #%lld: %lld\n",i,j);
       else printf("Case #%lld: impossible\n",i);
   }

    return 0;
}
