#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef unsigned int uint;

inline uint inc(uint mask, uint x) {
  return mask | (mask << x);
}

int c, d, v;
int solve() {
  // c == 1
  uint x;
  uint mask = 1, tmask = (1u << (v+1)) - 1;
  for (int i = 0; i < d; ++i) {
    cin >> x;
    mask = inc(mask, x) & tmask;
  }
  int q = 0;
  while (mask != tmask) {
    ++q;
    x = __builtin_ctz(~mask);
    //cerr << x << endl;
    mask = inc(mask, x) & tmask;
  }
  return q;
}

int main() {
  ios::sync_with_stdio(0);
  int tc;
  cin >> tc;
  for (int cs = 1; cs <= tc; ++cs) {
    cout << "Case #" << cs << ": ";
    cin >> c >> d >> v;
    cout << solve();
    cout << endl;
  }
  return 0;
}

