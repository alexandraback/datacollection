#include <assert.h>
#include <ctype.h>
#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <complex>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

#define SZ(a) (int)(a).size()
#define FOR(i,a,b) for (int i=(a); i<=(b); ++i)
#define REP(i,n) for (int i=0; i<(n); ++i)
#define ALL(c) c.begin(), c.end()
#define CLR(c,n) memset(c, n, sizeof(c))
#define CONTAIN(it, c) (c.find(it) != c.end())
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long long LL;
template <class T> void checkmin(T &a, T b) { if (b<a) a=b; }
template <class T> void checkmax(T &a, T b) { if (b>a) a=b; }

int main(int argc, char *argv[]) {
  int tc, n, x[1024];
  scanf("%d", &tc);
  FOR(t, 1, tc) {
    scanf("%d", &n);
    REP(i, n) scanf("%d", &x[i]);
    int mx = *max_element(x, x + n), best = mx;
    FOR(i, 1, mx) {
      int cnt = i;
      REP(j, n) cnt += (x[j] - 1) / i;
      checkmin(best, cnt);
    }
    printf("Case #%d: %d\n", t, best);
  }
}
