#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <cmath>
#include <iostream>
#include <set>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s); i>=(e); i--)
#define LL long long
#define eps 1e-9
#define pi acos(-1.0)
#define win {printf("GABRIEL\n"); return;}
#define lose {printf("RICHARD\n"); return;}
LL max(LL a,LL b){if (a>b){return a;} else {return b;}}
LL min(LL a,LL b){if (a<b){return a;} else {return b;}}

struct P{
    double x, y;
    P(){}
    P(int x, int y):x(double(x)), y(double(y)){}
    P(double x, double y):x(x) , y(y){}
    P operator+ (const P &a) const {return P(x+a.x, y+a.y);}
    P operator- (const P &a) const {return P(x-a.x, y-a.y);}
    double operator^ (const P &a) const {return x*a.x+y*a.y;}
    void in(){scanf("%lf%lf", &x, &y);}
    void out(){printf("REQUIRED %.7f %.7f\n", x, y);}
    double dist(P a, P b) {return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
    double sqdist(P a, P b) {return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);}

};

#define M 600000
#define N 200001

int x, r, c, ok;
int a[17][17], v[17][17];
int b[17][17], p[17][17], sx, sy, pp;

int dx[5] = {0, -1, 0, 1}, dy[5] = {-1, 0, 1, 0};

int DFS(int cx, int cy){
    v[cx][cy] = 1;
    int cnt = 1;
    FOE(i, 0, 3) {
        int nx = cx + dx[i], ny = cy + dy[i];
        if (nx > 0 && nx <= r && ny > 0 && ny <= c && !v[nx][ny] && a[nx][ny] == 0) cnt += DFS(nx, ny);
    }
    return cnt;
}

int plug(int cx, int cy){
    FOE(i, 1, r) FOE(j, 1, c) a[i][j] = v[i][j] = 0;

    FOE(i, 0, 16) FOE(j, 0, 16) if (p[i][j]){
        if (i - sx + cx > r || j - sy + cy > c) return 1;
        a[i - sx + cx][j - sy + cy] = 1;
    }

    FOE(i, 1, r) FOE(j, 1, c) if (a[i][j] == 0 && v[i][j] == 0){
        if (DFS(i, j) % x != 0) return 1;
    }

    return 0;
}

int check(int order){
    int fi = 1;
    sx = 16; sy = 16;
    if (order == 0) FOE(i, 0, 16) FOE(j, 0, 16) p[i][j] = b[i][j];
    else FOE(i, 0, 16) FOE(j, 0, 16) p[i][j] = b[j][i];
    FOE(i, 0, 16) FOE(j, 0, 16) if (p[i][j]){
        sx = min(sx, i);
        sy = min(sy, j);
    }

    FOE(i, 1, c) FOE(j, 1, c) if (!plug(i, j)) fi = 0;

    if (order == 1) return fi;
    if (order == 0){
        fi = min(fi, check(1));
        if (fi) ok = 1;
    }
}

void go(int cx, int cy, int p){
    b[cx][cy] = 1;
    if (p == x) check(0);
    else {
        FOE(i, 0, 3) if (b[cx + dx[i]][cy + dy[i]] == 0) go(cx + dx[i], cy + dy[i], p + 1);
    }
    b[cx][cy] = 0;
}

void solve(){
    pp = 0;
    scanf("%d%d%d", &x, &r, &c);
 /*   if (r * c % x != 0) lose
    if (r > c) swap(r, c);
    if (r < (x - 1) / 2 + 1) lose
    if (c < (x / 2) + 1) lose */
    if (x >= 7) lose
    ok = 0;
    go(8, 8, 1);

    if (ok) lose
    win
}

int main(){
    freopen("D-large.in", "r", stdin);
    freopen("D.out", "w", stdout);
    int t;
    scanf("%d", &t);
    FOE(i, 1, t){
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}
