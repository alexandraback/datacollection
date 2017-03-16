#include <iostream>
#include <cstdio>
using namespace std;
const int mm=111;
int a[mm][mm],x[mm],y[mm];
int i,j,n,m,t,cs,flag;
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;++i)
            for(j=1;j<=m;++j)
                scanf("%d",&a[i][j]);
        for(i=1;i<=n;++i)
            for(x[i]=j=1;j<=m;++j)
                x[i]=max(x[i],a[i][j]);
        for(j=1;j<=m;++j)
            for(y[j]=i=1;i<=n;++i)
                y[j]=max(y[j],a[i][j]);
        flag=1;
        for(i=1;i<=n;++i)
            for(j=1;j<=m;++j)
                if(a[i][j]!=x[i]&&a[i][j]!=y[j])flag=0;
        printf("Case #%d: %s\n",++cs,flag?"YES":"NO");
    }
    return 0;
}
