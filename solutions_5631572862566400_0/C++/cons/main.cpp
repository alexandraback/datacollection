#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#define FOR(i,x,y) for(int i=x;i<=y;++i)
using namespace std;
bool vis[1010];
int maxcircle,maxx,deep,t,x,y,n,temp,c[1010][1010],g[1010][1010],f[1010][1010];
void dfs(int x,int no,int cnt)
{
    int xx;
    if(cnt>deep) deep=cnt;
    FOR(i,1,g[x][0])
    {
        xx=g[x][i];
        if(xx!=no) dfs(xx,no,cnt+1);
    }
}
int main()
{
    scanf("%d",&t);
    FOR(s,1,t)
    {
        memset(f,0xc3,sizeof(f));
        memset(vis,0,sizeof(vis));
        memset(g,0,sizeof(g));
        memset(c,0,sizeof(c));
        maxcircle=0;
        maxx=0;
        printf("Case #%d: ",s);
        scanf("%d",&n);
        //FOR(i,1,n) f[i][i]=0;
        FOR(i,1,n)
        {
            scanf("%d",&temp);
            f[i][temp]=1;
            c[i][temp]=1;
            ++g[temp][0];
            g[temp][g[temp][0]]=i;
        }
        FOR(k,1,n) FOR(i,1,n) FOR(j,1,n) if(i!=k&&k!=j)
        {
            if(f[i][k]+f[k][j]>f[i][j]) f[i][j]=f[i][k]+f[k][j];
        }
        FOR(i,1,n)
        {
            if(maxcircle<f[i][i]) maxcircle=f[i][i];
            if(f[i][i]==2&&!vis[i])
            {
                FOR(j,1,g[i][0]) if(c[i][g[i][j]])
                {
                    x=i; y=g[i][j];
                    vis[x]=true;
                    vis[y]=true;
                    deep=0;
                    dfs(x,y,1);
                    temp=deep;
                    deep=0;
                    dfs(y,x,1);
                    temp+=deep;
                    maxx+=temp;
                }
            }
        }
        if(maxx<maxcircle) maxx=maxcircle;
        printf("%d\n",maxx);
    }
    return 0;
}
