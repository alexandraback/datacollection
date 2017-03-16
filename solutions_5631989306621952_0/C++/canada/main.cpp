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
    string s; cin >> s;
    ui n = s.length();
    vector<int> w_i(n);
    vector<char> w_c(n);
    w_i[0] = 0;
    w_c[0] = s[0];
    for (ui i = 1; i < n; ++i) {
      if (s[i] >= w_c[i - 1]) {
        w_i[i] = i;
        w_c[i] = s[i];
      } else {
        w_i[i] = w_i[i-1];
        w_c[i] = w_c[i-1];
      }
    }
    ii j = n - 1;
    while (j > 0) {
      cout << w_c[j];
      s[w_i[j]] = '\0';
      j = w_i[j] - 1;
    }
    for (char c : s) {
      if (c) cout << c;
    }
    cout << "\n";
  }
}
