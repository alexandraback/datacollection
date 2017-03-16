#include <cstdio>
#include <algorithm>
using namespace std;
int mote[1000010];
void solve()
{
    int a,n,mi=10000000,ad=0;
    scanf("%d%d",&a,&n);
    for(int i=0;i<n;i++)
        scanf("%d",&mote[i]);
    if(a==1)
    {
        printf("%d",n);
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
    printf("%d",mi);
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
