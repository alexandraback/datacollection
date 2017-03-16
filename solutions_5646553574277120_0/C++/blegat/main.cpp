#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <utility>
#include <stack>

using namespace std;

#define ABS(x) (((x) < 0) ? (-(x)) : (x))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define MAX(a,b) (((a) > (b)) ? (a) : (b))

int d[100];
bool ok[31];
bool used[30];

int C, D, V;
int BEST = V+1;

void best (int J, int cur) {
  if (cur >= BEST) return;
  bool allok = true;
  for (int i = 0; i <= V; i++) {
    if (!ok[i]) allok = false;
  }
  if (allok) BEST = MIN(cur, BEST);
  for (int j = J; j <= V; j++) {
    if (!used[j]) {
      used[j] = true;
      stack<int> s;
      for (int k = V-j; k >= 0; k--) {
        if (ok[k] && (!ok[k+j])) {
          ok[k+j] = true;
          s.push(k+j);
        }
      }
      best(j+1, cur+1);
      used[j] = false;
      while (!s.empty()) {
        int x = s.top();
        s.pop();
        ok[x] = false;
      }
    }
  }
}

int main (void) {
  int T;
  scanf("%d", &T);
  for (int currentcase = 1; currentcase <= T; ++currentcase) {
    scanf("%d %d %d\n", &C, &D, &V);
    fprintf(stderr,"%d\n", currentcase);
    fprintf(stderr,"%d %d %d\n", C, D, V);
    memset(ok, false, sizeof(bool) * 30);
    memset(used, false, sizeof(bool) * 30);
    ok[0] = true;
    for (int i = 0; i < D; i++) {
      scanf("%d\n", &(d[i]));
      for (int j = V-d[i]; j >= 0; j--) {
        if (ok[j]) ok[j+d[i]] = true;
      }
    }
    BEST=V+1;
    best(0,0);
    printf("Case #%d: %d\n", currentcase, BEST);
  }
  return 0;
}
