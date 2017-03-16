#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int MAXN=110;
const int INF=1e9;
const int direction[4][2]= {{0,-1},{-1,0},{0,1},{1,0}};
const int limit=50;
const int fast=20;

struct Node
{
    int x,y;
    Node(int _x,int _y)
    {
        x=_x;
        y=_y;
    }
};
int f[MAXN][MAXN][2];
int d[MAXN][MAXN],H,n,m;
bool visit[MAXN][MAXN];
vector<Node> sts;

void inputdata()
{
    scanf("%d%d%d",&H,&n,&m);
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            cin>>f[i][j][0];
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            cin>>f[i][j][1];
}
inline int max(int x,int y)
{
    return x>y?x:y;
}
inline bool check(int x,int y)
{
    return 1<=x && x<=n && 1<=y && y<=m;
}
void solve()
{
    memset(d,0x3f,sizeof(d));
    memset(visit,false,sizeof(visit));
    d[1][1]=0,visit[1][1]=true;
    sts.clear();
    sts.push_back(Node(1,1));
    for (int i=0; i<(int)sts.size(); ++i)
    {
        int ox=sts[i].x,oy=sts[i].y;
        for (int j=0; j<4; ++j)
        {
            int x=ox+direction[j][0],y=oy+direction[j][1];
            if (check(x,y) && !visit[x][y] && f[x][y][0]-max(f[x][y][1],H)>=limit &&
                f[x][y][0]-max(f[ox][oy][1],H)>=limit && f[ox][oy][0]-max(f[x][y][1],H)>=limit)
            {
                d[x][y]=0,visit[x][y]=true;
                sts.push_back(Node(x,y));
            }
        }
    }
    // for spfa
    queue<Node> que;
    for (int i=0; i<(int)sts.size(); ++i)
        que.push(sts[i]);
    for (int i=1; i<=m; ++i)
        while (!que.empty())
        {
            int ox=que.front().x,oy=que.front().y;
            que.pop(),visit[ox][oy]=false;
            for (int j=0; j<4; ++j)
            {
                int x=ox+direction[j][0],y=oy+direction[j][1];
                int t=d[ox][oy];
                if (!check(x,y) || f[x][y][0]-f[x][y][1]<limit ||
                        f[x][y][0]-f[ox][oy][1]<limit || f[ox][oy][0]-f[x][y][1]<limit)
                    continue;
                int wait=max(0,(H-t)-(f[x][y][0]-limit));
                int leavingHeight=max(f[ox][oy][1],H-t-wait);
                int toTime=leavingHeight-f[ox][oy][1]>=fast?10:100;
                if (d[x][y]>d[ox][oy]+wait+toTime)
                {
                    d[x][y]=d[ox][oy]+wait+toTime;
                    if (!visit[x][y])
                        visit[x][y]=true,que.push(Node(x,y));
                }

            }
        }
    cout<<d[n][m]/10<<'.'<<d[n][m]%10<<endl;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    for (int i=1; i<=t; ++i)
    {
        printf("Case #%d: ",i);
        inputdata();
        solve();
    }
    return 0;
}

