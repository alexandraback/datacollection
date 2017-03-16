#include <iostream>
#include <bitset>
#include <cstdint>
#include <vector>
#include <string>
#include <sstream>

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

int main() {
  freopen("in", "r", stdin);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cout << "Case #" << i << ": ";
    ii v; cin >> v;
    if (v == 0) {
      cout << "INSOMNIA\n";
      continue;
    }
    ii k = 0;
    ii last;
    for (ii m = 1; k != 1023; ++m) {
      stringstream ss;
      last = v * m;
      ss << last;
      string s = ss.str();
      for (char c : s) k = k | (1 << (c - '0'));
    }
    cout << last << "\n";
  }
}
