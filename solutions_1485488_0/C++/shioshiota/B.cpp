#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include<cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include<bitset>

#define REP(i,b,n) for(int i=b;i<(int)n;i++)
#define rep(i,n)   REP(i,0,n)
#define ALL(C)     (C).begin(),(C).end()
#define FOR(it,o)  for(__typeof((o).begin()) it=(o).begin(); it!=(o).end(); ++it)
#define dbg(x) cerr << #x << " = " << (x) << endl


typedef long long ll;

using namespace std;


const int N = 100, M = 100;

const int INF = (1<<29);


int cost[N][M], F[N][M], C[N][M];
bool visited[N][M];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

class State{
public:
  int y, x, cost;
  bool operator<(const State &s)const{
    return cost > s.cost;
  }
};


int dijkstra(int h, int n, int m){
  rep(i, N)rep(j, M){
    cost[i][j] = INF;
    visited[i][j] = false;
  }
  priority_queue<State> Q;
  Q.push((State){0, 0, 0});
  visited[0][0] = true;
  while(!Q.empty()){
    State now = Q.top();
    Q.pop();
    //dbg(now.y);
    //dbg( now.x);
    visited[now.y][now.x] = true;
    rep(d, 4){
      const int y = now.y + dy[d];
      const int x = now.x + dx[d];
      if(y >= n || x >= m || min(x, y) < 0)continue;
      if(visited[y][x])continue;
      if(C[now.y][now.x] - F[y][x] < 50)continue;
      if(C[y][x] - F[y][x] < 50)continue;
      if(C[y][x] - F[now.y][now.x] < 50)continue;
      int nextCost = 0;
      if(now.cost == 0 && C[y][x] - (h-now.cost) >= 50){//cost 0 
	nextCost = 0;
      }
      else{
	int nowCost = now.cost;
	if(C[y][x] - (h-nowCost) < 50){
	  nowCost = h-(C[y][x] - 50);
	}
	nowCost = max(now.cost, nowCost);
	if(h - nowCost - F[now.y][now.x] >= 20){// kayak
	  nextCost = nowCost + 10;
	}else{
	  nextCost = nowCost + 100;//walk
	}
      }
      if(cost[y][x] <= nextCost)continue;
      cost[y][x] = nextCost;
      Q.push((State){y, x, nextCost});
    }
  }
  return cost[n-1][m-1];
}




int main(){
  int T;
  cin >> T;
  rep(tc, T){
    printf("Case #%d: ",tc+1);
    int h, n, m;
    cin >> h >>n >> m;
    rep(i, n)rep(j, m)cin >> C[i][j];
    rep(i, n)rep(j, m)cin >> F[i][j];
    printf("%.7lf\n", dijkstra(h, n, m)/10.);
  }
  return 0;
}
