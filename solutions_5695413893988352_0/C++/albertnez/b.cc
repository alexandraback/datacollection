#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

bool ok(int n, const string &s) {
  for (int i = s.size()-1; i >= 0; --i) {
    if (s[i] != '?' && s[i]-'0' != (n%10)) return false;
    n /= 10;
  }
  return n == 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T; cin >> T;
  for (int ncase = 1; ncase <= T; ++ncase) {
    int bestd = 1000000;
    const int lim = 1000;
    int bestc = 0, bestj = 0;
    string l, r; cin >> l >> r;
    for (int c = 0; c < lim; ++c) {
      for (int j = 0; j < lim; ++j) {
        if (abs(c-j) < bestd && ok(c, l) && ok(j, r)) {
          bestd = abs(c-j);
          bestc = c;
          bestj = j;
        }
      }
    }
    cout << "Case #" << ncase << ": " 
         << setw(l.size()) << setfill('0') << bestc << " " << 
         setw(l.size()) << setfill('0') << bestj << endl;
  }
}
