#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
#define M 1005
#define INF 1<<30
#define exp 1e-6
int t,n,m,x;
bool a[M][M];
bool aa[M][M];
void fk()
{
}
void gao(int p)
{
    for(int i=1;i<=n;i++)
    {
        if(a[p][i])
        {
            gao(i);
        }
    }
}
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    scanf("%d",&t);
    for(int cas=1; cas<=t; cas++)
    {
        scanf("%d",&n);
        bool c=0;
        memset(a,0,sizeof(a));
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&m);
            for(int j=0; j<m; j++)
            {
                scanf("%d",&x);
                a[i][x]=1;
            }
        }
        for(int k=1;k<=n;k++)
        {
            if(c)
            break;
            for(int i=1;i<=n;i++)
            {
                if(c)
                break;
                for(int j=1;j<=n;j++)
                {
                    if(c)
                    break;
                    if(a[i][k] && a[k][j])
                    {
                        if(a[i][j])
                        c=1;
                        else
                        a[i][j]=1;
                    }
                }
            }
        }
        printf("Case #%d: ",cas);
        if(c)
        printf("Yes\n");
        else
        printf("No\n");
    }
    return 0;
}
