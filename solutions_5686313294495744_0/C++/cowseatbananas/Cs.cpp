#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (n); ++i)
#define REP(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;

int T, N;
string A[16], B[16];

int main() {
  cin >> T;
  REP (tc, T) {
    cin >> N;
    FOR (i, N) cin >> A[i] >> B[i];

    int best = 0;
    for (int m = 0; m < (1 << N); ++m) {
      set<string> gotA, gotB;
      FOR (i, N) if ((m >> i) & 1) {
        gotA.insert(A[i]);
        gotB.insert(B[i]);
      }

      bool ok = true;
      FOR (i, N)
        if (!(gotA.find(A[i]) != gotA.end() && gotB.find(B[i]) != gotB.end()))
          ok = false;

      if (ok) best = max(best, N - __builtin_popcount(m));
    }

    printf("Case #%d: %d\n", tc, best);
  }
  return 0;
}
