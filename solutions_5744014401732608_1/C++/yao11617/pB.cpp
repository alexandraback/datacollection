#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

typedef long long LL;

int main()
{
    int T;
    scanf("%d",&T);
    for(int tc=1;tc<=T;++tc)
    {
        int n;
        LL m;
        scanf("%d%lld",&n,&m);
        if(m<(LL)1<<n-2)
        {
            printf("Case #%d: POSSIBLE\n",tc);
            for(int i=1;i<n;++i)
            {
                for(int j=1;j<n;++j)
                {
                    printf("%d",(int)(i<j));
                }
                printf("%d\n",(int)((m>>i-2)&1));
            }
            for(int i=1;i<=n;++i)printf("0");
            printf("\n");
        }
        else if(m>(LL)1<<n-2)
        {
            printf("Case #%d: IMPOSSIBLE\n",tc);
        }
        else
        {
            printf("Case #%d: POSSIBLE\n",tc);
            for(int i=1;i<=n;++i)
            {
                for(int j=1;j<=n;++j)
                {
                    printf("%d",(int)(i<j));
                }
                printf("\n");
            }
        }
    }
    return 0;
}
