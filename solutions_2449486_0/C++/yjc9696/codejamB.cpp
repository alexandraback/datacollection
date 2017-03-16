#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int i,j,k,l,n,m,s,an,sum;
char a[101][101];
void work(int x,int y)
{
    if (!an) return;
    for (int i=1;i<=n;i++)
    if (a[i][y]<a[x][y])
    {
        for (int j=1;j<=m;j++)
        if (a[i][j]>a[i][y]) an=0;
    }
    for (int j=1;j<=m;j++)
    if (a[x][j]<a[x][y])
    {
        for (int i=1;i<=n;i++)
        if (a[i][j]>a[x][j]) an=0;
    }
}
   
int main()
{
       freopen("b1.in","r",stdin);
    freopen("b.out","w",stdout);
     int T;
    scanf("%d",&T);
    for (int t=1;t<=T;t++)
    {
        an=1;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        scanf("%d",&a[i][j]);
        for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        work(i,j);
        printf("Case #%d: ",t);
        if (!an) printf("NO\n");
        else printf("YES\n");
    }
   // system("pause");
    return 0;
}
        
