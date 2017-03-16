#include <bits/stdc++.h>

using namespace std;

// TEMPLATE {{{
#ifndef LOCAL
#define OJ 1
#else
#define OJ 0
#endif
 
#define endl '\n'
#define TIMESTAMP merr << "Execution time: " << (double)clock()/CLOCKS_PER_SEC << " s.\n"
class C_ {}; template <typename T> C_& operator <<(C_& __m, const T& __s) { if (!OJ) cerr << "\E[91m" << __s << "\E[0m"; return __m; }
C_ merr;
 
struct __s { __s() { if (OJ) { ios_base::Init i; cin.sync_with_stdio(0); cin.tie(0); } } ~__s(){ TIMESTAMP; } } __S;
/// END OF TEMPLATE }}}

// 1 = 0, i = 1, j = 2, k = 3

int M[4][4] = {
  { 0, 1, 2, 3 },
  { 1, 0, 3, 2 },
  { 2, 3, 0, 1 },
  { 3, 2, 1, 0 }
};

int S[4][4] = {
  {  1,  1,  1,  1 },
  {  1, -1,  1, -1 },
  {  1, -1, -1,  1 },
  {  1,  1, -1, -1 }
};

int main(void) {
  int T;
  freopen("input.txt", "rt", stdin);
  // freopen("output.txt", "wt", stdout);
  cin >> T;
  for (int tt = 0; tt < T; tt++) {
    string s,ss;
    int l,x,n;
    int PM[11111];
    int PS[11111];
    int V[11111];
    int vlen = 0;
    cin >> l >> x >> ss;
    n = l*x;
    for (int i = 0; i < x; i++) {
      s += ss;
    }
    PM[0] = (s[0]-'i'+1);
    PS[0] = 1;
    if (PM[0] == 1 && PS[0] == 1) V[vlen++] = 0;
    for (int i = 1; i < n; i++) {
      int prev = PM[i-1];
      int cur = s[i]-'i'+1;
      PM[i] = M[prev][cur];
      PS[i] = PS[i-1] * S[prev][cur];
      if (PM[i] == 1 && PS[i] == 1) V[vlen++] = i;
    }
    int lastm = PM[n-1], lasts = PS[n-1];
    bool ok = false;
    for (int i = 0; i < vlen; i++) {
      int idx = V[i];
      int im = PM[idx], is = PS[idx];
      for (int j = idx+1; j < n-1; j++) {
        int jm = M[im][PM[j]], js = -S[im][PM[j]]*is*PS[j];
        if (jm != 2 || js != 1) continue;
        int km = M[PM[j]][lastm], ks = -S[PM[j]][lastm]*PS[j]*lasts;
        if (km == 3 && ks == 1) {
          ok = true;
          break;
        }
      }
      if (ok) break;
    }
    cout << "Case #" << tt+1 << ": " << (ok ? "YES" : "NO") << endl;
  }
  return 0;
}
