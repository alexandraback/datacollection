#include <cstdio>
#include <cstdlib>
#include <cstring>
int t,r,n,m,k,f[205],g[205],ans[3],cnt;
int main()
{
    freopen("in3","r",stdin);
    freopen("out3","w",stdout);
    scanf("%d",&t); printf("Case #1:\n");
    scanf("%d%d%d%d",&r,&n,&m,&k);
    while(r--)
    {
        memset(f,0,sizeof(f)); int x,y; cnt=k+1;
        for(int i=0;i<k;++i) {scanf("%d",&x); ++f[x];}
        if(n==3)
        {
            y=k;
            for(int i=2;i<=5&&cnt;++i)
                for(int j=2;j<=5&&cnt;++j)
                    for(int u=2;u<=5&&cnt;++u)
                    {
                        y=k; memcpy(g,f,sizeof(g));
                        if(g[1]) {--y; --g[1];}
                        if(g[i]) {--y; --g[i];}
                        if(g[j]) {--y; --g[j];}
                        if(g[u]) {--y; --g[u];}
                        if(g[i*j]) {--y; --g[i*j];}
                        if(g[i*u]) {--y; --g[i*u];}
                        if(g[j*u]) {--y; --g[j*u];}
                        if(g[i*j*u]) {--y; --g[i*j*u];}
                        if(y<cnt) {cnt=y; ans[0]=i; ans[1]=j; ans[2]=u;}
                    }
        }
        printf("%d%d%d\n",ans[0],ans[1],ans[2]);
    }
    return 0;
}
