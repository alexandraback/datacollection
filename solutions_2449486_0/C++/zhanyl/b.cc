#include <cstdio>
#include <cstdlib>
#include <cstring>

int n,m,f[105][105],t,a[105],b[105];

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            a[i]=0;
        for(int i=0;i<m;i++)
            b[i]=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                scanf("%d",&f[i][j]);
                if(f[i][j]>a[i])a[i]=f[i][j];
                if(f[i][j]>b[j])b[j]=f[i][j];
            }
        bool ans=1;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(a[i]>f[i][j]&&b[j]>f[i][j])ans=0;
        if(ans)printf("Case #%d: YES\n",cas);
        else printf("Case #%d: NO\n",cas);
    }
    return 0;
}
