#include<cstdio>
#include<algorithm>
#include<cstring>

#define MAXX 111

short t,T;
int n,m,i,j,k;
int a[MAXX][MAXX];
int max[2][MAXX];

int main()
{
    scanf("%hd",&T);
    for(t=1;t<=T;++t)
    {
        memset(max,0,sizeof(max));
        scanf("%d %d",&n,&m);
        for(i=0;i<n;++i)
            for(j=0;j<m;++j)
            {
                scanf("%d",a[i]+j);
                max[0][i]=std::max(max[0][i],a[i][j]);
            }
        for(i=0;i<m;++i)
            for(j=0;j<n;++j)
                max[1][i]=std::max(max[1][i],a[j][i]);
        for(i=0;i<n;++i)
            for(j=0;j<m;++j)
                if(a[i][j]!=std::min(max[0][i],max[1][j]))
                    goto OT;
OT:
        printf("Case #%hd: %s\n",t,i<n?"NO":"YES");
    }
    return 0;
}
