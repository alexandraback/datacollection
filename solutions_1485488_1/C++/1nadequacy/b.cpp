#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <functional>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

#define pb push_back
#define mp make_pair
#define sz(a) int((a).size())
#define forn(i, n) for (int i=0; i<(n); ++i)

typedef pair<ld, int> node;

const int maxn = 128;
const ld eps = 1e-9;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int n, m, h;
int a[maxn][maxn], b[maxn][maxn];
ld f[maxn][maxn];
bool u[maxn][maxn];
priority_queue<node,vector<node>, greater<node> > q;
int qx[maxn*maxn], qy[maxn*maxn], qs, qf;

bool cango(int x1, int y1, int x2, int y2, ld w)
{
    if (x2<0 || x2>=n || y2<0 || y2>=m) return false;
    if (w+50 > b[x2][y2]) return false;
    if (a[x2][y2]+50 > b[x2][y2]) return false;
    if (a[x1][y1]+50 > b[x2][y2]) return false;
    if (a[x2][y2]+50 > b[x1][y1]) return false;
    return true;

}


double solve()
{
    forn (i, n) forn (j, m) f[i][j] = 1e10;
    while (!q.empty()) q.pop();
    forn (i, n) forn (j, m) u[i][j] = false;
    qs = qf = 0;
    qx[qf] = 0, qy[qf++] = 0;
    u[0][0] = true;
    for (; qs<qf; ++qs)
    {
        int x = qx[qs], y = qy[qs];
        f[x][y] = 0;
        q.push(mp(f[x][y], x*1000+y));
        forn (i, 4) 
        {
            int nx = x+dx[i], ny = y+dy[i];
            if (cango(x, y, nx, ny, h) && !u[nx][ny])
                qx[qf] = nx, qy[qf++] = ny, u[nx][ny] = true;
        }
    }

    while (!q.empty())
    {
        ld ff = q.top().first;
        int x = q.top().second / 1000;
        int y = q.top().second % 1000;
        q.pop();
        if (f[x][y] > ff) continue;
        if (x == n-1 && y == m-1) return ff;

        forn (i, 4)
        {
            int nx = x+dx[i], ny = y+dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            ld w = max(ld(0), h - ff*10);
            ld wait = 0.0;
            if (w+50 > b[nx][ny]-eps)
            {
                wait = (50- (b[nx][ny]-w))/10;
            }
            
            ld w2 = max(ld(0), h-(ff+wait)*10);
            if (!cango(x, y, nx, ny, w2)) continue;
            int togo = 0;
            if ((w2-a[x][y]) > 20-eps) togo = 1; else togo = 10;
            ld nff = ff+wait+togo;
            if (nff < f[nx][ny]-eps)
            {
                f[nx][ny] = nff;
                q.push(mp(f[nx][ny], 1000*nx+ny));
            }
        }


    }
    

    return 1e10;


}

int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);

    int tc; scanf("%d", &tc);
    for (int tt=1; tt<=tc; ++tt)
    {
        scanf("%d %d %d", &h, &n, &m);
        forn (i, n) forn (j, m) scanf("%d", &b[i][j]);
        forn (i, n) forn (j, m) scanf("%d", &a[i][j]);
        printf("Case #%d: %.10f\n", tt, solve());
    }

    return 0;
}
