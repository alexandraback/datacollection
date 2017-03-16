#include <iostream>

using namespace std;

typedef long long L;

int main() {
  int t; cin >> t;
  for (int test = 1; test <= t; ++test) {
    L aa, bb, kk; cin >> aa >> bb >> kk;
    L wins = 0;
    for (L a = 0; a < aa; ++a) {
      for (L b = 0; b < bb; ++b) {
        if ((a & b) < kk) {
          wins++;
        }
      }
    }
    cout << "Case #" << test << ": " << wins << endl;
  }
  return 0;
}