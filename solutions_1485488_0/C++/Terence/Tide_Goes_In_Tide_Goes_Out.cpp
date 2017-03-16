#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
using namespace std;

#define N 150
#define MAX(a,b) ((a)>(b)?(a):(b))

int h, n, m, cl[N][N], fl[N][N];
int tim[N][N];

int hx[N*N], hy[N*N], hp;
void heap_init()
{
    hp = 0;
}

void heap_push(int x, int y)
{
    hx[hp] = x; hy[hp++] = y;
}

void heap_update(int x, int y)
{
}

bool heap_pop(int &x, int &y)
{
    if(hp <= 0)
        return false;
    int im = 0;
    for(int i = 0; i < hp; i++) {
        if(tim[hx[i]][hy[i]] < tim[hx[im]][hy[im]])
            im = i;
    }
    x = hx[im]; y = hy[im];
    for(int i = im+1; i < hp; i++) {
        hx[i-1] = hx[i];
        hy[i-1] = hy[i];
    }
    --hp;
    return true;
}

int stk[N*N][2], top;
void dfs(int x, int y)
{
    stk[0][0] = x; stk[0][1] = y; top = 0;
    tim[x][y] = 0;
    while(top >= 0) {
        x = stk[top][0]; y = stk[top--][1];
        heap_push(x,y);
        if(x > 0 && tim[x-1][y] < 0 && cl[x-1][y]-fl[x-1][y]>=50 && cl[x-1][y]-fl[x][y]>=50 && cl[x][y]-fl[x-1][y]>=50 && cl[x-1][y]-h>=50) {
            stk[++top][0] = x-1; stk[top][1] = y;
            tim[x-1][y] = 0;
        }
        if(x < n-1 && tim[x+1][y] < 0 && cl[x+1][y]-fl[x+1][y]>=50 && cl[x+1][y]-fl[x][y]>=50 && cl[x][y]-fl[x+1][y]>=50 && cl[x+1][y]-h>=50) {
            stk[++top][0] = x+1; stk[top][1] = y;
            tim[x+1][y] = 0;
        }
        if(y > 0 && tim[x][y-1] < 0 && cl[x][y-1]-fl[x][y-1]>=50 && cl[x][y-1]-fl[x][y]>=50 && cl[x][y]-fl[x][y-1]>=50 && cl[x][y-1]-h>=50) {
            stk[++top][0] = x; stk[top][1] = y-1;
            tim[x][y-1] = 0;
        }
        if(y < m-1 && tim[x][y+1] < 0 && cl[x][y+1]-fl[x][y+1]>=50 && cl[x][y+1]-fl[x][y]>=50 && cl[x][y]-fl[x][y+1]>=50 && cl[x][y+1]-h>=50) {
            stk[++top][0] = x; stk[top][1] = y+1;
            tim[x][y+1] = 0;
        }
    }
}

int dijkstra(int tx, int ty)
{
    int x, y;
    if(tim[tx][ty] >= 0)
        return tim[tx][ty];
    while(heap_pop(x, y)) {
        if(x == tx && y == ty)
            return tim[x][y];
        if(x > 0 && cl[x-1][y]-fl[x-1][y]>=50 && cl[x-1][y]-fl[x][y]>=50 && cl[x][y]-fl[x-1][y]>=50) {
            int tx = MAX(h - (cl[x-1][y]-50),tim[x][y]);
            tx += (h-tx >= fl[x][y]+20 ? 10 : 100);
            if(tim[x-1][y] < 0) {
                tim[x-1][y] = tx;
                heap_push(x-1,y);
            } else if(tim[x-1][y] > tx) {
                tim[x-1][y] = tx;
                heap_update(x-1,y);
            }
        }
        if(x < n-1 && cl[x+1][y]-fl[x+1][y]>=50 && cl[x+1][y]-fl[x][y]>=50 && cl[x][y]-fl[x+1][y]>=50) {
            int tx = MAX(h - (cl[x+1][y]-50),tim[x][y]);
            tx += (h-tx >= fl[x][y]+20 ? 10 : 100);
            if(tim[x+1][y] < 0) {
                tim[x+1][y] = tx;
                heap_push(x+1,y);
            } else if(tim[x+1][y] > tx) {
                tim[x+1][y] = tx;
                heap_update(x+1,y);
            }
        }
        if(y > 0 && cl[x][y-1]-fl[x][y-1]>=50 && cl[x][y-1]-fl[x][y]>=50 && cl[x][y]-fl[x][y-1]>=50) {
            int tx = MAX(h - (cl[x][y-1]-50),tim[x][y]);
            tx += (h-tx >= fl[x][y]+20 ? 10 : 100);
            if(tim[x][y-1] < 0) {
                tim[x][y-1] = tx;
                heap_push(x,y-1);
            } else if(tim[x][y-1] > tx) {
                tim[x][y-1] = tx;
                heap_update(x,y-1);
            }
        }
        if(y < m-1 && cl[x][y+1]-fl[x][y+1]>=50 && cl[x][y+1]-fl[x][y]>=50 && cl[x][y]-fl[x][y+1]>=50) {
            int tx = MAX(h - (cl[x][y+1]-50),tim[x][y]);
            tx += (h-tx >= fl[x][y]+20 ? 10 : 100);
            if(tim[x][y+1] < 0) {
                tim[x][y+1] = tx;
                heap_push(x,y+1);
            } else if(tim[x][y+1] > tx) {
                tim[x][y+1] = tx;
                heap_update(x,y+1);
            }
        }
    }
}

int main()
{
    int t;
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    //freopen("B-large.in", "r", stdin);
    //freopen("B-large.out", "w", stdout);
    scanf("%d", &t);
    for(int idx = 1; idx <= t; idx++) {
        scanf("%d%d%d", &h, &n, &m);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                scanf("%d", &cl[i][j]);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                scanf("%d", &fl[i][j]);
        memset(tim, -1, sizeof(tim));
        heap_init();
        dfs(0,0);
        printf("Case #%d: %lf\n", idx, dijkstra(n-1,m-1)/10.0);
    }
    return 0;
}
