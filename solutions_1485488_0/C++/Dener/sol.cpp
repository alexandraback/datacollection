#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>

using namespace std;

const double inf = 1e100;
const double eps =  1e-7;
const int MAXTIME = 10000;
const int MAXN = 110;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

vector< vector< int > > c;
vector< vector< int > > f;
int n, m;
int H;

double D[MAXN][MAXN];

inline bool isGood(int x, int y)
{
  return x>=0 && y>=0 && x < n && y < m;
}

inline bool canGo(int x, int y, int nx, int ny)
{
  int wl = H;
  if (!(max(wl, max(f[x][y], f[nx][ny])) <= c[nx][ny] - 50))
    return false;
  if (!(f[nx][ny] + 50 <= c[x][y]))
    return false;
  return true;
}

inline void DFS(int x, int y)
{
  D[x][y] = 0;
  
  for (int i = 0; i < 4; i++)
  {
    int nx = x + dx[i];
    int ny = y + dy[i];
    
    if (!isGood(nx, ny))
      continue;
    if (D[nx][ny] == 0)
      continue;
    if (!canGo(x, y, nx, ny))
      continue;
    
    DFS(nx, ny);
  }
}

struct node
{
  int x, y;
  node (int _x, int _y)
  {
    x =_x;
    y =_y;
  }
};

inline bool operator<(const node &a, const node &b)
{
  double ta = D[a.x][a.y];
  double tb = D[b.x][b.y];
  
  if (ta != tb)
    return ta < tb;
  return make_pair(a.x, a.y) < make_pair(b.x, b.y);
}

set< node > S;

inline void solve(int testnumber)
{
  
  printf("Case #%d: ", testnumber+1);
  
  scanf("%d%d%d", &H, &n, &m);
  c.assign(n, vector<int>(m));
  f.assign(n, vector<int>(m));
  
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      scanf("%d", &c[i][j]);
  for (int i =0 ;i < n; i++)
    for (int j=0; j < m; j++)
      scanf("%d", &f[i][j]);
    
  for (int i =0 ; i < n; i++)
    for (int j = 0; j < m; j++)
      D[i][j] = inf;
      
  DFS(0, 0);
  S.clear();
  
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      S.insert(node(i, j));
    
  while (!S.empty())
  {
    node cur = *S.begin();
    S.erase(S.begin());
    int x = cur.x;
    int y = cur.y;
    double curt = D[x][y];
    
    for (int i =0 ; i<4; i++)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];
      
      if (!isGood(nx, ny))
	continue;
      
      if (f[x][y] > c[nx][ny] - 50)
	continue;
      if (f[nx][ny] > c[nx][ny] - 50)
	continue;
      if (f[nx][ny] + 50 > c[x][y])
	continue;
      double tneed = (H - c[nx][ny] + 50)*1.0 / 10;
      double tn = max(tneed, curt);
      
      double wl = H*1.0 - 10.0*tn;
      if (wl - eps > c[nx][ny] - 50)
	continue;
      
      if (wl + eps >= f[x][y] + 20)
	tn += 1;
      else
	tn += 10;
      
      if (tn < D[nx][ny])
      {
	S.erase(node(nx, ny));
	D[nx][ny] = tn;
	S.insert(node(nx, ny));
      }
    }
  }

  cout.precision(30);
  cout.setf(ios::fixed);
  cout << D[n-1][m-1] << endl;
};

int main()
{
  int testcount;
  scanf("%d\n", &testcount);
  
  for (int i = 0; i < testcount; i++)
  {
    solve(i);
  }
}