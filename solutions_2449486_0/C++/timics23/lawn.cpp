#include<stdio.h>
#include<algorithm>
using namespace std;
int T,M,N,l[110],c[110],a[110][110],ok;
int main()
{
    freopen("input.in","r",stdin);
    freopen("bla.out","w",stdout);
    scanf("%d",&T);
    for(int k=1;k<=T;++k)
    {
        ok=0;
        scanf("%d%d",&N,&M);
        for(int j=1;j<=M;++j)
            c[j]=0;
        for(int i=1;i<=N;++i)
        {
            l[i]=0;
            for(int j=1;j<=M;++j)
            {
                scanf("%d",&a[i][j]);
                if(a[i][j]>l[i])
                    l[i]=a[i][j];
                if(a[i][j]>c[j])
                    c[j]=a[i][j];
            }
        }

        for(int i=1;i<=N;++i)
        {
            for(int j=1;j<=M;++j)
                if(a[i][j]!=min(l[i],c[j]))
                {
                    ok=1;
                    break;
                }
            if(ok==1)
            {
                printf("Case #%d: NO\n",k);
                break;
            }
        }

        if(ok==0)
            printf("Case #%d: YES\n",k);
    }

    return 0;
}
