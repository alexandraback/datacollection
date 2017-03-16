#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN=110;
const int INF=~0U>>1;
const int dir[4][2]={{0,-1},{-1,0},{0,1},{1,0}};
const int IMT=50;
const int FST=20;

struct Node
{
    int x,y;
    Node(){}
    Node(int _x,int _y):x(_x),y(_y){}
};
struct Snode
{
    int up,down;
} map[MAXN][MAXN];
int d[MAXN][MAXN];
int H,n,m;
bool flag[MAXN][MAXN];
vector<Node> sts;

void init()
{
    scanf("%d%d%d",&H,&n,&m);
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            scanf("%d",&map[i][j].up);
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            scanf("%d",&map[i][j].down);
}
bool check(int x,int y)
{
    return 1<=x && x<=n && 1<=y && y<=m;
}
void bfs()
{
    memset(d,0x3f,sizeof(d));
    memset(flag,false,sizeof(flag));
    d[1][1]=0,flag[1][1]=true;
    sts.clear();
    sts.push_back(Node(1,1));
    for (int i=0; i<(int)sts.size(); ++i)
    {
        int ox=sts[i].x,oy=sts[i].y;
        for (int f=0; f<4; ++f)
        {
            int x=ox+dir[f][0],y=oy+dir[f][1];
            if (check(x,y) && !flag[x][y] &&
                    map[x][y].up-max(map[x][y].down,H)>=IMT &&
                    map[x][y].up-max(map[ox][oy].down,H)>=IMT &&
                    map[ox][oy].up-max(map[x][y].down,H)>=IMT)
            {
                d[x][y]=0;
                flag[x][y]=true;
                sts.push_back(Node(x,y));
            }
        }
    }
}
void spfa()
{
    queue<Node> que;
    for (int i=0; i<(int)sts.size(); ++i)
        que.push(sts[i]);
    for (int j=1; j<=m; ++j)
        while (!que.empty())
        {
            int ox=que.front().x,oy=que.front().y;
            que.pop(),flag[ox][oy]=false;
            for (int f=0; f<4; ++f)
            {
                int x=ox+dir[f][0],y=oy+dir[f][1];
                int t=d[ox][oy];
                if (!check(x,y) || map[x][y].up-map[x][y].down<IMT ||
                    map[x][y].up-map[ox][oy].down<IMT || map[ox][oy].up-map[x][y].down<IMT)
                    continue;
                int wait=max(0,(H-t)-(map[x][y].up-IMT));
                int leavingHeight=max(map[ox][oy].down,H-t-wait);
                int toTime=leavingHeight-map[ox][oy].down>=FST?10:100;
                if (d[x][y]>d[ox][oy]+wait+toTime)
                {
                    d[x][y]=d[ox][oy]+wait+toTime;
                    if (!flag[x][y])
                        flag[x][y]=true,que.push(Node(x,y));
                }

            }
        }
}
void solve()
{
    bfs();
    spfa();
    printf("%d.%d\n",d[n][m]/10,d[n][m]%10);
}
int main()
{
    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int cases=1,t;
    for (scanf("%d",&t); t--;)
    {
        printf("Case #%d: ",cases++);
        init();
        solve();
    }
    return 0;
}

