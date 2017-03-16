#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define MAXN 110
#define MP(x,y) make_pair((x),(y))
using namespace std;
int ty[300],fa[MAXN*2][MAXN*2];
const char outdir[10]="NESW";
const int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
const int ndir[4][2]={{0,-1},{-1,0},{0,1},{1,0}};
char str[MAXN];
void cal()
{
    queue<pair<int,int> >que;
    que.push(MP(0+MAXN,0+MAXN));
    int nsize;
    for(int h =1;h<=500&&que.size();++h)
    {
        nsize=que.size();
        while(nsize--)
        {
            int x=que.front().first,y=que.front().second,tx,ty;
            que.pop();
            for(int i=0;i<4;++i)
            {
                tx=x+dir[i][0]*h,ty=y+dir[i][1]*h;
                if(tx<0||tx>=2*MAXN||ty<0||ty>=2*MAXN)  continue;
                if(fa[tx][ty]==-1)
                {
                    fa[tx][ty]=i;
                    que.push(MP(tx,ty));
                }
            }
        }
    }
}
int main()
{
    freopen("/home/moor/Code/input.txt","r",stdin);
    //freopen("/home/moor/Code/output.txt","w",stdout);
    int ncase,x,y,tx,ty;
    vector<int> ans;
    memset(fa,-1,sizeof(fa));
    fa[MAXN][MAXN]=5;
    cal();
    for(int h=1;h<=ncase;++h)
    {
        scanf("%d%d",&x,&y);
        x+=MAXN,y+=MAXN;
        ans.clear();
        while(fa[x][y]!=5)
        {
            ans.push_back(fa[x][y]);
            tx=x+ndir[fa[x][y]][0],ty=y+ndir[fa[x][y]][1];
            x=tx,y=ty;
        }
        printf("Case #%d: ",h);
        for(int i=ans.size()-1;i>=0;--i)
            printf("%c",outdir[ans[i]]);
    }
    return 0;
}

