/**
* Small Dataset O(n)
*/
#include <cstdio>
#include <algorithm>
#define forn(i,n) for(int i=0;i<(int)n;i++)
typedef long long ll;
int rvs(int n)
{
    int ret=0;
    while(n!=0)
    {
        ret=ret*10+n%10;
        n/=10;
    }
    return ret;
}
int a[1000000+1];
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int T;
    int n;
    for(int i=1;i<=1000000;i++)
    {
        int t=rvs(i);
        //if(i<100) printf("i=%d r=%d\n",i,t);
        if(i>t && i%10!=0) a[i]=std::min(a[i-1],a[t])+1;
        else a[i]=a[i-1]+1;
        //if(i<100) printf("%d %d\n",i,a[i]);
    }
    scanf("%d",&T);
    for(int tc=1;tc<=T;tc++)
    {
        scanf("%d",&n);
        printf("Case #%d: %d\n",tc,a[n]);
    }
    return 0;
}
