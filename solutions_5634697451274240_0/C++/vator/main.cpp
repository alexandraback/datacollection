// TEMPLATE {{{
#include <bits/stdc++.h>
using namespace std;
#ifndef LOCAL
#define OJ 1
#else
#define OJ 0
#endif

#define endl '\n'
#define TIMESTAMP merr << "Execution time: " << fixed << setprecision(3) << (double)clock()/CLOCKS_PER_SEC << " s.\n"
class C_ {}; template <typename T> C_& operator <<(C_& __m, const T& __s) { if (!OJ) cerr << "\E[91m" << __s << "\E[0m"; return __m; }
C_ merr;

struct __s { __s() { if (OJ) { ios_base::Init i; cin.sync_with_stdio(0); cin.tie(0); } } ~__s(){ TIMESTAMP; } } __S;
/// END OF TEMPLATE }}}

int naive(const string & s) {
  int n = (int)s.size();
  set<string> S;
  map<string,int> mp;
  mp[s] = 0;
  queue<string> Q;
  Q.push(s);
  while (Q.size()) {
    string v = Q.front();
    int d = mp[v];
    Q.pop();
    for (int i = 0; i < n; i++) {
      string ss = v;
      reverse(ss.begin(), ss.begin()+i+1);
      for (int j = 0; j <= i; j++) {
        ss[j] = (ss[j] == '+' ? '-' : '+');
      }
      if (mp.find(ss) == mp.end()) {
        mp[ss] = d+1;
        Q.push(ss);
      }
    }
  }
  string ss;
  for (int i = 0; i < n; i++) {
    ss += '+';
  }
  return mp[ss];
}

int clever(const string & s) {
  int n = (int)s.size();
  while (n && s[n-1] == '+') { n--; }
  string ss = s.substr(0, n);
  int prev = -1;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] != prev) ans++;
    prev = s[i];
  }
  return ans;
}

void tests() {
  int fidx = 0;
  while (1) {
    merr << '\r' << ++fidx << '\r';
    string s;
    int n = rand()%10+1;
    for (int i = 0; i < n; i++) {
      s += (rand()%2 ? '+' : '-');
    }
    int a1 = naive(s);
    int a2 = clever(s);
    if (a1 != a2) {
      merr << "EREOROEROOE!!" << '\n';
      merr << a1 << " " << a2 << '\n';
      merr << s << '\n';
      cin.get();
    }
  }
}

int main(void) {
  // tests();
  int T;
  freopen("input.txt", "rt", stdin); freopen("output.txt", "wt", stdout);
  cin >> T;
  for (int tt = 0; tt < T; tt++) {
    string s;
    cin >> s;
    cout << "Case #" << tt+1 << ": ";
    // cout << naive(s) << endl;
    cout << clever(s) << endl;
  }
  return 0;
}
