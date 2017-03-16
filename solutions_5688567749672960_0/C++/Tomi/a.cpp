#include <cstdio>
#include <vector>
#include <set>
#include <queue>
using namespace std;

#define MAXN 1100000
int dist[MAXN];

int rev(int r) {
  int rv = 0;
  while (r) {
    rv *= 10;
    rv += (r % 10);
    r /= 10;
  }
  return rv;
}

int main() {
  queue<int> Q;
  Q.push(1);
  dist[1] = 1;

  while (!Q.empty()) {
    int r = Q.front(); Q.pop();
//    fprintf(stderr, "%d\n", r);

    int r1 = r + 1;
    int r2 = rev(r);

    if (r1 < MAXN && !dist[r1]) dist[r1] = dist[r]+1, Q.push(r1);
    if (r2 < MAXN && !dist[r2]) dist[r2] = dist[r]+1, Q.push(r2);
  }

  for (int i = 0; i < 100; i++) fprintf(stderr, "dist[%d] = %d\n", i, dist[i]);

  int T;
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    int N;
    scanf("%d", &N);
    printf("Case #%d: %d\n", tc, dist[N]);
  }
}
