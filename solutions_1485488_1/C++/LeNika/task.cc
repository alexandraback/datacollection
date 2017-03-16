#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
typedef long long llong;
#define X first
#define Y second

struct Qwe {
  llong time;
  int x, y;
  Qwe(llong t, int x, int y): time(t), x(x), y(y) {}
};

bool operator < (const Qwe& a, const Qwe& b)
{
  return a.time > b.time;
}

int n, m;
int H;
vector< vector<int> > c, f;
vector< vector<char> > visited;
vector< vector<llong> > tm;

const int step[4][2] = {{1,0}, {-1,0}, {0, 1}, {0,-1}};
const llong INFTY = 1LL << 50;

bool canmove(int h, int F, int C, int x, int y)
{
  return (h + 50 <= c[x][y] && f[x][y] + 50 <= c[x][y] && F + 50 <= c[x][y] && f[x][y] + 50 <= C);
}

inline bool iscorrect(int x, int y)
{
  return (x >= 0 && x < n && y >= 0 && y < m);
}

bool pathok()
{
  queue<pii> que;
  que.push(pii(0,0));
  visited[0][0] = 1;

  pii cur;
  int x, y;
  while (!que.empty()) {
    cur = que.front();
    if (cur.X == n - 1 && cur.Y == m - 1)
      return true;
    que.pop();
    for (int i = 0; i < 4; ++i) {
      x = cur.X + step[i][0];
      y = cur.Y + step[i][1];
      if (iscorrect(x, y) && !visited[x][y] && canmove(H, f[cur.X][cur.Y], c[cur.X][cur.Y], x, y)) {
          que.push(pii(x, y));
          visited[x][y] = 1;
      }
    }
  }
  return false;
}

const int swim_time = 10;
const int walk_time = 100;

/*
inline int code(int x, int y)
{
  return (x << 10) | y;
}

inline int decode(int c, int&x ,int& y)
 {
  x = c >> 10;
  y = c - (x << 10);
}
*/

llong fairsolve()
{
  tm.assign(n, vector<llong>(m, INFTY));
  priority_queue<Qwe> que;

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (visited[i][j]) {
        tm[i][j] = 0;
        que.push(Qwe(0, i, j));
      }

  Qwe cur(0,0,0);
  int x, y, h;
  llong t;

  while (!que.empty()) {
    cur = que.top();
    if (cur.x == n - 1 && cur.y == m - 1)
      break;
    que.pop();
    if (cur.time != tm[cur.x][cur.y]) continue;

    for (int i = 0; i < 4; ++i) {
      x = cur.x + step[i][0];
      y = cur.y + step[i][1];
      if (iscorrect(x, y) && canmove(0, f[cur.x][cur.y], c[cur.x][cur.y], x, y)) {
        if (canmove(H - cur.time, f[cur.x][cur.y], c[cur.x][cur.y], x, y)) {
          h = H - cur.time;
        } else {
          h = c[x][y] - 50;
        }
        t = H - cur.time - h;
        // printf("need %d, have %d, wait %d, f %d\n", h, H - cur.time, t, f[x][y]);
        if (h - f[cur.x][cur.y] >= 20) t += swim_time;
        else t += walk_time;
        
        if (tm[x][y] > cur.time + t) {
          tm[x][y] = cur.time + t;
          que.push(Qwe(tm[x][y], x, y));
          // printf("from (%d, %d, %d) to (%d, %d, %d)\n", cur.time, cur.x, cur.y, tm[x][y], x, y); 
        }
      }
    }
  }

  return tm[n - 1][m - 1];
}

llong solve()
{
  scanf("%d %d %d", &H, &n, &m);
  c.assign(n, vector<int>(m));
  f.assign(n, vector<int>(m));
  visited.assign(n, vector<char>(m, 0));

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      scanf("%d", &c[i][j]);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      scanf("%d", &f[i][j]);

  if (pathok()) return 0;

  return fairsolve();
}

int main()
{
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    llong res = solve();
    printf("Case #%d: %lld.%lld\n", t + 1, res / 10, res % 10);
  }
  return 0;
}
