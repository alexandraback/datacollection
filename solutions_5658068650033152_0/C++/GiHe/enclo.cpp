#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

bool h[25][25];
int qx[4444], qy[4444];
int tail, head;
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int f[25][25][25];
int map[25][25];

void check(int n,int m,int sum)
{
    //cout << n << " " << m << endl;
    memset(h, true, sizeof h);
    qx[1] = 0;qy[1] = 0;head = 1; tail = 1;h[0][0] = false;
    int cnt = 0;
    int cx,cy;
    while (head <= tail) {
        cx = qx[head];cy = qy[head];
        for (int p = 0; p <= 3; p++) {
            int tx,ty;
            tx = cx + dx[p];ty = cy + dy[p];
            if (tx>=0 && tx<=n+1 && ty >=0 && ty <= m+1 && map[tx][ty] == 0)
            if (h[tx][ty]) {
                tail++;
                qx[tail] = tx;qy[tail] = ty;
                h[tx][ty] = false;
                if (tx>0 && tx <= n && ty > 0 && ty <= m) cnt++;
            }
        }
        head++;
    }
    if (sum < f[n][m][n*m-cnt]) f[n][m][n*m-cnt] = sum;
}

void dfs(int x, int y, int n, int m,int sum)
{
    if (y > m) dfs(x+1,1,n,m,sum);
    else if (x > n) check(n,m,sum);
    else {
        map[x][y] = 0;
        dfs(x, y+1, n, m,sum);
        map[x][y] = 1;
        dfs(x, y+1, n, m, sum+1);
    }
}

void calc(int n, int m)
{
    dfs(1, 1, n, m, 0);
}

int main()
{
    freopen("enclo.in","r", stdin);
    freopen("enclo.out","w",stdout);
    for (int i = 1; i <= 20; i++)
        for (int j = 1; j<= 20; j++)
            for (int k = 0; k <= i *j; k++)
            f[i][j][k] = 10000000;
    for (int i = 1; i <= 20; i++)
        for (int j = 1; j <= 20; j++)
        if (i * j <= 20) {
                memset(map, 0, sizeof(map));
                calc(i,j);
        }
    int testcase, x, y, z;
    scanf("%d", &testcase);
    for (int test = 1; test <= testcase; test++) {
        scanf("%d%d%d", &x, &y, &z);
        printf("Case #%d: %d\n",test,  f[x][y][z]);
    }
    return 0;
}
