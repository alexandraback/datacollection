#include <assert.h>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <string>
#include <list>
#include <stack>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <utility>
#include <list>
#define INF 0x3fffffff
#define LINF 0x3fffffffffffffffll
#define DINF 1e100
#define EPS 0.000000000001

typedef long long ll;
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define PDD pair<double, double>
#define PIL pair<int, ll>
#define PLI pair<ll, int>
#define PID pair<int, double>
#define PDI pair<double, int>
#define PLD pair<ll, double>
#define PDL pair<double, ll>

#define NUL(x) memset(x, 0, sizeof(x))
#define MINUS(x) memset(x, 0xff, sizeof(x))
#define PQ(x) priority_queue< x >  //highest first
#define PQR(x) priority_queue< x , vector< x > , greater < x > > //lowest first
#define MP make_pair
#define PB push_back
#define IT(x) for (typeof((x).begin()) it = (x).begin() ; it != (x).end() ; it++)
#define IT2(x) for (typeof((x).begin()) it2 = (x).begin() ; it2 != (x).end() ; it2++)
#define FOR(i, a, b) for (int i = (a) ; i< (b) ; i++)
//#define DEB(x...) fprintf(stderr,x)
#define DEB

using namespace std;

int H,N,M;

#define MAX 105
int f[MAX][MAX];//[y][x], [N][M]
int c[MAX][MAX];
bool visit[MAX][MAX];
int dist[MAX][MAX];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0,  1, -1};

struct entry{
  int y;
  int x;
  int time;
  entry(int y_, int x_, int t_) : y(y_), x(x_), time(t_){;}
  bool operator<(const entry other) const {
    return time>other.time;
  }
};

inline int water(int time) {
  return max(0, H-time);
}

inline int watertotime(int water) {
  assert(water<=H);
  assert(water>=0);
  
  return H-water;
}

bool testc(int tc=0)
{
  scanf("%i %i %i ", &H, &N, &M);
  FOR(y,0,N) FOR(x,0,M) scanf("%i ", &c[y][x]);
  FOR(y,0,N) FOR(x,0,M) scanf("%i ", &f[y][x]);
  FOR(y,0,N) FOR(x,0,M) {
    visit[y][x] = false;
    dist[y][x] = INF;
  }

  // pre tide
  queue<entry> q;
  q.push(entry(0,0,0));
  visit[0][0]=true;

  while(!q.empty()) {
    entry cur = q.front();
    q.pop();
    DEB("Pre %i %i %i\n", cur.y, cur.x, cur.time);
    FOR(i,0,4) {
      entry nxt = entry(cur.y + dy[i], cur.x + dx[i], 0);
      if (nxt.x<0 || nxt.x>=M ||
          nxt.y<0 || nxt.y>=N ||
          visit[nxt.y][nxt.x]) continue;
      DEB("nxt %i %i H %i c %i f %i\n", nxt.y,nxt.x, H, c[nxt.y][nxt.x], f[nxt.y][nxt.x]);
      DEB("cur %i %i H %i c %i f %i\n", cur.y,cur.x, H, c[cur.y][cur.x],f[cur.y][cur.x]);
      if (c[nxt.y][nxt.x] < H + 50) continue;
      if (c[nxt.y][nxt.x] < f[cur.y][cur.x] + 50) continue;
      if (c[nxt.y][nxt.x] - f[nxt.y][nxt.x] < 50) continue;
      if (f[nxt.y][nxt.x] + 50 > c[cur.y][cur.x]) continue;
      visit[nxt.y][nxt.x]=true;
      q.push(nxt);
    }
  }

  PQ(entry) pq;
  
  FOR(y,0,N) FOR(x,0,M) if (visit[y][x]) {
    visit[y][x] = false;
    pq.push(entry(y,x,0));
    dist[y][x] = 0;
  }

  while(!pq.empty()) {
    entry cur = pq.top(); pq.pop();
    if (visit[cur.y][cur.x]) continue;
    visit[cur.y][cur.x] = true;

    int time = cur.time;

    if (cur.y == N-1 && cur.x == M-1) {
      printf("Case #%i: %lf\n", tc, time*1.0/10);
      return true;
    }
    FOR(i,0,4) {
      entry nxt = entry(cur.y + dy[i], cur.x + dx[i], 0);
      if (nxt.x<0 || nxt.x>=M ||
          nxt.y<0 || nxt.y>=N ||
          visit[nxt.y][nxt.x]) continue;

      DEB("nxt %i %i H %i c %i f %i\n", nxt.y,nxt.x, H, c[nxt.y][nxt.x], f[nxt.y][nxt.x]);
      DEB("cur %i %i H %i c %i f %i time %i\n", cur.y,cur.x, H, c[cur.y][cur.x],f[cur.y][cur.x], time);
      
      // Can never move?
      if (c[nxt.y][nxt.x] < f[cur.y][cur.x] + 50) continue;
      if (c[nxt.y][nxt.x] - f[nxt.y][nxt.x] < 50) continue;
      if (f[nxt.y][nxt.x] + 50 > c[cur.y][cur.x]) continue;

      DEB("Still here\n");
      
      // Cant move directly but later
      if (c[nxt.y][nxt.x] < water(time) + 50 && c[nxt.y][nxt.x] >= 50) {
        time = watertotime(c[nxt.y][nxt.x]-50);
        DEB("Not now but later: time=%i\n", time);
      } else {
        DEB("Direct\n");
      }
      assert(c[nxt.y][nxt.x] >= water(time) + 50);

      // fast move
      if (water(time) >= 20+f[cur.y][cur.x]) {
        DEB("fast move\n");
        if ( dist[nxt.y][nxt.x] > time+10) {
          dist[nxt.y][nxt.x] = time+10;
          nxt.time = dist[nxt.y][nxt.x];
          pq.push(nxt);
        }
      } else { // slow move
        DEB("slow move\n");
        if ( dist[nxt.y][nxt.x] > time+100) {
          dist[nxt.y][nxt.x] = time+100;
          nxt.time = dist[nxt.y][nxt.x];
          pq.push(nxt);
        }
      }
    }
  }

}


int main()
{
  int t;
  scanf("%i ",&t);
  FOR(i,0,t)
    testc(i+1);

  /*
    while(testc());
  */
  
  return 0;
}
