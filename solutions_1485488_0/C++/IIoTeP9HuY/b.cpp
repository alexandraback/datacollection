#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <cassert>
#include <math.h>
#include <vector>
#include <time.h>
#include <set>
#include <queue>
#define REP(i,n) for(int i=0, _n=(n); i<_n; i++)
#define REPD(i,n) for(int i=n-1; i>=0; i--)
#define FOR(i,a,b) for(int i=a,_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=a,_b=(b); i>=_b; i--)
#define FILL(x, v) memset(&x,v,sizeof(x))
#define DB(x) cout << #x << ": " << x << endl;
#define x first
#define y second
#define mp make_pair
#define pb push_back

using namespace std;

typedef pair<int, int> pii;
typedef long long LL;

const int MAXN = 100;
const int MAXM = 100;
const int MAXK = 100;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, m, h;
vector< vector<int> > c;
vector< vector<int> > f;
vector< vector<double> > dist;

void readInput()
{
  scanf("%d%d%d", &h, &n, &m);
  f.resize(n);
  REP(i, n)
  {
    f[i].resize(m);
    REP(j, m)
    {
      scanf("%d", &f[i][j]);
    }
  }
  c.resize(n);
  REP(i, n)
  {
    c[i].resize(m);
    REP(j, m)
    {
      scanf("%d", &c[i][j]);
    }
  }
  dist.resize(n);
  REP(i, n)
    dist[i].assign(m, 1000000000.0);
  dist[0][0] = 0.0;
}

bool isValid(int x, int y)
{
  if (x < 0 || y < 0)
    return 0;
  if (x >= n || y >= m)
    return 0;
  return 1;
}

bool canMove(int x, int y, int nx, int ny)
{
  if (f[nx][ny] - c[x][y] < 50)
    return 0;
  if (f[x][y] - c[nx][ny] < 50)
    return 0;
  if (f[nx][ny] - c[nx][ny] < 50)
    return 0;
  return 1;
}

bool canMove1(int x, int y, int nx, int ny, double h)
{
  if (f[nx][ny] - c[x][y] < 50)
    return 0;
  if (f[x][y] - c[nx][ny] < 50)
    return 0;
  if (f[nx][ny] - c[nx][ny] < 50)
    return 0;
  if (f[nx][ny] - h < 50)
    return 0;
  return 1;
}

double speed(int x, int y, double curh)
{
  if (curh - c[x][y] >= 20)
    return 1.0;
  return 10.0;
}

void bfs()
{
  queue< pair<int, int> > Q;
  Q.push(mp(0, 0));
  while (!Q.empty())
  {
    pair<int, int> cur = Q.front();
    Q.pop();
    int x = cur.x;
    int y = cur.y;
    for(int k = 0; k < 4; k++)
    {
      int nx = x + dx[k];
      int ny = y + dy[k];
      if (!isValid(nx, ny))
        continue;
      if (!canMove(x, y, nx, ny))
        continue;
      if (!canMove1(x, y, nx, ny, h))
        continue;
      if (dist[x][y] + 0 < dist[nx][ny])
      {
        dist[nx][ny] = dist[x][y] + 0;
        Q.push(mp(nx, ny));
      }
    }
  }
}

double getTime(int x, int y, int nx, int ny, double h)
{
  if (f[nx][ny] - h >= 50)
    return 0.0;
  return (50.0 - f[nx][ny] + h) / 10.0;
}

void dijkstra()
{
  priority_queue< pair<double, pair<int, int> > > Q;
  REP(nx, n)
  {
    REP(ny, m)
    {
      if (dist[nx][ny] < 1000000)
      {
        Q.push(mp(-dist[nx][ny], mp(nx, ny)));
      }
    }
  }
  while (!Q.empty())
  {
    pair<double, pair<int, int> > cur = Q.top();
    Q.pop();
    double t = -cur.x;
    int x = cur.y.x;
    int y = cur.y.y;
    for(int k = 0; k < 4; k++)
    {
      int nx = x + dx[k];
      int ny = y + dy[k];
      if (!isValid(nx, ny))
        continue;
      if (!canMove(x, y, nx, ny))
        continue;
      double nt = t + max(getTime(x, y, nx, ny, h - t*10), 0.0);
      nt += speed(x, y, h - nt * 10);
      if (nt < dist[nx][ny])
      {
        dist[nx][ny] = nt;
        Q.push(mp(-dist[nx][ny], mp(nx, ny)));
      }
    }
  }
}

double solve()
{
  bfs();
  dijkstra();
  return dist[n - 1][m - 1];
}

void writeOutput(int t, double ans)
{
  printf("Case #%d: ", t);
  printf("%.9lf", ans);
  printf("\n");
}

int main()
{
	freopen("input.txt","r", stdin); 
  freopen("output.txt","w", stdout);
  size_t t1 = clock();

  int T;
  scanf("%d", &T);
  for(int t = 1; t <= T; t++)
  {
    readInput();
    double ans = solve();
    writeOutput(t, ans);
  }

  size_t t2 = clock();
  //fprintf(stderr, "Execution time: ", double(t2 - t1) / CLOCKS_PER_SEC);
	return 0;
}
