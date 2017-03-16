#include <iostream>
#include <bitset>
#include <cstdint>
#include <vector>

using namespace std;

typedef int64_t ii;
typedef uint64_t ui;

int64_t expo(int64_t a, int64_t b){
  int64_t result = 1ll;

  while (b>0ll){
    result *= a;
    b--;
  }

  return result;
}

ii k, c, s;

int main() {
  freopen("in", "r", stdin);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> k >> c >> s;
    cout << "Case #" << i << ":";
    if (s * c < k) {
      cout << " IMPOSSSIBLE\n";
      continue;
    }

    for (ii b = 0; b < k; b += c) {
      vector<ii> tmp(c);
      for (ii t = 0; t < c; ++t) tmp[t] = min(k - 1, b + t);
      ii a = expo(k, c), d = 0;
      for (ii t = 0; t < c; ++t) {
        a /= k;
        d += tmp[t] * a;
      }
      cout << " " << (d + 1);
    }
    cout << "\n";
  }
}
