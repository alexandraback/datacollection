#include <stdio.h>
#include <queue>
#include <utility>
using namespace std;

#define FOR(q,n) for(int q=0; q<n; q++)

int n,m,h;
#define MAX 110
#define INF 1000000000
int floor[MAX][MAX];
int ceil[MAX][MAX];
int best[MAX][MAX];
queue<int> fronta;
typedef pair<int,int> PII;
typedef pair<int, PII> PIII;
#define fi first
#define se second
#define mp make_pair

priority_queue<PIII> halda;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int can_go(int x,int y, int nx, int ny) {
    if (nx < 0 || nx >= n) return INF;
    if (ny < 0 || ny >= m) return INF;
    if (ceil[nx][ny] - floor[nx][ny] < 50) return INF;
    if (ceil[nx][ny] - floor[x][y] < 50) return INF;
    if (ceil[x][y] - floor[nx][ny] < 50) return INF;

    int maxh = ceil[nx][ny] - 50;
    if (maxh >=h ) return 0; // we can go instantly
    return h - maxh; // we can go later
}

void initial() {
  best[0][0] = 0;

  fronta.push(0);
  fronta.push(0);
  while (!fronta.empty()) {
    int x = fronta.front(); fronta.pop();
    int y = fronta.front(); fronta.pop();
    FOR(smer, 4) {
      int nx = x + dx[smer];
      int ny = y + dy[smer];
      if (can_go(x, y, nx, ny) != 0) continue;

      if (best[nx][ny] == 0) continue;
      fronta.push(nx);
      fronta.push(ny);
      best[nx][ny] = 0;
    }

  }

}

void dijkstra() {
  FOR(q, n)
    FOR(w, m)
      if (best[q][w] == 0)
          halda.push(mp(0, mp(q,w)));

  while (!halda.empty()) {
    PIII top = halda.top(); halda.pop();
    int t = -top.fi;
    int x = top.se.fi;
    int y = top.se.se;
//    printf("%d %d %d\n", t, x, y);
    if (best[x][y] < t) continue; // stale
    FOR(smer, 4) {
      int nx = x + dx[smer];
      int ny = y + dy[smer];
      int wait = can_go(x, y, nx, ny);
//      printf("can go %d %d -- wait %d\n", nx,ny, wait);
      if (wait == INF) continue;
      if (wait < t) wait = t;
      int nt = wait + ((h - wait >= floor[x][y] + 20) ? 10: 100);
//      printf("new time: %d\n", nt);
      if (best[nx][ny] > nt) {
        best[nx][ny] = nt;
        halda.push(mp(-nt ,mp(nx, ny)));
      }

    }
  }
}

void solve(int _case) {
  scanf("%d %d %d", &h, &n, &m);
  FOR(q, n)
    FOR(w, m)
      scanf("%d", &ceil[q][w]);

  FOR(q,n)
    FOR(w,m)
      scanf("%d", &floor[q][w]);

  FOR(q, n)
    FOR(w, m)
      best[q][w] = INF;

  initial();
  dijkstra();
  printf("Case #%d: %d.%d\n",_case, best[n-1][m-1]/10, best[n-1][m-1]%10);

}


int main() {
  int t;
  scanf("%d", &t);
  FOR(q, t) solve(q+1);
}
