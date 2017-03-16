#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int N,M,Mine,Blank;

char mp[64][64];
bool used[64][64];

bool inrange(int xx,int yy)
{
    return xx>=0&&yy>=0&&xx<N&&yy<M;
}
bool isNeib(int xx,int yy)
{
    for(int i=-1;i<2;i++)
    for(int j=-1;j<2;j++)
    {
        int nx=xx+i;
        int ny=yy+j;
        if(inrange(nx,ny)&&mp[nx][ny]=='*') return true;
    }
    return false;
}

void dfs(int x,int y)
{
    if(used[x][y]) return;
    used[x][y]=true;
    if(isNeib(x,y)) return;
    for(int i=-1;i<2;i++)
    for(int j=-1;j<2;j++)
    {
        int nx=x+i;
        int ny=y+j;
        if(inrange(nx,ny)) dfs(nx,ny);
    }
}

bool Check()
{
    memset(used,0,sizeof(used));
    dfs(0,0);
    int cnt=0;
    for(int i=0;i<N;i++)
    for(int j=0;j<M;j++)
    {
        if(mp[i][j]=='.')
        {
            cnt++;
            if(!used[i][j]) return false;
        }
    }
    if(cnt!=Blank) return false;
    return true;
}

bool judge(int H)
{
    int DV = Blank/H;
    int MD = Blank%H;
    int CC = DV+(MD!=0);
    if(CC>M) return false;
    if(MD!=1)
    {
        for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        {
            if((i<H&&j<DV)||(i<MD&&j==DV)) mp[i][j]='.';
            else mp[i][j]='*';
        }
    }
    else
    {
        for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        {
            if((i<H&&j<DV)||(i<=MD&&j==DV)) mp[i][j]='.';
            else mp[i][j]='*';
        }
        mp[H-1][DV-1]='*';
    }
    if(Check())
    {
        mp[0][0]='c';
        return true;
    }
    return false;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int casT;
    scanf("%d",&casT);
    for(int cas=1;cas<=casT;cas++)
    {
        printf("Case #%d:\n",cas);
        memset(mp,0,sizeof(mp));
        scanf("%d%d%d",&N,&M,&Mine);
        Blank=N*M-Mine;
        bool ok=false;
        for(int H=1;H<=N;H++)
        {
            ok=judge(H);
            if(ok) break;
        }
        ///if(N==2||M==2) if(Mine&1) ok=false;
        if(ok)
        {
            for(int i=0;i<N;i++) printf("%s\n",mp[i]);
        }
        else printf("Impossible\n");
    }
    return 0;
}
