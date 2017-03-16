#include <cstdio>
#include <algorithm>
using namespace std;
long long mote[1000010];
void solve()
{
    long long a,n,mi=10000000,ad=0;
    scanf("%lld%lld",&a,&n);
    for(int i=0;i<n;i++)
        scanf("%lld",&mote[i]);
    if(a==1)
    {
        printf("%lld",n);
        return;
    }
    sort(mote,mote+n);
    for(int i=0;i<n;i++)
    {
        mi=min(mi,ad+n-i);
        if(a<=mote[i])
        {
            while(a<=mote[i])
            {
                ad++;
                a+=a-1;
            }
        }
        a+=mote[i];
    }
    mi=min(mi,ad);
    printf("%lld",mi);
}
int main()
{
    int t;
    freopen("Sm.in","r",stdin);
    freopen("ou.out","w",stdout);
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        printf("Case #%d: ",i);
        solve();
        printf("\n");
    }
}
