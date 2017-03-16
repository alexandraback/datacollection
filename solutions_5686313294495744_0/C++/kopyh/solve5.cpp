//kopyh
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define N 112
using namespace std;
int n,m,sum,res,flag;
string a[N],b[N];
int vis[N];
int main()
{
    int i,j,k,cas,T,t,x,y,z;
//    #ifndef ONLINE_JUDGE
//        freopen("in.in","r",stdin);
//        freopen("out.out","w",stdout);
//    #endif
    scanf("%d",&T);
    cas=0;
    while(T--)
//    while(scanf("%d",&n)!=EOF)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            cin>>a[i]>>b[i];
        }
        memset(vis,0,sizeof(vis));
        for(i=0;i<n;i++)
        {
            x=y=0;
            for(j=i+1;j<n;j++)
            {
                if(i!=j)
                {
                    if(a[i]==a[j]&&!vis[j])x=1;
                    else if(b[i]==b[j]&&!vis[j])y=1;
                }
            }
            if(x&&y)
            {
//                printf("%d ",i);
                vis[i]=1;
            }
        }
//        printf("\n");
        res=0;
        for(i=0;i<n;i++)if(vis[i])res++;
        printf("Case #%d: %d\n",++cas,res);
    }
    return 0;
}
