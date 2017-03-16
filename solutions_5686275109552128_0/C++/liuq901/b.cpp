#include <cstdio>
#include <algorithm>
using namespace std;
int a[1010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        int ans=1<<30;
        for (int i=1;i<=1000;i++)
        {
            int sum=0;
            for (int j=1;j<=n;j++)
                sum+=max(0,(a[j]+i-1)/i-1);
            ans=min(ans,sum+i);
        }
        static int id=0;
        printf("Case #%d: %d\n",++id,ans);
    }
    return(0);
}

