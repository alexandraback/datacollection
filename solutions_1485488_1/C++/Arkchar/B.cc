#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <complex>
using namespace std;

// begin insert defines
template <class T> inline void gmin (T &a, T b) {if (b < a) a = b;}
#define PB push_back
#define ND second
#define FS first
template <class T> void PA(T x[], int n) {for (int i = 0; i < n; i++) cout << x[i] << " "; cout << endl;}
#define CR clear
#define PR pair
template<typename S, typename T> ostream& operator<<(ostream& os, pair<S,T> p){ return os << "(" << p.first << "," << p.second << ")"; };
template <class T> void PV(T x) {for(__typeof__((x).begin()) i = (x).begin(); i != (x).end(); i++) cout << *i << " "; cout << endl;}
typedef pair<int, int> PII;
#define Rep(i,n) for(int n_ = (n), i = 0; i< n_; ++i)
#define MP make_pair

// end insert defines

const int N = 100, H = 10010;

const int mv[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int n, m, gh;
int c[N][N], f[N][N];
set<PII> bgns;

bool ib(int x, int y)
{
  return x < n && x >=0 && y < m && y >= 0;
}

int check(int x, int y, int nx, int ny, int h)
{
  if (!ib(nx, ny)) return 0;
  int ff = max(max(f[x][y], h), f[nx][ny]);
  int cc = min(c[x][y], c[nx][ny]);
  if (cc - ff < 50) return 0;
  return h - f[x][y] >= 20 ? 10 : 100;
}

int back[N][N];

void dfs(int x, int y)
{
  if (bgns.count(MP(x, y))) return ;
  bgns.insert(MP(x, y));
  Rep(i, 4) {
    int nx = x + mv[i][0], ny = y + mv[i][1];
    if (check(x, y, nx, ny, gh))
      dfs(nx, ny);
  }
}

void bfs_back()
{
  queue<PII> que;
  que.push(MP(n - 1, m - 1));
  back[n - 1][m - 1] = 0;
  for (; que.size(); que.pop()) {
    int x = que.front().FS, y = que.front().ND;
    Rep(i, 4) {
      int nx = x + mv[i][0], ny = y + mv[i][1];
      if (check(x, y, nx, ny, 0) && back[nx][ny] == -1) {
        que.push(MP(nx, ny));
        back[nx][ny] = back[x][y] + 1;
      }
    }
  }
}

void dfs2(int x, int y, int d)
{
  int &ret = back[x][y];
  if (ret != -1) return ;
  ret = d;
  Rep(i, 4) {
    int nx = x + mv[i][0], ny = y + mv[i][1];
    if (check(x, y, nx, ny, 0))
      dfs2(nx, ny, d + 1);
  }
}

bool v[N][N][H];

struct Que
{
  int x, y, h;
  Que(int _x, int _y, int _h): x(_x), y(_y), h(_h){}
};

queue<Que> que;
int ans;

void bfs(int bgnx, int bgny)
{
  while (que.size()) que.pop();
  que.push(Que(bgnx, bgny, gh));
  v[bgnx][bgny][gh] = true;
  for (; que.size(); que.pop()) {
    int x = que.front().x;
    int y = que.front().y;
    int h = que.front().h;
    if (h == 0) {
      if (back[x][y] != -1) {
        gmin(ans, back[x][y] * 100 + gh);
      }
      continue;
    }
    else {
      if (!v[x][y][h - 1]) {
        v[x][y][h - 1] = true;
        que.push(Que(x, y, h - 1));
      }
    }
    Rep(i, 4) {
      int nx = x + mv[i][0], ny = y + mv[i][1];
      int t;
      if (t = check(x, y, nx, ny, h)) {
        if (h - t >= 0 && gh - (h - t) < ans) {
          if (!v[nx][ny][h - t]) {
            que.push(Que(nx, ny, h - t));
            v[nx][ny][h - t] = true;
            if (nx == n - 1 && ny == m - 1)
              gmin(ans, gh - (h - t));
          }
        }
        else {
          if (back[nx][ny] != -1) {
            // if (gh - h + t + back[nx][ny] == 172) {
            //   cout << gh << endl;
            //   cout << h << endl;
            //   cout << t << endl;
            //   cout << back[nx][ny] << endl;
            //   cout << MP(x, y) << endl;
            //   cout << MP(nx, ny) << endl;
            // }
            gmin(ans, gh - h + t + back[nx][ny] * 100);
          }
        }
      }
    }
  }
  Rep(i, H) if (v[n - 1][m - 1][i]) {
    gmin(ans, gh - i);
  }
}

int main(int argc, char *argv[])
{
  int T;
  cin >> T;
  Rep(Ca, T) {
    cout << "Case #" << Ca + 1 << ": ";
    cin >> gh >> n >> m;
    Rep(i, n) Rep(j, m) cin >> c[i][j];
    Rep(i, n) Rep(j, m) cin >> f[i][j];
    memset(v, 0, sizeof(v));
    bgns.CR();
    dfs(0, 0);
    memset(back, -1, sizeof(back));
    bfs_back();
    memset(v, 0, sizeof(v));
    ans = 100000000;
    // Rep(i, n) PA(back[i], m);
    // PV(bgns);
    for (const PII &bgn: bgns)
      bfs(bgn.FS, bgn.ND);
    printf("%.2lf\n", ans / 10.0);
  }
  return 0;
}

