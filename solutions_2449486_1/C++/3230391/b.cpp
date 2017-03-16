# include <cstring>
# include <cstdio>
# include <iostream>
# include <cstdlib>
using namespace std;
# define N 150
int mrow[N],mcol[N],a[N][N];
int main (void)
{
    int t, ys=0, n,m;
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    scanf("%d",&t);
    
    while (t--){
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                scanf("%d",&a[i][j]);
        
        for (int i=1;i<=n;i++)
        {
            mrow [ i ] = -1;
            for (int j=1;j<=m;j++)
                mrow[i] = max(mrow[i],a[i][j]);    
        }
        for (int j=1;j<=m;j++)
        {
            mcol [j] = -1;
            for (int i=1;i<=n;i++)
                mcol [j] = max(mcol[j],a[i][j]);
        }
        int flag = 1;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                if (a[i][j]!=mrow[i] && a[i][j]!=mcol[j])
                   flag=0;
        if (flag) printf("Case #%d: YES\n",++ys);
        else printf("Case #%d: NO\n",++ys);
    }
    return 0;   
}
