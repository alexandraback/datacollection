#include <bits/stdc++.h>
using namespace std;

int main() {
  int TT;
  cin >> TT;
  for (int tt = 0; tt < TT; ++tt) {
    string s, t;
    cin >> s;
    for (char c : s) {
      string d(1, c);
      if (d + t > t + d)
        t = d + t;
      else
        t = t + d;
    }
    cout << "Case #" << tt + 1 << ": " << t << endl;
  }
}
