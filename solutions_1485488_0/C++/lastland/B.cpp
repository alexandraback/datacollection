#include<iostream>
#include <cstring>
#include <stdio.h>
#include <cmath>
#include <iomanip>
using namespace std;

struct node {
    int x, y;
    double time;
};

const int maxn = 100;
int T,n,m,h;
int f[maxn][maxn],c[maxn][maxn];
bool b[maxn][maxn];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

node q[maxn];
int l,r;


void init() {
    cin >> h >> n >> m;
    memset(b, 0, sizeof (b));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> c[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> f[i][j];
}

bool check(int c1,int f1,int c2,int f2)
{
    if (c2 - f2 < 50) return false;
    if (c1 - f2 < 50) return false;
    if (c2 - f1 < 50) return false;
    return true;
}

bool edge(int i, int j)
{
    if (i >= n || i < 0 || j >= m || j < 0)return false;
    else return true;
}

double solve()
{
    int xx, yy;
    int cx,cy;
    double current,tt;
    l = -1; r = 0;
    q[0].x = 0; q[0].y = 0; q[0].time = 0; b[0][0] = 1;
    while (r < n*m)
    {
        current = 1000000;
        for (int i = 0; i <= r; i++)
            for (int j = 0; j < 4; j++)
            {
                xx = q[i].x+dx[j]; yy = q[i].y+dy[j];
                if (!edge(xx,yy)||b[xx][yy]||!check(c[q[i].x][q[i].y],f[q[i].x][q[i].y],c[xx][yy],f[xx][yy])) continue;
                if (c[xx][yy] - h >= 50) tt = 0;
                else  tt = double(h-c[xx][yy]+50)/10;
                if (q[i].time > tt) tt = q[i].time;
                if (q[i].time < 0.00001 && tt < 0.00001) tt = 0;
                else
                    if (h-tt*10-f[q[i].x][q[i].y]>=20) tt+=1; else tt+= 10;
                if (current > tt)
                {
                    current = tt;
                    cx = xx;
                    cy = yy;
                }
            }
        r++;
        q[r].x = cx; q[r].y = cy; q[r].time = current; b[cx][cy] = true;
        if (cx == n-1 && cy == m-1) return current;
    }
}

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    cin >> T;
    double tmp;
    for (int test = 1; test <= T; test++) {
        cout << "Case #" << test << ": ";
        init();
        tmp = solve();
        cout << fixed << setprecision(6) << tmp << endl;
    }
    return 0;
}
