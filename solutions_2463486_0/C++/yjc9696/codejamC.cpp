#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
long long i,j,k,l,n,m,s,an,sum,tot;
const long long N=110000;
long long a[N],b[N];
bool cheak(long long x)
{
    long long s=0;
    while (x)
    {
        a[++s]=x%10;
        x/=10;
    }
    for (long long i=1;i<=s/2;i++)
    if (a[i]!=a[s-i+1]) return false;
    return true;
}
int main()
{
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    //cheak(100);
    for (long long  i=1;i<=10000000;i++)
    if (cheak(i)&&(cheak(i*i))) b[++tot]=i*i;
    long long T;
    scanf("%I64d",&T);
    for (long long t=1;t<=T;t++)
    {
        an=0;
        scanf("%I64d%I64d",&n,&m);
        for (long long i=1;i<=tot;i++)
        if ((b[i]>=n)&&(b[i]<=m))
        an++;
        printf("Case #%I64d: ",t);
        printf("%I64d\n",an);
    }
   // system("pause");
    return 0;
}
