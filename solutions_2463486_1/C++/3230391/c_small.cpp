# include <cstring>
# include <cstdio>
# include <iostream>
# include <cstdlib>
using namespace std;
# define N 10000000
long long q [ 1000 ] ;
int a[20];
inline int pd (long long x)
{
    int tot=0;
    while (x)
    {
        a[++tot] = x%10;
        x /= 10;      
    }
    for (int i=1;i<=tot;i++)
        if (a[i]!=a[tot+1-i])
           return 0;
    return 1;
}
int main (void)
{
    int tail=0;
    for (int i=1;i<=N;i++)
    {
        long long x = (long long) i*i;
        if (pd (i) && pd(x))
           q[++tail]=x;
    }
    int t,ys=0;
    long long x,y;
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    scanf("%d",&t);
    while (t--)
    {
        int ans=0;
        scanf("%lld%lld",&x,&y);
        for (int i=1;i<=tail;i++)
        {
            if (q[i]>=x && q[i]<=y)
               ans++;
        }
        printf("Case #%d: %d\n",++ys,ans);
    }
    return 0;   
}
