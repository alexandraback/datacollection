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
  srand((int)time(0));
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
  cin >> T;
  for (int tt = 0; tt < T; tt++) {
    int j,p,s,k;
    cin >> j >> p >> s >> k;
    cout << "Case #" << tt+1 << ": ";
    vector<int> V;
    for (int i1 = 1; i1 <= j; i1++) {
      for (int i2 = 1; i2 <= p; i2++) {
        for (int i3 = 1; i3 <= s; i3++) {
          V.push_back(i1*100 + i2*10 + i3);
        }
      }
    }
    vector<int> VA;
    for (int t = 0; t < 100000; t++) {
      random_shuffle(V.begin(), V.end());
      int C12[4][4] = {};
      int C13[4][4] = {};
      int C23[4][4] = {};
      vector<int> VV;
      for (int i = 0; i < (int)V.size(); i++) {
        int x = V[i];
        int i1,i2,i3;
        i3 = x%10; x /= 10;
        i2 = x%10; x /= 10;
        i1 = x;
        if (C12[i1][i2] >= k) continue;
        if (C13[i1][i3] >= k) continue;
        if (C23[i2][i3] >= k) continue;
        C12[i1][i2]++;
        C13[i1][i3]++;
        C23[i2][i3]++;
        VV.push_back(V[i]);
      }
      if (VV.size() > VA.size()) VA = VV;
    }
    cout << VA.size() << endl;
    for (int i = 0; i < (int)VA.size(); i++) {
      int x = VA[i];
      int i1,i2,i3;
      i3 = x%10; x /= 10;
      i2 = x%10; x /= 10;
      i1 = x;
      cout << i1 << " " << i2 << " " << i3 << endl;
    }
  }
  return 0;
}
