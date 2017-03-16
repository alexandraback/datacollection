#include <ctime>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <cstdio>

using namespace std;

// TEMPLATE {{{
#ifdef ONLINE_JUDGE
#define OJ 1
#else
#define OJ 0
#endif

//#define TIMESTAMP fprintf(stderr, "Execution time: %.3lf s.\n", (double)clock()/CLOCKS_PER_SEC)
#define TIMESTAMP merr << "Execution time: " << fixed << setprecision(3) << (double)clock()/CLOCKS_PER_SEC << " s.\n"
class C_ {}; template <typename T> C_& operator <<(C_& m, const T& s) { if (!OJ) cerr << "\E[91m" << s << "\E[0m"; return m; }
C_ merr;
/// END OF TEMPLATE }}}

int main(void) {
  int T;
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
  cin >> T;
  for (int tt = 0; tt < T; tt++) {
    int n;
    int ans = 0;
    double A[1111], B[1111];
    set<double> S;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> A[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> B[i];
      S.insert(B[i]);
    }
    sort(A,A+n,greater<double>());
    sort(B,B+n);
    for (int d = 1; d <= n; d++) {
      bool ok = true;
      for (int i = 0; i < d; i++) {
        if (B[i] > A[d-i-1]) {
          ok = false;
          break;
        }
      }
      if (ok) ans = d;
      else break;
    }
    cout << "Case #" << tt+1 << ": " << ans << " ";
    ans = 0;
    sort(A,A+n,greater<double>());
    for (int i = 0; i < n; i++) {
      double a = A[i];
      if (S.lower_bound(a) != S.end()) {
        S.erase(S.lower_bound(a));
      } else {
        S.erase(S.begin());
        ans++;
      }
    }
    cout << ans << endl;
  }
  //TIMESTAMP;
  return 0;
}
