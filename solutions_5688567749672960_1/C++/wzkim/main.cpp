#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

long long n,m;
char k[20];
int t,cases=0;
long long op[20],ans;

long long p9(int x)
{
    long long ret=9;
    for(int i=1;i<x;i++)
        ret=ret*10+9;
    return ret;
}
long long rev(long long x)
{
    long long ret=0;
    while(x!=0)
    {
        ret=ret*10+x%10;
        x=x/10;
    }
    return ret;
}
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.txt","w",stdout);
    op[1]=0;
    op[2]=10;
    for(int i=3;i<16;i++)
    {
        int cnt=(i-1)/2;
        if(i%2==0)
        {
            op[i]=op[i-1]+p9(cnt)+p9(cnt+1)+1;
        }
        else
        {
            op[i]=op[i-1]+p9(cnt)*2+1;
        }
    }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",k+1);
        int l=strlen(k+1);
        m=0;
        for(int i=1;i<=l;i++)
            m=m*10+k[i]-'0';
        ans=op[l];
        long long a=0,b=0;
        for(int i=1;i<=l/2;i++)
            a=a*10+k[i]-'0';
        for(int i=l/2+1;i<=l;i++)
            b=b*10+k[i]-'0';
        if(rev(a)==1)
        {
            ans=ans+b;
        }
        else if(b==0)
        {
            ans=ans+rev(a-1)+p9(l-l/2);
            if(rev(a-1)!=1)
                ans++;
        }
        else
        {
            ans=ans+rev(a)+b;
        }
        printf("Case #%d: %lld\n",++cases,ans);
    }
    return 0;
}
