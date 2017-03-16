/* Written by Filip Hlasek 2016 */
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
#include <iostream>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 111111
map<string, int> wmap;
int W;
int N;
int A[MAXN], B[MAXN];

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  FOR(t, 1, T) {
    W = 0;
    wmap.clear();
    scanf("%d", &N);
    REP(i, N) {
      string a, b;
      cin >> a >> b;
      if (!wmap.count(a)) wmap[a] = W++;
      if (!wmap.count(b)) wmap[b] = W++;
      A[i] = wmap[a]; B[i] = wmap[b];
    }
    int ans = 0;
    REP(mask, (1 << N)) {
      bool ok = true;
      int cnt = 0;
      REP(i, N) if (mask & (1 << i)) {
        ++cnt;
        bool ok_a = false, ok_b = false;
        REP(j, N) if (!(mask & (1 << j))) {
          if (A[j] == A[i]) ok_a = true;
          if (B[j] == B[i]) ok_b = true;
        }
        if (!ok_a || !ok_b) {
          ok = false;
          break;
        }
      }
      if (ok) ans = max(ans, cnt);
    }
    printf("Case #%d: %d\n", t, ans);
  }
  return 0;
}
