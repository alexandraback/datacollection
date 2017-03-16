#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
long long  dp[105][105];
long long  ma[102][102];
long long mb[120][120];
struct pp
{
    long long num;
    int type;
} a[102],b[102],ta[122],tb[102];
int tr[122][3]= {{0,0,0},{0,0,1},{0,0,2},{0,1,1},{0,1,2},{0,2,2},{1,1,1},
    {1,1,2},{1,2,2},{2,2,2}
};
long long  match(int i,int j)
{
    if(ta[i].type==tb[j].type)
    {
        long long mn=min(ta[i].num,tb[j].num);
        ta[i].num-=mn;
        tb[j].num-=mn;
        return mn;
    }
    return 0;
}
int main()
{
    freopen("cs.in","r",stdin);
    freopen("cs.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int c=1; c<=T; c++)
    {
        printf("Case #%d: ",c);
        int m,n;
        memset(dp,0,sizeof(dp));
        memset(ma,0,sizeof(ma));
        memset(mb,0,sizeof(mb));
        scanf("%d%d",&n,&m);
        for(int i=0; i<n; i++)
            scanf("%lld%d",&a[i].num,&a[i].type);
        for(int i=0; i<m; i++)
            scanf("%lld%d",&b[i].num,&b[i].type);
        long long mx=0;
        for(int i=0; i<m; i++)
        {
            for(int j=i; j<m; j++)
            {
                for(int k=j; k<m; k++)
                {
                    for(int dd=0; dd<10; dd++)
                    {
                        for(int tt=0;tt<3;tt++)
                        {
                        long long t=0;
                        for(int d=0; d<m; d++)
                            tb[d]=b[d];
                        for(int d=0; d<n; d++)
                            ta[d]=a[d];
                        t=0;
                        int j1,j2;
                        for(int q=0; q<=tr[dd][0]; q++)
                            t+=match(q,i);
                            if(tt==0)j1=i,j2=i;
                            else if(tt==1)j1=i,j2=j;
                            else j1=j,j2=j;
                        for(int q=tr[dd][0]; q<=tr[dd][1]; q++)
                            t+=match(q,j1);
                        for(int q=tr[dd][1]; q<=tr[dd][2]; q++)
                            t+=match(q,j2);
                        for(int q=tr[dd][2]; q<=2; q++)
                            t+=match(q,k);
                        mx=max(t,mx);
                        }
                    }
                }
            }
        }
        printf("%lld\n",mx);
    }


    return 0;
}
