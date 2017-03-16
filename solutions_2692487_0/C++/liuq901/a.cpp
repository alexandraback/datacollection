#include <cstdio>
#include <algorithm>
using namespace std;
const int inf=100000000;
int a[1000010];
int calc(int n,int m)
{
    if (m==1)
        return(inf);
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        while (m<=a[i])
        {
            m=min(inf,(m<<1)-1);
            ans++;
        }
        m=min(inf,m+a[i]);
    }
    return(ans);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int m,n;
        scanf("%d%d",&m,&n);
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        int ans=n;
        for (int i=0;i<=n;i++)
            ans=min(ans,calc(i,m)+n-i);
        static int id=0;
        printf("Case #%d: %d\n",++id,ans);
    }
    return(0);
}

