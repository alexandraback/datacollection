#include<stdio.h>
#include<algorithm>
#define maxn 1005
using namespace std;

int T,n,Max,sol;
int a[maxn];

void read()
{
    Max=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),Max=max(Max,a[i]);
}

void solve()
{
    int nr,d;
    sol=Max;
    for(int i=1;i<=Max;i++)
    {
        nr=0;
        for(int j=1;j<=n;j++)
         if(a[j]>i)
         {
             d=a[j]/i;
             if(a[j]%i==0) d--;

             nr+=d;
         }
         sol=min(sol,i+nr);
    }
}

int main()
{
    freopen("date.in","r",stdin);
    freopen("date.out","w",stdout);

    scanf("%d",&T);
    for(int it=1;it<=T;it++)
    {
        read();
        solve();
        printf("Case #%d: %d\n",it,sol);
    }


    return 0;
}
