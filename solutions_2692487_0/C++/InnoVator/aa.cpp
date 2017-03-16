#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int mote[1100];
int dp[1100];
int a,n;
int main()
{
    int T;
    #ifdef OJ
    freopen("A-small-attempt2.in","r",stdin);
    freopen("a.txt","w",stdout);
    #endif
    scanf("%d",&T);
    int ca=0;
    while(T--)
    {
        scanf("%d",&a);
        scanf("%d",&n);
    //    printf("%d %d\n",a,n);
        for(int i=0;i<n;i++)
            scanf("%d",&mote[i]);
        sort(mote,mote+n);
        int res=0;
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
        printf("Case #%d: %d\n",++ca,res);
    }
}
