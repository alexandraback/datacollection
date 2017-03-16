#include <cstdio>
#include <cstring>

int a[10000];

int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int tot_tc;
    scanf("%d",&tot_tc);
    for (int tc=1;tc<=tot_tc;++tc)
    {
        int n,s,p,tmp;
        scanf("%d%d%d",&n,&s,&p);
        tmp=s;
        int ans=0;
        for (int i=0;i<n;++i)
        {
            int x;
            scanf("%d",&x);
            a[i]=x;
            if (x>=3*p-2) ++ans;
            if (x>=3*p-4 && x<3*p-2)
            {
                if (s>0) ++ans;
                --s;
            }
        }
        if (p==1)
        {
            ans=0;
            for (int i=0;i<n;++i)
                if (a[i]>0)
                    ++ans;
        }
        if (p==0) ans=n;
        printf("Case #%d: %d\n", tc,ans);
    }
    return 0;
}
