#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define PRINT(format, args...) do { fprintf(stdout, format, ## args); fflush(stdout); } while (0)

#define SIZE(__c) (int)(__c).size()
#define FOREACH(__i, __c) for (typeof(__c.begin()) __i=__c.begin(); __i!=__c.end(); ++__i)

typedef signed long long int i64;

const int INF=0x20202020;
const int DY[4]={-1, 0, 1, 0};
const int DX[4]={0, 1, 0, -1};

struct QueueItem {
  int y, x, d;
  QueueItem(int y, int x, int d): y(y), x(x), d(d) {}
  bool operator<(const QueueItem &qi) const { return d>qi.d; }
};

int W, Y, X;
int cl[128][128];
int fr[128][128];
int dt[128][128];

bool in_bounds(int y, int x) {
  return 0<=y && y<Y && 0<=x && x<X;
}

int go_time(int ys, int xs, int yt, int xt) {
  if (fr[ys][xs]>cl[yt][xt]-50)
    return INF;
  if (fr[yt][xt]>cl[yt][xt]-50)
    return INF;
  if (fr[yt][xt]>cl[ys][xs]-50)
    return INF;
  if (W<=cl[yt][xt]-50)
    return 0;
  return W-(cl[yt][xt]-50);
}

int main() {
  int t, T;
  scanf("%d", &T);
  for (t=1; t<=T; t++) {
    int i, j, ny, nx, d;
    scanf("%d %d %d", &W, &Y, &X);
    for (i=0; i<Y; i++)
      for (j=0; j<X; j++)
        scanf("%d", &cl[i][j]);
    for (i=0; i<Y; i++)
      for (j=0; j<X; j++)
        scanf("%d", &fr[i][j]);
    memset(dt, ' ', sizeof dt);
    dt[0][0]=0;
    queue<QueueItem> qe;
    priority_queue<QueueItem> pq;
    qe.push(QueueItem(0, 0, 0));
    pq.push(QueueItem(0, 0, 0));
    while (!qe.empty()) {
      QueueItem qi=qe.front();
      qe.pop();
      for (i=0; i<4; i++) {
        ny=qi.y+DY[i];
        nx=qi.x+DX[i];
        if (in_bounds(ny, nx) && dt[ny][nx]==INF && go_time(qi.y, qi.x, ny, nx)==0) {
          dt[ny][nx]=0;
          qe.push(QueueItem(ny, nx, 0));
          pq.push(QueueItem(ny, nx, 0));
        }
      }
    }
    while (!pq.empty()) {
      QueueItem qi=pq.top();
      pq.pop();
      if (qi.d!=dt[qi.y][qi.x])
        continue;
      for (i=0; i<4; i++) {
        ny=qi.y+DY[i];
        nx=qi.x+DX[i];
        if (in_bounds(ny, nx)) {
          d=max(qi.d, go_time(qi.y, qi.x, ny, nx));
          d+=(W-d>=fr[qi.y][qi.x]+20 ? 10 : 100);
          if (d<dt[ny][nx]) {
            dt[ny][nx]=d;
            pq.push(QueueItem(ny, nx, d));
          }
        }
      }
    }
    PRINT("Case #%d: %d.%d\n", t, dt[Y-1][X-1]/10, dt[Y-1][X-1]%10);
  }
  return 0;
}
