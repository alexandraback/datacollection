#define _CRT_SECURE_NO_DEPRECATE
#include <iostream> 
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <math.h>
#include <stack>
#include <deque>
#include <numeric>
#define all(x) x.begin(),x.end()
#define mpair make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
const ld epsylon = 1e-9;
vector<vector<int> > lo;
vector<vector<int> > hi;
ld h;
int move[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
/*
The water level, the floor height of your current square, 
and the floor height of the adjacent square must all be at least 50 centimeters
lower than the ceiling height of the adjacent square. 
Note: this means that you will never be able to enter a square with less than 50 centimeters 
between the floor and the ceiling.

The floor height of the adjacent square must be at least 50 centimeters 
below the ceiling height of your current square as well.
You can never move off the edge of the map.
*/
bool can(ld lo1, ld hi1, ld lo2, ld hi2, ld h) {
  ld lm = hi2 - 50.0 + epsylon;
  if (h > lm || lo1 > lm || lo2 > lm) {
    return false;
  }
  if (lo2 > hi1 - 50 + epsylon) {
    return false;
  }
  return true;
}
ld get_min_time(ld lo1, ld hi1, ld lo2, ld hi2, ld t) {
  ld beg = 0.0;
  ld end = 2000.0;
  for (int i = 0; i < 100; ++i) {
    ld mid = (end + beg)*0.5;
    ld th = h - (t + mid)* 10.0;
    if (can(lo1, hi1, lo2, hi2, th)) {
      end = mid;
    } else {
      beg = mid;
    }
  }
  if (h - (t + beg) * 10.0 > lo1 + 20.0 - epsylon) {
    return beg + 1.0;
  } else if (beg < 1500){
    return beg + 10.0;
  } else {
    return -1.0;
  }
}
ld solve() {
  int n = (int)lo.size();
  int m = (int)lo[0].size();
  vector<vector<ld> > dist(n, vector<ld>(m, -1.0));
  vector<vector<char> > vis(n, vector<char>(m, 0));
  dist[0][0] = 0.0;
  priority_queue<pair<ld, pair<int, int> > >  tc;
  tc.push(mpair(0.0, mpair(0,0)));
  vector<vector<vector<pair<int, int> > > > ne(n);
  for (int i=0;i<n;++i){
    ne[i].resize(m);
  }
  for (int i =0;i<n;++i){
    for (int j=0;j<m;++j) {
      for (int l = 0; l <4 ;++l){
        int ti = i + move[l][0];
        int tj = j + move[l][1];
        if (ti < 0 || ti >= n || tj < 0 || tj >= m) {
          continue;
        }
        if (can(lo[i][j], hi[i][j], lo[ti][tj], hi[ti][tj], h)){
          ne[i][j].push_back(mpair(ti,tj));
        }
      }
    }
  }
  vector<vector<char> > v(n, vector<char>(m, 0));
  queue<pair<int, int> > q;
  q.push(mpair(0,0));
  v[0][0] = true;
  vector<pair<int, int> > pp;
  while (!q.empty()) {
    pair<int,int> c = q.front();q.pop();
    int x = c.first;
    int y = c.second;
    for (int i=0;i<(int)ne[x][y].size();++i){
      int tx = ne[x][y][i].first;
      int ty =ne[x][y][i].second;
      if (v[tx][ty] == 0) {
        q.push(mpair(tx,ty));
        v[tx][ty] = 1;
        pp.push_back(mpair(tx,ty));
      }
    }
   }
  for (int i =0;i<pp.size();++i){
    int x = pp[i].first;
    int y = pp[i].second;
    dist[x][y] = 0.0;
    tc.push(mpair(dist[x][y], mpair(x,y)));
  }
  while (!tc.empty()) {
    pair<ld, pair<int, int> > c = tc.top(); tc.pop();
    int x = c.second.first;
    int y = c.second.second;
    if (vis[x][y]) {
      continue;
    }
    ld d = -c.first;
    vis[x][y] = 1;
    for (int l = 0; l < 4; ++l) {
      int tx = x + move[l][0];
      int ty = y + move[l][1];
      if (tx < 0 || tx >= n || ty < 0 || ty >= m) {
        continue;
      }
      if (vis[tx][ty]) {
        continue;
      }
      ld temp = get_min_time(lo[x][y], hi[x][y], lo[tx][ty], hi[tx][ty], d);
      if (temp < 0) {
        continue;
      }
      if (dist[tx][ty] < 0 || temp + d < dist[tx][ty]) {
        dist[tx][ty] = temp + d;
        tc.push(mpair(-dist[tx][ty], mpair(tx,ty)));
      }
    }
  }
  return dist[n-1][m-1];
}
int main()
{
  freopen("google.in","r",stdin);
  freopen("google.out","w",stdout);
  int nt;
  cin>>nt;
  for(int it=1;it<=nt;it++)
  {
    lo.clear();
    hi.clear();
    int H,n,m;
    cin >> H >> n >> m;
    h = H;
    hi.resize(n);
    for (int j=0;j<n;++j) hi[j].resize(m);
    lo.resize(n);
    for (int j=0;j<n;++j) lo[j].resize(m);
    for (int i =0; i<n;++i){
      for (int j=0;j<m;++j){
        scanf("%d",&hi[i][j]);
      }
    }
    for (int i =0; i<n;++i){
      for (int j=0;j<m;++j){
        scanf("%d",&lo[i][j]);
      }
    }
    cout<<"Case #"<<it<<": ";
    printf("%.7llf\n", solve());
  }
  return 0;
}
