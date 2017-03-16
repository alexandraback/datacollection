#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int c=1;c<=t;c++)
    {
        int n,a;
        scanf("%d%d",&a,&n);
        int mt[111];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&mt[i]);
        }
        sort(mt,mt+n);
        int ans=n;
        for(int i=0;i<=n&&a>1;i++)
        {
            int s=a;
            int w=n-i;
            for(int j=0;j<i;j++)
            {
                while(s<=mt[j])
                {
                    s+=s-1;
                    w++;
                }
                s+=mt[j];
            }
            if(ans>w)
                ans=w;
        }
        printf("Case #%d: %d\n",c,ans);
    }
    return 0;
}
