#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <array>
#include <list>
#include <stack>
#include <valarray>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef unsigned long long UInt;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }
int in() { int x; scanf("%d", &x); return x; }
double fin() { double x; scanf("%lf", &x); return x; }
Int lin() { Int x; scanf("%lld", &x); return x; }

void check(int n, Int& AC, Int& AJ, Int tc[20], Int tj[20]) {
  Int c = 0, j = 0;
  for (int i = 0; i < n; ++i) {
    c = c * 10 + tc[i];
    j = j * 10 + tj[i];
  }
  Int D = llabs(AC - AJ);
  Int d = llabs(c - j);
  if (D > d || (D == d && AC > c) || (D == d && AC == c && AJ > j)) {
    AC = c;
    AJ = j;
  }
}

void solve() {
  char CS[20], JS[20];
  scanf("%s%s", CS, JS);

  int N = strlen(CS);
  Int AC = INFLL, AJ = 0;

  Int cs[2][20][4], js[2][20][4];
  for (int i = 0; i < N; ++i) {
    for (int p = 0; p < 4; ++p) {
      cs[0][i][p] = js[0][i][p] = -1;
      cs[1][i][p] = js[1][i][p] = -1;
      for (int di = 0; di <= 9; ++di) {
        if (CS[i] != '?' && CS[i] - '0' != di) {
          continue;
        }
        for (int dj = 0; dj <= 9; ++dj) {
          if (JS[i] != '?' && JS[i] - '0' != dj) {
            continue;
          }
          bool ok = true;
          if (p == 0) ok &= di >= dj;
          if (p == 1) ok &= di > dj;
          if (p == 2) ok &= di < dj;
          if (p == 3) ok &= di <= dj;
          if (!ok) {
            continue;
          }
          bool upd = false;
          upd |= cs[0][i][p] == -1;
          if (!upd) upd |= cs[0][i][p] - js[0][i][p] > di - dj;
          if (!upd) upd |= cs[0][i][p] - js[0][i][p] == di - dj && cs[0][i][p] > di;
          if (upd) {
            cs[0][i][p] = di;
            js[0][i][p] = dj;
          }
          upd = false;
          upd |= cs[1][i][p] == -1;
          if (!upd) upd |= cs[1][i][p] - js[1][i][p] < di - dj;
          if (!upd) upd |= cs[1][i][p] - js[1][i][p] == di - dj && cs[1][i][p] > di;
          if (upd) {
            cs[1][i][p] = di;
            js[1][i][p] = dj;
          }
        }
      }
    }
  }

  for (int p = 0; p < (1 << N); ++p) {
    Int tc[20], tj[20];
    bool ok = true;
    for (int i = N - 1; i >= 0; --i) {
      int cp = (((p >> i) & 1) << 1) | ((p >> (i+1)) & 1);
      ok &= (tc[i] = cs[p & 1][i][cp]) != -1;
      ok &= (tj[i] = js[p & 1][i][cp]) != -1;
    }
    if (ok) {
      check(N, AC, AJ, tc, tj);
    }
  }

  printf("%0*lld %0*lld\n", N, AC, N, AJ);
}

int main() {
  int T = in();

  for (int CN = 1; CN <= T; ++CN) {
    printf("Case #%d: ", CN);
    solve();
  }

  return 0;
}
