#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <cstring>
#include <algorithm>

using namespace std;

#ifdef DBG12
    #define dbg(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#else
    #define dbg(...)
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;

const int N = 110;
int n, k, m;
char keys[N];
char s[N];

int nextPref[N][26];
bool used[N][N][N];
int maxDP[N][N][N];
double meanDP[N][N][N];

int getPref(int pref, char nextChar) {
  dbg("getPref(%d %c)\n", pref, nextChar);
  int & res = nextPref[pref][nextChar - 'A'];
  if (res != -1) {
    return res;
  }
  for (res = pref + 1; res >= 1; --res) {
    if (strncmp(s, s + pref - res + 1, res - 1) == 0 && s[res - 1] == nextChar) {
      return res;
    }
  }
  return res = 0;
}

void calcDP(int len, int pref, int occur) {
  if (used[len][pref][occur]) {
    return;
  }
  used[len][pref][occur] = true;
  if (len == m) {
    dbg("len = %d, pref = %d, occur = %d\n", len, pref, occur);
    maxDP[len][pref][occur] = occur;
    meanDP[len][pref][occur] = occur;
    return;
  }

  int & curMax = maxDP[len][pref][occur];
  double & curMean = meanDP[len][pref][occur];
  curMax = 0;
  curMean = 0;
  for (int i = 0; i < n; ++i) {
    int nextPref = getPref(pref, keys[i]);
    int nextOccur = occur + (nextPref == k ? 1 : 0);
    calcDP(len + 1, nextPref, nextOccur);

    curMax = max(curMax, maxDP[len + 1][nextPref][nextOccur]);
    curMean += meanDP[len + 1][nextPref][nextOccur];
  }
  curMean /= (double)n;
  dbg("len = %d, pref = %d, occur = %d, maxDP = %d, meanDP = %.5f\n", len, pref, occur, curMax, curMean);
}

void solve() {
  assert(scanf("%d%d%d%s%s", &n, &k, &m, keys, s) == 5);

  dbg("%d %d %d %s %s\n", n, k, m, keys, s);
  memset(nextPref, 0xFF, sizeof(nextPref));
  memset(used, 0, sizeof(used));
  calcDP(0, 0, 0);
  printf("%.20f\n", maxDP[0][0][0] - meanDP[0][0][0]);
}

int main()
{
  int tt;
  assert(scanf("%d", &tt) == 1);
  for (int ii = 1; ii <= tt; ++ii) {
    printf("Case #%d: ", ii);
    solve();
  }

  return 0;
}

