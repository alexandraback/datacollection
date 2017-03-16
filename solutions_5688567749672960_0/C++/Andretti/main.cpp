#include <stdio.h>
#include<algorithm>
using namespace std;

int T,nr;
long long n;
int a[20];

long long det(long long x)
{
    if(x==n) return 1;

    long long aux=x; nr=0;
    for(;aux;aux/=10) a[++nr]=aux%10;

    int i=1;
    long long inv=0;

    for(;a[i]==0;i++);
    for(int j=i;j<=nr;j++)
    {
        inv=inv*10+a[j];
        if(inv>n) break;
    }

    long long sol;
    if(inv>x && inv<=n) sol=1+det(inv);
    else sol=1+det(x+1);

    return sol;
}


int main()
{
    freopen("date.in","r",stdin);
    freopen("date.out","w",stdout);

    scanf("%d",&T);
    for(int it=1;it<=T;it++)
    {
        scanf("%lld",&n);
        printf("Case #%d: %lld\n",it,det(1));
    }


    return 0;
}
