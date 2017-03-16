#include <iostream>
#include <set>
using namespace std;

int main() {
  int T, n, n_orig, c;
  set<int> s;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    cin >> n_orig;
    cout << "Case #" << i+1 << ": ";
    s.clear();
    if (!n_orig) {
      cout << "INSOMNIA" << endl;
      continue;
    }
    c = 0;
    while (s.size() != 10) {
      ++c;
      n = n_orig * c;
      while (n) {
        s.insert(n % 10);
        n /= 10;
      }
    }
    cout << n_orig * c << endl;
  }
  return 0;
}
