#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

// TEMPLATE {{{
#ifdef ONLINE_JUDGE
#define OJ 1
#else
#define OJ 0
#endif

#define endl '\n'
//#define TIMESTAMP fprintf(stderr, "Execution time: %.3lf s.\n", (double)clock()/CLOCKS_PER_SEC)
#define TIMESTAMP merr << "Execution time: " << (double)clock()/CLOCKS_PER_SEC << " s.\n"
class C_ {}; template <typename T> C_& operator <<(C_& m, const T& s) { if (!OJ) cerr << "\E[91m" << s << "\E[0m"; return m; }
C_ merr;
/// END OF TEMPLATE }}}

int main(void) {
  int T;
  freopen("input.txt", "rt", stdin); freopen("output.txt", "wt", stdout);
  cin >> T;
  for (int tt = 0; tt < T; tt++) {
    int n;
    int ans = 1000000000;
    int A[1111];
    cin >> n;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      A[i] = a;
    }
    for (int mn = 1; mn <= 1000; mn++) {
      int moves = 0;
      for (int i = 0; i < n; i++) {
        if (A[i] > mn) {
          moves += A[i]/mn + !!(A[i]%mn) - 1;
        }
      }
      ans = min(ans, moves + mn);
    }
    cout << "Case #" << tt+1 << ": " << ans << endl;
  }
  return 0;
}
