#include <stdio.h>
#include <stdlib.h>
int a[105][105];
int main()
{
    int T,c,n,m,i,j,k,s,x,y;
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    scanf("%d",&T);
    for(c=1;c<=T;c++)
    {
        printf("Case #%d: ",c);
        scanf("%d%d",&n,&m);
        s=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++) scanf("%d",&a[i][j]);
        }
        for(i=0;i<n;i++)
        {
            if(s) break;
            for(j=0;j<m;j++)
            {
                x=y=0;
                for(k=0;k<j;k++)
                {
                    if(a[i][k]>a[i][j]) x=1;
                }
                if(!x)
                {
                    for(k=j+1;k<m;k++)
                    {
                        if(a[i][k]>a[i][j]) x=1;
                    }
                }
                for(k=0;k<i;k++)
                {
                    if(a[k][j]>a[i][j]) y=1;
                }
                if(!y)
                {
                    for(k=i+1;k<n;k++)
                    {
                        if(a[k][j]>a[i][j]) y=1;
                    }
                }
                if(x&&y)
                {
                    s=1;
                    break;
                }
            }
        }
        if(s) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
