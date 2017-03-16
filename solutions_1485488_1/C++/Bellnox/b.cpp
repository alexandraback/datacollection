#include <iostream>
#include <map>
#include <set>
#include <stdio.h>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <memory.h>
#include <math.h>
using namespace std;

typedef long long LL;
typedef unsigned int UI;
typedef pair<int, int> PP;

struct node
{
  double f, c;
  double t;
};

node a[128][128];
double h;
int n, m;
set<PP> q;

double wait(const node& f, const node& t)
{
  if(min(t.c - f.f, f.c - t.f) < 50 - 1e-8 || t.c - t.f < 50 - 1e-8)
    return 1e10;
  double w = 0;
  if(t.c - h + 10.0 * f.t < 50 - 1e-8)
    w = (50 - t.c + h - 10.0 * f.t) / 10.0;
  if(fabs(f.t) < 1e-8 && fabs(w) < 1e-8)
    return 0;
  if(h - 10 * (f.t + w) - f.f > 20 - 1e-8)
    return w + 1;
  return w + 10;
}

int main() 
{
  freopen("ib.txt", "r", stdin);
  freopen("ob.txt", "w", stdout);
  int t;
  cin >> t;
  for(int tt = 0; tt < t; tt++)
  {
    cin >> h >> n >> m;
    q.clear();
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < m; j++)
      {
	q.insert(PP(i, j));
	a[i][j].t = 1e10;
	cin >> a[i][j].c;
      }
    }
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < m; j++)
      {
	cin >> a[i][j].f;
      }
    }
    a[0][0].t = 0;
    while(!q.empty())
    {
      PP b = PP(-1, -1);
      for(set<PP>::iterator it = q.begin(); it != q.end(); it++)
      {
	if(b.first == -1 || a[b.first][b.second].t > a[it->first][it->second].t)
	  b = *it;
      }
      q.erase(b);
      node& nd = a[b.first][b.second];
      if(b.first > 0)
      {
	a[b.first - 1][b.second].t = min(a[b.first - 1][b.second].t, nd.t + wait(nd, a[b.first - 1][b.second]));
      }
      if(b.first < n - 1)
      {
	a[b.first + 1][b.second].t = min(a[b.first + 1][b.second].t, nd.t + wait(nd, a[b.first + 1][b.second]));
      }
      if(b.second > 0)
      {
	a[b.first][b.second - 1].t = min(a[b.first][b.second - 1].t, nd.t + wait(nd, a[b.first][b.second - 1]));
      }
      if(b.second < m - 1)
      {
	a[b.first][b.second + 1].t = min(a[b.first][b.second + 1].t, nd.t + wait(nd, a[b.first][b.second + 1]));
      }
    }
    printf("Case #%d: %.7lf\n", tt + 1, a[n - 1][m - 1].t);
  }
  return 0;
}
