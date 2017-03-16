#include<cstdio>
using namespace std;
int ans[1100][3],nans,ab[11][11],ac[11][11],bc[11][11],a,b,c,m;
main()
{
    int i,j,k,q,nq;
    scanf("%d",&nq);
    for(q=1;q<=nq;q++)
    {
        scanf("%d%d%d%d",&a,&b,&c,&m);
        for(i=1;i<=a;i++)
            for(j=1;j<=b;j++)
                ab[i][j]=0;
        for(i=1;i<=a;i++)
            for(j=1;j<=c;j++)
                ac[i][j]=0;
        for(i=1;i<=b;i++)
            for(j=1;j<=c;j++)
                bc[i][j]=0;
        nans=0;
        for(i=1;i<=a;i++)
            for(j=1;j<=b;j++)
                for(k=1;k<=c;k++)
                {
                    if(ab[i][j]>=m||ac[i][k]>=m||bc[j][k]>=m)
                        continue;
                    ab[i][j]++;
                    ac[i][k]++;
                    bc[j][k]++;
                    ans[nans][0]=i;
                    ans[nans][1]=j;
                    ans[nans][2]=k;
                    nans++;
                }
        printf("Case #%d: %d\n",q,nans);
        for(i=0;i<nans;i++)
            printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
    }
    return 0;
}
