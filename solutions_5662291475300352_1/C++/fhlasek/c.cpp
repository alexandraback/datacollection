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
pair<int, int> hiker[MAXN];
int H;

int solve() {
  int best = max(0, H - 1);
  REP(i, H) {
    int turnarounds = 0;
    FOR(j, i + 1, H - 1) {
      int k = 2;
      while (k < H + 2 &&
              ((long long)(360     - hiker[i].second) * -hiker[i].first >=
              (long long)(360 * k - hiker[j].second) * -hiker[j].first)) k++;
      turnarounds += k - 2;
    }
    best = min(best, i + turnarounds);
  }
  return best;
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
      REP(j, h) hiker[H++] = make_pair(-(m + j), d);
    }
    sort(hiker, hiker + H);
    printf("Case #%d: %d\n", t, solve());
  }
  return 0;
}
