#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long n,m,aux,k;
long long put2[60];
bool b[60],a[60][60];
int main()
{
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    int Q;
    scanf("%d\n",&Q);
    put2[0]=1;
    for(int i=1;i<=52;i++)
        put2[i]=2LL*put2[i-1];
    for(int test=1;test<=Q;test++)
    {
        printf("Case #%d: ",test);

        scanf("%lld %lld",&n,&m);
        memset(a,0,sizeof(a));
        for(int i=1;i<=n-1;i++)
            for(int j=i+1;j<n;j++)
                a[i][j]=1;
        if(put2[n-2]<m)
        {
            printf("IMPOSSIBLE\n");
            continue;
        }
        else printf("POSSIBLE\n");
        if(put2[n-2]==m)
        {
            for(int i=1;i<n;i++)
                a[i][n]=1;
        }
        else
        {
            aux=m;
            k=0;
            while(aux>0)
            {
                b[++k]=aux%2;
                aux/=2;
            }
            for(int i=2;i<=k+1;i++)
                a[i][n]=b[i-1];
        }
        for(int i=1;i<=n;i++&&printf("\n"))
            for(int j=1;j<=n;j++)
                printf("%d",a[i][j]);
    }
    return 0;
}
