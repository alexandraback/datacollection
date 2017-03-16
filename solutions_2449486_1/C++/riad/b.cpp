#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAX 103

using namespace std;

int row[MAX],col[MAX],inp[MAX][MAX];

int main()
{
    freopen("bin.txt","r",stdin);
    freopen("bout.txt","w",stdout);
    int test,cas,n,m,i,j;
    scanf("%d",&test);
    for (cas=1;cas<=test;cas++)
    {
        scanf("%d%d",&n,&m);
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        for (i=0;i<n;i++)
        {
            for (j=0;j<m;j++)
            {
                scanf("%d",&inp[i][j]);
                row[i]=max(row[i],inp[i][j]);
                col[j]=max(col[j],inp[i][j]);
            }
        }
        for (i=0;i<n;i++)
        {
            for (j=0;j<m;j++)
            {
                if (row[i]<=inp[i][j]||col[j]<=inp[i][j]) ;
                else break;
            }
            if (j<m) break;
        }
        if (i<n) printf("Case #%d: NO\n",cas);
        else printf("Case #%d: YES\n",cas);
    }
    return 0;
}
