#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define inf 0x3f3f3f3f
#define N 101
#define M 1001
int n,a[2000];
int main()
{
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    int T,cas=0;
    cin>>T;
    while (T--)
    {
        scanf("%d",&n);
        int mx=0,ans=inf;
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            mx=max(a[i],mx);
        }
        for (int i=1;i<=mx;i++)
        {
            int tmp=i;
            for (int j=1;j<=n;j++)
            {
                tmp+=(a[j]-1)/i;
            }
            ans=min(tmp,ans);
        }
        printf("Case #%d: %d\n",++cas,ans);
    }
}
