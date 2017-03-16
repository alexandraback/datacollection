#include <bits/stdc++.h>

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()

using namespace std;

void solve() {
  string s, res;
  cin >> s;
  for (char c: s) {
    if (res + c < c + res)
      res = c + res;
    else
      res = res + c;
  }
  cout << res << endl;
}

int main() {
  int T;
  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    cout << "Case #" << cas << ": ";
    solve();
  }
  return 0;
}
