#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>

int t,id,a,b,k,ans;
int i,j;


int main()
{
    freopen("B-small-attempt0.in","r",stdin);freopen("b.out","w",stdout);
    scanf("%d",&t);
    for (id=1;id<=t;id++)
    {
        ans=0;
        scanf("%d%d%d",&a,&b,&k);
        printf("Case #%d: ",id);
        for (i=0;i<a;i++)
            for (j=0;j<b;j++)
            if ((i&j)<k)ans++;
        printf("%d\n",ans);
    }
    return 0;
}
