#include <ctime>
#include <iostream>
#include <iomanip>
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
    double c,f,x;
    double rate = 2;
    double t = 0;
    cin >> c >> f >> x;
    while (1) {
      if (c/rate+x/(rate+f) < x/rate) {
        t += c/rate;
        rate += f;
      } else {
        t += x/rate;
        break;
      }
    }
    cout << "Case #" << tt+1 << ": ";
    cout << fixed << setprecision(9) << t << endl;
  }
  //TIMESTAMP;
  return 0;
}
