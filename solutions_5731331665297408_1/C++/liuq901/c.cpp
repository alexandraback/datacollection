#include <cstdio>
#include <cstring>
#include <bitset>
#include <algorithm>
using namespace std;
int b[60],c[60],f[60],a[1000000][2];
bitset <60> all,vis[60];
void dfs(int x,int t)
{
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (vis[t].test(y) || f[y]!=-1)
            continue;
        vis[t].set(y);
        dfs(y,t);
    }
}
int calc(int n,int start)
{
    int m=0,s[60];
    for (int i=start;i!=0;i=f[i])
        s[++m]=i;
    reverse(s+1,s+m+1);
    for (int i=1;i<=m;i++)
    {
        int x=s[i];
        vis[x].reset();
        dfs(x,x);
    }
    bitset <60> tmp=all;
    int mi=1<<30,u,v;
    for (int i=1;i<=m;i++)
    {
        int x=s[i];
        tmp|=vis[x];
        if (tmp.count()!=n)
            continue;
        for (int j=b[x];j;j=a[j][1])
        {
            int y=a[j][0];
            if (f[y]==-1 && c[y]<=mi)
            {
                mi=c[y];
                u=x;
                v=y;
            }
        }
    }
    f[v]=u;
    return(v);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            scanf("%d",&c[i]);
        memset(b,0,sizeof(b));
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[i][0]=y,a[i][1]=b[x],b[x]=i;
            a[i+m][0]=x,a[i+m][1]=b[y],b[y]=i+m;
        }
        int k=1;
        for (int i=1;i<=n;i++)
            if (c[i]<c[k])
                k=i;
        all.reset();
        all.set(k);
        static int id=0;
        printf("Case #%d: %d",++id,c[k]);
        memset(f,-1,sizeof(f));
        f[k]=0;
        for (int i=2;i<=n;i++)
        {
            k=calc(n,k);
            all.set(k);
            printf("%d",c[k]);
        }
        printf("\n");
    }
    return(0);
}

