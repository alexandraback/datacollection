#include <cstdio>
#include <cstdlib>
#include <cstring>
const int o[8][2]={1,0,-1,0,0,1,0,-1,1,1,-1,-1,1,-1,-1,1};
int T,r,c,m,X,Y; bool f,g[7][7],h[7][7],s[7][7];
void dfs(int x,int y)
{
    if(s[x][y]||h[x][y]) return; s[x][y]=1;
    for(int i=0;i<8;++i)
        if(x+o[i][0]&&x+o[i][0]<=r&&y+o[i][1]&&y+o[i][1]<=c)
            dfs(x+o[i][0],y+o[i][1]);
}
bool check()
{
    for(int i=1;i<=r;++i)
        for(int j=1;j<=c;++j)
        {
            h[i][j]=g[i][j];
            for(int k=0;k<8;++k) if(g[i+o[k][0]][j+o[k][1]]) {h[i][j]=1; break;}
        }
    for(int i=1;i<=r;++i)
        for(int j=1;j<=c;++j) if(!g[i][j]&&h[i][j])
        {
            bool x=0;
            for(int k=0;k<8;++k)
                if(i+o[k][0]&&i+o[k][0]<=r&&j+o[k][1]&&j+o[k][1]<=c)
                    if(!h[i+o[k][0]][j+o[k][1]]) {x=1; break;}
            if(!x) return 0;
        }
    for(int i=1;i<=r;++i)
        for(int j=1;j<=c;++j) if(!h[i][j])
        {
            memset(s,0,sizeof(s));
            dfs(i,j); X=i; Y=j;
            for(int k=1;k<=r;++k)
                for(int l=1;l<=c;++l) if(!h[k][l]&&!s[k][l]) return 0;
            return 1;
        }
}
void print()
{
    for(int i=1;i<=r;++i)
    {
        for(int j=1;j<=c;++j) if(i==X&&j==Y)
            printf("c");
        else
            printf("%c",g[i][j]?'*':'.');
        printf("\n");
    }
}
void go(int x,int y,int z)
{
    if(x>r) {go(1,y+1,z); return;}
    if(!z)
    {
        if(check()) {f=1; print();}
        return;
    }
    if(y>c||f) return;
    g[x][y]=1; go(x+1,y,z-1);
    g[x][y]=0; go(x+1,y,z);
}
void ps()
{
    printf("c");
    for(int i=1;i<=r;++i)
    {
        for(int j=i==1?2:1;j<=c;++j) printf("*");
        printf("\n");
    }
}
int main()
{
    freopen("i.txt","r",stdin);
    freopen("o.txt","w",stdout);
    scanf("%d",&T);
    for(int I=1;I<=T;++I)
    {
        scanf("%d%d%d",&r,&c,&m); f=0;
        printf("Case #%d:\n",I);
        if(r*c==m+1) ps();
        else
        {
            memset(g,0,sizeof(g)); memset(h,0,sizeof(h));
            go(1,1,m); if(!f) printf("Impossible\n");
        }
    }
    return 0;
}
