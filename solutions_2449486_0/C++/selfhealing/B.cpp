#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[105][105];

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B.out","w",stdout);
    int T,n,m,cas=0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                scanf("%d",&a[i][j]);
        int ok = 1, f1,f2;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                f1 = f2 = 0;
                for(int k = 0; k < m; k++)
                    if(a[i][k] > a[i][j])
                        f1 = 1;
                for(int k = 0; k < n; k++)
                    if(a[k][j] > a[i][j])
                        f2 = 1;
                if(f1 && f2)ok = 0;
            }
        printf("Case #%d: %s\n",++cas,ok?"YES":"NO");
    }

    return 0;
}
