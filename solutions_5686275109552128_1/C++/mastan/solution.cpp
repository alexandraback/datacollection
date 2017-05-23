#include <cstdio>
#include <algorithm>

using namespace std;

int vals[1005];
int tc;

int main()
{
    freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
    scanf("%d",&tc);
    for (int it=1; it<=tc; it++)
    {
        int n;
        scanf("%d",&n);
        for (int i=1; i<=n; i++)
            scanf("%d",&vals[i]);
        int ret=10000;
        for (int lim=1; lim<=1000; lim++)
        {
            int nmx=0;
            int moar=0;
            for (int i=1; i<=n; i++)
            {
                moar+=(vals[i]+lim-1)/lim-1;
                nmx=max(nmx,min(vals[i],lim));
            }
            //printf("%d %d %d\n",lim,nmx,moar);
            ret=min(ret,moar+nmx);
        }
        printf("Case #%d: %d\n",it,ret);
    }

}
