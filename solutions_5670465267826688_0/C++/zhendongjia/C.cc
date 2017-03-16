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

int l, x;
char s[10240];
int f[5][5] = {
  { 0, 0, 0, 0, 0 },
  { 0, 1, 2, 3, 4 },
  { 0, 2, -1, 4, -3},
  { 0, 3, -4, -1, 2},
  { 0, 4, 3, -2, -1}
};

int go(int a, int b) {
  int x = f[abs(a)][abs(b)];
  if (a < 0) x = -x;
  if (b < 0) x = -x;
  return x;
}

bool check(void) {
  int p = 1;
  REP(i, l) p = go(p, s[i]);
  int np = 1;
  REP(i, x) np = go(np, p);
  if (np != -1) return false;
  int target = 2;
  checkmin(x, 16);
  p = 1;
  REP(j, x) REP(i, l) {
    p = go(p, s[i]);
    if (p == target) {
      ++target;
      p = 1;
    }
  }
  return target > 3;
}

int main(int argc, char *argv[]) {
  int tc;
  scanf("%d", &tc);
  FOR(t, 1, tc) {
    scanf("%d %d %s", &l, &x, s);
    REP(i, l) s[i] = (s[i] == '1' ? 1 : s[i] - 'g');
    printf("Case #%d: %s\n", t, check() ? "YES" : "NO");
  }
}
