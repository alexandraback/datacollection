#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define ll long long
ll mote[1100];
ll dp[1100];
ll a,n;
int main()
{
    int T;
    #ifdef OJ
    freopen("A-large.in","r",stdin);
    freopen("aa.txt","w",stdout);
    #endif
    scanf("%d",&T);
    int ca=0;
    while(T--)
    {
        scanf("%lld",&a);
        scanf("%lld",&n);
    //    printf("%d %d\n",a,n);
        for(int i=0;i<n;i++)
            scanf("%lld",&mote[i]);
        sort(mote,mote+n);
        ll res=0;
        for(int i=0;i<n;i++)
        {
            while(a<=mote[i]&&res<n)
            {
                res++;
                a+=a-1;
            }
            a+=mote[i];
            dp[i]=res;
        }
        res=n;
        for(int i=0;i<n;i++) if(dp[i]+n-i-1<res)
            res=dp[i]+n-i-1;
       // for(int i=0;i<n;i++)
      //      printf("%d ",mote[i]);
     //   printf("\n");
        printf("Case #%d: %lld\n",++ca,res);
    }
}
