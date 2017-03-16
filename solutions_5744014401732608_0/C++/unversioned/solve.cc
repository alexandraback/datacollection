#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <iterator>

using namespace std;

using int64 = long long;

int64 intpow(int64 base, int64 pow) {
  if (pow == 0)
    return 1;
  if (pow == 1)
    return base;

  int64 tmp = intpow(base, pow/2);
  return tmp * tmp * (pow%2 == 0 ? 1 : base);
}

int main() {
  int n;
  cin >> n;

  auto solve = [](int64 b, int64 m) {
    int64 max_possible = intpow(2, b-2);
    if (max_possible < m) {
      cout << "IMPOSSIBLE";
      return;
    }

    bool mx[50][50] = {false};
    for (int i = 0; i < b-1; ++i) {
      for (int j = i+1; j < b-1; ++j) {
	mx[i][j] = true;
      }
    }
    
    if (m == max_possible) {
      mx[0][b-1] = true;
      --m;
    }
    vector<bool> ones(b-2, false);
    int bit = 0;
    while (bit < b-2 && m > 0) {
      ones[bit] = (m % 2 == 1);
      m /= 2;
      ++bit;
    }

    for (int i = 1; i < b-1; ++i) {
      if (ones[i-1])
	mx[i][b-1] = true;
    }

    cout << "POSSIBLE\n";
    for (int i = 0; i < b; ++i) {
      for (int j = 0; j < b; ++j) {
	cout << (mx[i][j] ? '1' : '0');
      }
      if (i != b-1)
	cout << "\n";
    }
  };

  for (int i = 1; i <= n; ++i) {
    int64 b, m;
    cin >> b >> m;
    
    cout << "Case #" << i << ": ";
    solve(b, m);
    cout << "\n";
  }
}
