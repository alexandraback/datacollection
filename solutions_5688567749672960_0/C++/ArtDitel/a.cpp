#include <iostream>
#include <vector>
using namespace std;

long long rev(long long x) {
  long long y = 0;
  while (x) {
    y = (x % 10) + y * 10;
    x /= 10;
  }
  return y;
}

long long solve(long long n) {
  std::vector<long long> a(n*10, 10000);
  a[0] = 0;
  auto up =  [&](long long x, long long v) {
    if (x < 0 || x >= a.size()) return;
    a[x] = std::min(a[x], v);
  };
  for (int j = 0; j < 2; ++j) {
    for (long long i = 0; i < 10*n; ++i) {
      long long x = i + 1;
      long long y = rev(i);
      up(x, a[i]+1);
      up(y, a[i]+1);
    }
    cerr << a[n] << endl;
  }
  return a[n];
}

int main() {
  int tc;
  cin >> tc;
  for (int t = 1; t <= tc; ++t) {
    long long n;
    cin >> n;
    cout << "Case #" << t << ": " << solve(n) << endl;

  }
}
