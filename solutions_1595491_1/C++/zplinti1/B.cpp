#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
    int cas;
    int n,s,p,x;

    freopen("in.in","r",stdin);
    freopen("ans.out","w",stdout);
    scanf("%d",&cas);
    for(int ii=1;ii<=cas;ii++)
    {
        scanf("%d %d %d",&n,&s,&p);
        int ans=0;
        int limit1=p+max(p-1,0)+max(p-1,0);
        int limit2=p+max(p-2,0)+max(p-2,0);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            if (x>=limit1) ans++;
            else
            if (x>=limit2&&s)
            {
                ans++;
                s--;
            }
        }
        printf("Case #%d: %d\n",ii,ans);
    }
    return 0;
}
