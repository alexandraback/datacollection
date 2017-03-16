#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int tt,n,m,a[200][200],b[200],c[200];
bool work()
{
    for(int i=1;i<=n;++i)
    for(int j=1;j<=m;++j)
    {
        if (a[i][j]<b[i] && a[i][j]<c[j])
            return false;    
    }
    return true;
}
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d",&tt);
    for(int o=1;o<=tt;++o)
    {
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        printf("Case #%d: ",o);
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            scanf("%d",&a[i][j]);
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                b[i]=max(b[i],a[i][j]);
                c[j]=max(c[j],a[i][j]);
            }
        }
        if (work())
            puts("YES");
        else puts("NO");  
    }
}
