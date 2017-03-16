/* Written by Filip Hlasek 2015 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 555555
int hiker_turn[MAXN], hiker_start[MAXN], H;

int solve() {
  if (H < 2) return 0;
  if (hiker_turn[0] < hiker_turn[1]) {
    swap(hiker_turn[0], hiker_turn[1]);
    swap(hiker_start[0], hiker_start[1]);
  }
  // time_slow = (360 - hiker_start[0]) * hiker_turn[0]
  // time_fast = (720 - hiker_start[1]) * hiker_turn[1]
  return (long long)(360 - hiker_start[0]) * hiker_turn[0] >= (long long)(720 - hiker_start[1]) * hiker_turn[1];
}

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  FOR(t, 1, T) {
    H = 0;
    int N;
    scanf("%d", &N);
    REP(i, N) {
      int d, h, m;
      scanf("%d%d%d", &d, &h, &m);
      REP(j, h) { hiker_start[H] = d; hiker_turn[H++] = m + j; }
    }
    printf("Case #%d: %d\n", t, solve());
  }
  return 0;
}
