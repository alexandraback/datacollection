#include<stdio.h>
#include<algorithm>
using namespace std;
int v[101010];
int din[1010][1010];
int E,R,N,T;
int caz;
void make()
{
    int ret=-101010;
    for(int i=0;i<=20;++i)
        for(int j=0;j<=20;++j)
            din[i][j]=-1010;
    din[0][E]=0;
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<=E;++j)
        {
        if(din[i][j]>=0)
            for(int k=0;k<=j;++k)
            {
                din[i+1][min(E,j-k+R)] = max(din[i][j] + k * v[i+1],din[i+1][min(E,j-k+R)]);
            }
        }
    }
    for(int i=0;i<=E;++i)
        ret = max(ret,din[N][i]);
    printf("Case #%d: %d\n",caz,ret);
}

int main()
{
freopen("b.in","r",stdin);
freopen("b.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        ++caz;
        scanf("%d%d%d",&E,&R,&N);
        for(int i=1;i<=N;++i)
            scanf("%d",&v[i]);
        make();
    }
}
