#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int a[1005];

int main()
{
    freopen("as.in","r",stdin);
    freopen("as.out","w",stdout);
    int i,j,n,T,cnt=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        n++;
        for (i=0;i<n;i++)
        {
            scanf("%1d",&a[i]);
        }
        int ans=0;
        int t=0;
        for (i=0;i<n;i++)
        {
            if (t<i)
            {
                ans+=(i-t);
                a[i]+=(i-t);
            }
            t+=a[i];
        }
        printf("Case #%d: %d\n",cnt++,ans);
    }
    return 0;
}
