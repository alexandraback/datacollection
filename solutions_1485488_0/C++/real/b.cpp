#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cctype>
#include <numeric>
#include <queue>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <iterator>
#define FOR(i,s,e) for(int i=(s);i<(int)(e);i++)
#define FOE(i,s,e) for(int i=(s);i<=(int)(e);i++)
#define REP(i,n)   FOR(i,0,n)
#define ALL(x) (x).begin(), (x).end()
#define CLR(s) memset(s,0,sizeof(s))
#define PB push_back
#define ITER(v)      __typeof((v).begin())
#define FOREACH(i,v) for(ITER(v) i=(v).begin();i!=(v).end();i++)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef vector<int> vi;
#define x first
#define y second

const int N = 105;
int vis[20001][N][N] = {0}; // time,i,j
int H, n, m;
int c[N][N];
int a[N][N];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = { 0,-1, 0, 1};

inline bool in(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
}

int qx[N*N], qy[N*N], hd, tl;

int main() {
        int T; scanf("%d", &T);
        FOE(ca, 1, T) {
                scanf("%d%d%d", &H, &n, &m);
                FOR(i, 0, n) FOR(j, 0, m) scanf("%d", &c[i][j]);
                FOR(i, 0, n) FOR(j, 0, m) scanf("%d", &a[i][j]);

                printf("Case #%d: ", ca);

                vis[0][0][0] = ca;
                hd = 0, tl = 0;
                qx[tl] = 0; qy[tl++] = 0;
                while (hd != tl) {
                        int i = qx[hd], j = qy[hd++];
                        int h = H;
                        FOR(k, 0, 4) {
                                int x = i + dx[k], y = j + dy[k];
                                if (!in(x, y) || vis[0][x][y] == ca) continue;
                                if (c[x][y] >= a[i][j] + 50
                                 && c[x][y] >= h + 50
                                 && c[x][y] >= a[x][y] + 50)
                                        if (a[x][y] <= c[i][j] - 50) {
                                                vis[0][x][y] = ca;
                                                qx[tl] = x; qy[tl++] = y;
                                        }
                        }
                }

                bool sol = false;
                for (int t=0; t<=20000; t++) {
                        int h = H - t;
//                      if (t % 1000 == 0) printf("t=%d : %d\n", t, h);
                        if (vis[t][n-1][m-1] == ca) { printf("%d.%d\n", t/10, t%10); break; }

                        int hd = 0, tl = 0;

                        FOR(i, 0, n) FOR(j, 0, m) if (vis[t][i][j] == ca) {
                                FOR(k, 0, 4) {
                                        int x = i + dx[k], y = j + dy[k];
                                        if (!in(x, y)) continue;
                                        // kayak!
                                        int dt = (h >= a[i][j] + 20 ? 10 : 100);
                                        if (c[x][y] >= a[i][j] + 50
                                         && c[x][y] >= h + 50
                                         && c[x][y] >= a[x][y] + 50)
                                                if (a[x][y] <= c[i][j] - 50) {
                                                        vis[t+dt][x][y] = ca;
                                                }
                                }
                        }

                        FOR(i, 0, n) FOR(j, 0, m) {
                                if (vis[t][i][j] == ca)
                                        vis[t+1][i][j] = ca;
                        }
                }
        }
        return 0;
}
