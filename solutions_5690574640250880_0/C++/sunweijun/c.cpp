#include<cstdio>
#include<cstring>
#define fo(i,a,b) for(int i=a;i<=b;++i)
const int mn=20,dx[]={-1,-1,-1,0,0,1,1,1},dy[]={-1,0,1,-1,1,-1,0,1};
int R,C,M,m1,col[mn][mn];
bool u[mn][mn],vis[mn][mn];
char map[mn][mn];
bool flag;
int cnt;
void search(int i,int j)
{
    int chc=0;
    vis[i][j]=1;
    ++cnt;
    fo(k,0,7)
        if(u[i+dx[k]][j+dy[k]])++chc;
    if(chc)return;
    fo(k,0,7)
    {
        int x=i+dx[k],y=j+dy[k];
        if(x<1||x>R||y<1||y>C)continue;
        if(!vis[x][y]&&!u[x][y])
            search(x,y);
    }
}
void check()
{
    cnt=0;
    fo(i,1,R)
        fo(j,1,C)
            if(!u[i][j])
            {
                int chc=0;
                fo(k,0,7)
                    if(u[i+dx[k]][j+dy[k]])++chc;
                if(chc)continue;
                memset(vis,0,sizeof vis);
                search(i,j);
                if(cnt==R*C-m1)
                {
                    fo(x,1,R)
                        fo(y,1,C)
                            map[x][y]=u[x][y]?'*':'.';
                    map[i][j]='c';
                    flag=1;
                }
                return;
            }
}
void dfs(int r,int c)
{
    if(flag)return;
    if(r>R)
    {
        if(!M)
            check();
        return;
    }
    if(c>C)
    {
        dfs(r+1,1);
        return;
    }
    if(M)
    {
        u[r][c]=1;
        --M;
        dfs(r,c+1);
        u[r][c]=0;
        ++M;
    }
    dfs(r,c+1);
}
int main()
{
    int Q;
    scanf("%d",&Q);
    fo(T,1,Q)
    {
        scanf("%d%d%d",&R,&C,&M);
        if(R*C-M==1)
        {
            printf("Case #%d:\n",T);
            fo(i,1,R-1)
            {
                fo(j,1,C)putchar('*');
                printf("\n");
            }
            fo(i,1,C-1)putchar('*');
            puts("c");
            continue;
        }
        m1=M;
        memset(u,0,sizeof u);
        memset(map,0,sizeof map);
        flag=0;
        dfs(1,1);
        printf("Case #%d:\n",T);
        if(flag)
            fo(i,1,R)puts(map[i]+1);
        else puts("Impossible");
    }
    return 0;
}
