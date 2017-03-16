#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int T,n,a1,a2; double f[1005],g[1005];
int main()
{
    freopen("i.txt","r",stdin);
    freopen("o.txt","w",stdout);
    scanf("%d",&T); int x,y,z;
    for(int I=1;I<=T;++I)
    {
        scanf("%d",&n); a1=a2=0;
        for(int i=1;i<=n;++i) scanf("%lf",&f[i]);
        for(int i=1;i<=n;++i) scanf("%lf",&g[i]);
        sort(f+1,f+n+1); sort(g+1,g+n+1); x=1; y=n;
        for(int i=n;i;--i)
        {
            if(g[y]>f[i]) --y;
            else {++x; ++a2;}
        }
        x=1; y=n;
        for(int i=1;i<=n;++i)
        {
            if(g[x]>f[i]) --y;
            else {++x; ++a1;}
        }
        /*
        a1=a2;
        g[n+1]=2;
        for(int i=0;i<=n;++i)
        {
            x=1; y=n-i; z=0;
            for(int j=i+1;j<=n;++j)
            {
                if(g[x]>f[j]) --y;
                else {++x; ++z;}
            }
            a1=max(z,a1);
        }
        */
        printf("Case #%d: %d %d\n",I,a1,a2);
    }
    return 0;
}
