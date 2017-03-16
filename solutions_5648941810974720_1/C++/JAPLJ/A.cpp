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

const char *DS[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

void solve() {
  char S[2048];
  scanf("%s", S);

  int A[26] = {};
  int R[10] = {};
  for (int i = 0; S[i]; ++i) {
    ++A[S[i] - 'A'];
  }

  int u = 0;
  for (int tr = 0; tr < 10; ++tr) {
    for (int d = 0; d < 10; ++d) {
      bool ok = false;
      int uniq = -1, cnts = 0;
      if (u & (1 << d)) {
        continue;
      }
      for (int i = 0; DS[d][i]; ++i) {
        bool okc = true;
        for (int e = 0; e < 10; ++e) {
          if (d == e || (u & (1 << e))) {
            continue;
          }
          for (int j = 0; DS[e][j]; ++j) {
            okc &= DS[d][i] != DS[e][j];
          }
        }
        if (okc) {
          ok = true;
          uniq = DS[d][i] - 'A';
          for (int j = 0; DS[d][j]; ++j) {
            if (DS[d][i] == DS[d][j]) {
              ++cnts;
            }
          }
          break;
        }
      }
      if (ok) {
        u |= 1 << d;
        R[d] = A[uniq] / cnts;
        for (int i = 0; i < DS[d][i]; ++i) {
          A[DS[d][i] - 'A'] -= R[d];
        }
      }
    }
  }

  for (int d = 0; d < 10; ++d) {
    for (int i = 0; i < R[d]; ++i) {
      putchar('0' + d);
    }
  }
  puts("");
}

int main() {
  int T = in();

  for (int CN = 1; CN <= T; ++CN) {
    printf("Case #%d: ", CN);
    solve();
  }

  return 0;
}
