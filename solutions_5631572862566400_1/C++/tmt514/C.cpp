// by tmt514
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
using namespace std;
typedef long long LL;

int cs=0;
int a[1005];
int circ[1005];
int used[1005];
int dist[1005];
int most[1005];

void go(int x) {
  if(dist[x]) return;
  if(!dist[a[x]]) go(a[x]);
  dist[x] = dist[a[x]]+1;
}

void solve() {
  ++cs;
  fprintf(stderr, "Case #%d: ", cs);
  printf("Case #%d: ", cs);

  
  int n;
  int best=0;
  scanf("%d", &n);
  for(int i=1;i<=n;i++) scanf("%d", &a[i]);
  
  memset(used, 0, sizeof(used));
  memset(dist, 0, sizeof(dist));
  memset(circ, 0, sizeof(circ));
  memset(most, 0, sizeof(most));
  
  for(int i=1;i<=n;i++) {
    if(!used[i]) {
      int x = i;
      while (used[x]==0) {
        used[x] = 1;
        x = a[x];
      }

      if (dist[x] > 0) {
        go(i);
        if (dist[x] == 2) best = max(best, dist[i]);
        continue;
      }

      circ[x] = 1;
      int j=1, y=0;
      for(j=1, y=a[x]; y!=x; y=a[y], ++j) circ[y]=1;
      dist[x] = j;
      for(y=a[x];y!=x;y=a[y]) dist[y] = j;
      best = max(best, j);

      go(i);
      if(j==2) {
        best = max(best, dist[i]);
      }
    }
  }
  for(int i=1;i<=n;i++) {
    int x = i;
    while(circ[x]==0) x = a[x];
    most[x] = max(most[x], dist[i] - dist[x]);
  }

  int total = 0;
  for(int i=1;i<=n;i++) {
    if(a[a[i]] == i) {
      total += dist[i] + most[i] + most[a[i]];
    }
  }
  total /= 2;
  best = max(best, total);

  printf("%d\n", best);
  fprintf(stderr, "%d\n", best);
}


int main(void) {
  int T;
  scanf("%d", &T);
  while(T--) solve();  
  return 0;
}
