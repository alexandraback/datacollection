#include<stdio.h>
#include<string.h>

int main()
{
    int T,c=0,N,M,i,j,k,inp[110][110],row[110],col[110],YES;

    freopen("B-small.in","r",stdin);
    freopen("B-small.out","w",stdout);

    scanf("%d",&T);

    while(c++<T)
    {
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        scanf("%d%d",&N,&M);

        for(i=0;i<N;i++)
        {
            for(j=0;j<M;j++)
            {
                scanf("%d",&k);
                inp[i][j]=k;
                if(row[i]<k) row[i]=k;
                if(col[j]<k) col[j]=k;
            }
        }
        /*puts("");
        for(i=0;i<N;i++) printf("%d ",row[i]); puts("");
        for(i=0;i<M;i++) printf("%d ",col[i]); puts("");
        puts("");*/
        YES=1;
        for(i=0;i<N;i++)
        {
            for(j=0;j<M;j++)
            {
                if(!(inp[i][j]>=row[i] || inp[i][j]>=col[j])) YES=0;
                if(!YES) break;
            }
            if(!YES) break;
        }
        if(YES) printf("Case #%d: YES\n",c);
        else printf("Case #%d: NO\n",c);
    }
    return 0;
}
