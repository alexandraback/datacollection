#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
long long t,s,e;
long long num[10000010];
bool judge(long long num)
{
    char a[1000];
    int pos=0;
    while(num)
    {
        a[pos++]=num%10+'0';
        num/=10;
    }
    a[pos]='\0';
    int len=strlen(a);
    for(int i=0;i<len;i++)
    {
        if(a[i]!=a[len-1-i])
        return false ;
    }
    return true;
}
int main ()
{
    long long ans=0;
    //freopen("C-large-1.in","r",stdin);
    //freopen("c.txt","w",stdout);
    memset(num,0,sizeof(num));
    int p=0;
    for(int  i=1; i<=10000000; i++)
    {
        long long temp=(long long )i*i;
        if(judge(i)&&judge(temp))
        {
            num[p++]=temp;
        }
    }
    scanf("%d",&t);
    for(long long  l=1; l<=t; l++)
    {
        scanf("%I64d%I64d",&s,&e);
        ans=0;
        for(long long i=0;i<p;i++)
        {
            if(num[i]>=s&&num[i]<=e)
            ans++;
        }
        printf("Case #%I64d: %I64d\n",l,ans);
    }
}
