#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int a[1005];

int main()
{
    freopen("bs.in","r",stdin);
    freopen("bs.out","w",stdout);
    int T,i,j,n,p,cnt=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        p=0;
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            p=max(p,a[i]);
        }
        int ans=p;
        for (i=1;i<=p;i++)
        {
            int s=0;
            for (j=0;j<n;j++)
            {
                s+=(a[j]/i)+(a[j]%i!=0)-1;
            }
          //  printf("%d..%d\n",i,s);
            ans=min(ans,s+i);
        }
        printf("Case #%d: %d\n",cnt++,ans);
    }
    return 0;
}
