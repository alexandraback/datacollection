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

using namespace std;

typedef unsigned uint;
typedef long long Int;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }
int in() { int x; scanf("%d", &x); return x; }

void solve() {
  int a, b, k;
  a = in();
  b = in();
  k = in();

  int A[40], B[40], K[40];
  for (int i = 0; i < 40; ++i) {
    A[i] = ((Int)a >> i) & 1;
    B[i] = ((Int)b >> i) & 1;
    K[i] = ((Int)k >> i) & 1;
  }
  reverse(A, A + 40);
  reverse(B, B + 40);
  reverse(K, K + 40);

  Int dp[50][2][2][2];
  memset(dp, 0, sizeof(dp));
  dp[0][0][0][0] = 1;

  for (int d = 0; d < 40; ++d) {
    for (int am = 0; am < 2; ++am) {
      for (int bm = 0; bm < 2; ++bm) {
        for (int km = 0; km < 2; ++km) {
          if (dp[d][am][bm][km] > 0) {
            int at = (am == 0 ? A[d] + 1 : 2);
            int bt = (bm == 0 ? B[d] + 1 : 2);
            for (int aa = 0; aa < at; ++aa) {
              for (int bb = 0; bb < bt; ++bb) {
                int kk = aa & bb;
                if (km == 0 && kk > K[d]) {
                  continue;
                }
                dp[d + 1][am | (aa < A[d])][bm | (bb < B[d])][km | (kk < K[d])] += dp[d][am][bm][km];
              }
            }
          }
        }
      }
    }
  }

  Int res = dp[40][1][1][1];

  printf("%lld\n", res);
}

int main()
{
  int T = in();

  for (int CN = 1; CN <= T; ++CN) {
    printf("Case #%d: ", CN);
    solve();
  }

  return 0;
}
