#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long li;
typedef pair<li, li> pi;
typedef vector<li> vi;
typedef vector<string> vs;

inline li bit(li n){ return 1LL<<n; }

#define rep(i,to)       for(li i=0;i<((li)to);i++)
#define foreach(it,set) for(__typeof((set).begin()) it=(set).begin();it!=(set).end();it++)
#define all(v)          v.begin(), v.end()

const double DOUBLE_MAX = 1e300;

li vx[4] = {1, 0, -1, 0};
li vy[4] = {0, 1, 0, -1};

void solve(li casenum){
  li wl, w, h;
  cin >> wl >> h >> w;
  li ceil[105][105], floor[105][105];
  rep(i, h) rep(j, w) cin >> ceil[i][j];
  rep(i, h) rep(j, w) cin >> floor[i][j];

  double dp[105][105];
  bool bvis[105][105];
  rep(i, h) rep(j, w){
    dp[i][j] = DOUBLE_MAX;
    bvis[i][j] = false;
  }

  priority_queue<pair<double, pi> > q;

  queue<pi> bfs;
  bfs.push(make_pair(0,0));
  while(!bfs.empty()){
    li i = bfs.front().first, j = bfs.front().second; bfs.pop();
    if(bvis[i][j]) continue;
    bvis[i][j] = true;

    q.push(make_pair(0.0, make_pair(i,j)));
    // cout << "b " << i << " " << j << endl;

    rep(d,4){
      li ni = i+vx[d], nj = j+vy[d];
      if(ni<0 || h<=ni || nj<0 || w<=nj) continue;
      if(floor[i][j]   + 50 > ceil[ni][nj]) continue;
      if(floor[ni][nj] + 50 > ceil[ni][nj]) continue;
      if(wl            + 50 > ceil[ni][nj]) continue;
      if(floor[ni][nj] + 50 > ceil[i][j]) continue;

      bfs.push(make_pair(ni, nj));
    }
  }

  while(!q.empty()){
    pair<double, pi> top = q.top(); q.pop();
    double time = top.first;
    li i = top.second.first, j = top.second.second;

    // cout << time << " " << i << " " << j << endl;
    if(dp[i][j] <= time) continue;
    dp[i][j] = time;

    rep(d,4){
      li ni = i+vx[d], nj = j+vy[d];
      if(ni<0 || h<=ni || nj<0 || w<=nj) continue;
      if(floor[i][j]   + 50 > ceil[ni][nj]) continue;
      if(floor[ni][nj] + 50 > ceil[ni][nj]) continue;
      if(floor[ni][nj] + 50 > ceil[i][j]) continue;
      double water = wl - time * 10.0, ntime = time;

      if(water + 50 > ceil[ni][nj]){
        double wait = (water + 50 - ceil[ni][nj]) / 10.0;
        water = ceil[ni][nj] - 50;
        ntime = time + wait;
      }

      if(water >= floor[i][j] + 20){
        // 1 sec
        ntime += 1;
      } else {
        // 10 sec
        ntime += 10;
      }

      if(ntime < DOUBLE_MAX) q.push(make_pair(ntime, make_pair(ni,nj)));
    }
  }

  printf("Case #%lld: %.09f\n", casenum, dp[h-1][w-1]);
  return;
}

int main(){
  li t;
  cin >> t;
  rep(i, t) solve(i+1);

  return 0;
}
