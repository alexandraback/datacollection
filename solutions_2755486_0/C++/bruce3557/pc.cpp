#include <stdio.h>
#include <string.h>
#include <queue>

using std::priority_queue;

struct node {
  int d, n, w, e, s;
  int dd, dp, ds;

  void get() {
    scanf("%d%d%d%d%d%d%d%d", &d, &n, &w, &e, &s, &dd, &dp, &ds);
  }

  bool operator < (const node &t) const {
    return d > t.d;
  }

  void nextRound() {
    d += dd;
    e += dp;
    w += dp;
    s += ds;
    --n;
  }
} tribe[20];

int N;

int mid;
int wall[1010];
int max_wall[1010];

void Update() {
  for(int i=0;i<=1000;++i)
    if(max_wall[i] > wall[i])
      wall[i] = max_wall[i];
}

int main() {
  int t, kas=0;

  mid = 500;

  scanf("%d", &t);
  while(t--) {
    scanf("%d", &N);
    for(int i=0;i<N;++i)
      tribe[i].get();
    memset(wall, 0, sizeof(wall));
    memset(max_wall, 0, sizeof(max_wall));

    int *W = &wall[500];
    int *MW = &max_wall[500];
    priority_queue< node > PQ;
    for(int i=0;i<N;++i)
      PQ.push(tribe[i]);
    
    int count = 0;
    int pr = -1;
    while( !PQ.empty() ) {
      node tp = PQ.top();
      PQ.pop();
      if(pr != tp.d)  Update();
      
      bool suc = false;
      for(int i=tp.w;i<tp.e;++i) {
        if(W[i] < tp.s) {
          suc = true;
          MW[i] = MW[i] > tp.s ? MW[i] : tp.s;
        }
      }
      if(suc) ++count;
      pr = tp.d;
      tp.nextRound();
      if(tp.n > 0)  PQ.push(tp);
    }
    printf("Case #%d: %d\n", ++kas, count);
  }

  return 0;
}

