#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,k,cate,x[5],a[5],ab[10][10],ac[10][10],bc[10][10],ras[1004][5];
void bck(int m)
{
    if(m==3)
    {
        if(ab [x[0]][x[1]]>=k)return ;
        if(ac [x[0]][x[2]]>=k)return ;
        if(bc [x[1]][x[2]]>=k)return ;
        ab [x[0]][x[1]]++;
        ac [x[0]][x[2]]++;
        bc [x[1]][x[2]]++;
        cate++;
        ras[cate][0]=x[0];
        ras[cate][1]=x[1];
        ras[cate][2]=x[2];
        return ;
    }
    for(int i=1;i<=a[m];i++)
    {
        x[m]=i;
        if(m==1 && ab[x[0]][x[1]]>=k)continue;
        bck(m+1);
    }
}
int main()
{
    freopen("input","r",stdin);
    freopen("out","w",stdout);
    int Q;
    scanf("%d\n",&Q);
    for(int test=1;test<=Q;test++)
    {
        printf("Case #%d: ",test);

        scanf("%d %d %d %d",&a[0],&a[1],&a[2],&k);
        memset(ab,0,sizeof(ab));
        memset(ac,0,sizeof(ac));
        memset(bc,0,sizeof(bc));
        cate=0;
        bck(0);
        printf("%d\n",cate);
        for(int i=1;i<=cate;i++)
            printf("%d %d %d\n",ras[i][0],ras[i][1],ras[i][2]);
    }
    return 0;
}
