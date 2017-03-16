// TEMPLATE {{{
#include <bits/stdc++.h>
using namespace std;
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

int main(void) {
  int T;
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
  cin >> T;
  for (int tt = 0; tt < T; tt++) {
    string s;
    int C[26] = {};
    int D[10] = {};
    cin >> s;
    for (int i = 0; i < (int)s.size(); i++) {
      C[s[i]-'A']++;
    }
    int cz = C['Z'-'A'];
    for (int i = 0; i < cz; i++) {
      D[0]++;
      C['Z'-'A']--; C['E'-'A']--; C['R'-'A']--; C['O'-'A']--;
    }
    int cw = C['W'-'A'];
    for (int i = 0; i < cw; i++) {
      D[2]++;
      C['T'-'A']--; C['W'-'A']--; C['O'-'A']--;
    }
    //THREE
    int cu = C['U'-'A'];
    for (int i = 0; i < cu; i++) {
      D[4]++;
      C['F'-'A']--; C['O'-'A']--; C['U'-'A']--; C['R'-'A']--;
    }
    int cf = C['F'-'A'];
    for (int i = 0; i < cf; i++) {
      D[5]++;
      C['F'-'A']--; C['I'-'A']--; C['V'-'A']--; C['E'-'A']--;
    }
    int cx = C['X'-'A'];
    for (int i = 0; i < cx; i++) {
      D[6]++;
      C['S'-'A']--; C['I'-'A']--; C['X'-'A']--;
    }
    int cs = C['S'-'A'];
    for (int i = 0; i < cs; i++) {
      D[7]++;
      C['S'-'A']--; C['E'-'A']--; C['V'-'A']--; C['E'-'A']--; C['N'-'A']--;
    }
    int cg = C['G'-'A'];
    for (int i = 0; i < cg; i++) {
      D[8]++;
      C['E'-'A']--; C['I'-'A']--; C['G'-'A']--; C['H'-'A']--; C['T'-'A']--;
    }
    int ci = C['I'-'A'];
    for (int i = 0; i < ci; i++) {
      D[9]++;
      C['N'-'A']--; C['I'-'A']--; C['N'-'A']--; C['E'-'A']--;
    }
    int co = C['O'-'A'];
    for (int i = 0; i < co; i++) {
      D[1]++;
      C['O'-'A']--; C['N'-'A']--; C['E'-'A']--;
    }
    int cr = C['R'-'A'];
    for (int i = 0; i < cr; i++) {
      D[3]++;
      C['T'-'A']--; C['H'-'A']--; C['R'-'A']--; C['E'-'A']--; C['E'-'A']--;
    }
    for (int i = 0; i < 26; i++) {
      assert(C[i] == 0);
    }
    cout << "Case #" << tt+1 << ": ";
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < D[i]; j++) {
        cout << i;
      }
    }
    cout << endl;
  }
  return 0;
}
