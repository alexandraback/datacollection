#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int64_t go(int64_t n) {
  if (n <= 20) return n;
  if (n % 10 == 0) return go(n - 1) + 1;

  auto s = to_string(n);
  
  int mid = s.size() / 2;
  auto left = s.substr(0, mid);
  auto right = s.substr(mid, s.size() - mid);

  int64_t res = stoll(right) - 1;

  reverse(left.begin(), left.end());
  int64_t ll = stoll(left);
  if (ll > 1) {
    res += ll;
  }

  string ss(s.size() - 1, '9');
  return res + 2 + go(stoll(ss));
}

int main(int argc, const char* argv[]) {
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int64_t N;
    cin >> N;
    cout << "Case #" << t + 1 << ": " << go(N) << endl;
  }
}
