#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int a,long long int b)
{
    if(b==0)
        return a;
    else return gcd(b,a%b);
}
int main()
{
    freopen("input.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long int ii,t;
    scanf("%lld",&t);
    for(ii=1;ii<=t;ii++)
    {
        char s[30];
        scanf("%s",&s);
        long long int n=0,m=0,i,x,st,count=0,co=0;
        for(i=0;s[i]!='/';i++)
            n=n*10+(s[i]-48);
        i++;
        for(;s[i]!='\0';i++)
            m=m*10+(s[i]-48);
        x=gcd(n,m);
        n/=x;
        m/=x;
        st=m;
        while(st%2==0)
        {
            st/=2;
            count ++;
        }
        if(st!=1)
           printf("Case #%lld: impossible\n",ii);
        else if(n==1)
        {
            printf("Case #%lld: %lld\n",ii,count);
        }
        else
        {
            while(n<m)
            {
                n*=2;
                co++;
            }
            printf("Case #%lld: %lld\n",ii,co);
        }
    }
    return 0;
}
