#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
#include <functional>
#include <numeric>
#include <sstream>
#include <stack>
#include <map>
#include <queue>

#define CL(arr, val)    memset(arr, val, sizeof(arr))
#define lc l,m,rt<<1
#define rc m + 1,r,rt<<1|1
#define pi acos(-1.0)
#define ll long long
#define L(x)    (x) << 1
#define R(x)    (x) << 1 | 1
#define MID(l, r)   (l + r) >> 1
#define Min(x, y)   (x) < (y) ? (x) : (y)
#define Max(x, y)   (x) < (y) ? (y) : (x)
#define E(x)        (1 << (x))
#define iabs(x)     (x) < 0 ? -(x) : (x)
#define OUT(x)  printf("%I64d\n", x)
#define lowbit(x)   (x)&(-x)
#define Read()  freopen("B-small-attempt0.in", "r", stdin)
#define Write() freopen("dout.txt", "w", stdout);


#define M 30007
#define N 2007

using namespace std;

const int inf = 100000007;
const int mod = 1000000007;
const double eps = 1e-6;

struct node
{
    int x,y;
    int val;
    bool operator < (const node &a) const
    {
        return val > a.val;
    }
}nd;
priority_queue<node>q;

bool vt[N][N];
int pre[N][N],sub[N][N];
int X,Y;

void bfs(int xi,int yi)
{
    CL(vt,false);
    CL(pre,-1); CL(sub,0);

    nd.x = xi; nd.y = yi;
    nd.val = 0;

    q.push(nd);
    vt[xi][yi] = true;

    while (!q.empty())
    {
        node u = q.top(); q.pop();
        if (u.x == X && u.y == Y) break;
        for (int i = 0; i < 4; ++i)
        {
            int tx = u.x,ty = u.y;
            int val = u.val + 1;
            if (i == 0) ty += val;
            if (i == 1) tx += val;
            if (i == 2) ty -= val;
            if (i == 3) tx -= val;

            if (tx >= 0 && tx <= 1000 && ty >= 0 && ty <= 1000 && !vt[tx][ty])
            {
                nd.x = tx; nd.y =ty;
                nd.val = val;
                q.push(nd);
                pre[tx][ty] = i;
                sub[tx][ty] = val;
                vt[tx][ty] = true;
            }
        }
    }
}
char ans[N*100];
int la;
void print(int x,int y)
{
    if (x == 100 && y == 100) return ;
//    printf("%d %d\n",x,y);
    if (pre[x][y] == 0)
    {
        ans[la++] = 'N';
        print(x,y - sub[x][y]);
    }
    else if (pre[x][y] == 1)
    {
        ans[la++] = 'E';
        print(x - sub[x][y],y);
    }
    else if (pre[x][y] == 2)
    {
        ans[la++] = 'S';
        print(x,y + sub[x][y]);
    }
    else
    {
        ans[la++] = 'W';
        print(x + sub[x][y],y);
    }
}

int main()
{
    Read();
    Write();
    int T;
    int cas = 1;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&X,&Y);
        X += 100; Y += 100;

        bfs(100,100);

        printf("Case #%d: ",cas++);
        la = 0;
        print(X,Y);
//        printf(">>>\n");
        for (int i = la - 1; i >= 0; --i) printf("%c",ans[i]);
        printf("\n");
    }

    return 0;
}
