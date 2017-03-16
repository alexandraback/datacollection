#include <cstdio>

using namespace std;

int main()
{
    int T,t;
    freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        int d,p[1000],ans=1;
        int i,z=2,sum;
        scanf("%d",&d);
        for(i=0;i<d;i++)
        {
            scanf("%d",&p[i]);
            if(p[i]>ans) ans=p[i];
        }
        while(z<ans)
        {
            sum=0;
            for(i=0;i<d;i++)
            {
                sum+=(p[i]-1)/z;
            }
            sum+=z;
            if(sum<ans) ans=sum;
            z++;
        }
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}
