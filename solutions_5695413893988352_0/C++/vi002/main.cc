#include <cassert>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
using namespace std;

string to_string(size_t n, int value) {
  ostringstream os;
  os << setfill('0') << setw(n) << value;
  return os.str();
}

bool matches(size_t n, string const &pattern, string const &text) {
  assert(pattern.size() == n);
  assert(text.size() == n);
  for (size_t i = 0; i < n; ++i) {
    if (pattern[i] != '?' && pattern[i] != text[i])
      return false;
  }
  return true;
}

int mpow(int a, int n) {
  int result = 1;
  for (int i = 0; i < n; ++i)
    result *= a;
  return result;
}

int main() {
  int num_tests;
  cin >> num_tests;
  for (int test_num = 0; test_num < num_tests; ++test_num) {
    string c, j;
    cin >> c >> j;
    const size_t n = c.size();

    int best_diff = numeric_limits<int>::max();
    int best_c = numeric_limits<int>::max();
    int best_j = numeric_limits<int>::max();

    for (int cn = 0; cn < mpow(10, n); ++cn) {
      string cns = to_string(n, cn);
      if (!matches(n, c, cns))
        continue;

      for (int jn = 0; jn < mpow(10, n); ++jn) {
        string jns = to_string(n, jn);
        if (!matches(n, j, jns))
          continue;

        int cur_diff = abs(cn - jn);
        if (cur_diff < best_diff || (cur_diff == best_diff && cn < best_c) ||
            (cur_diff == best_diff && cn == best_c && jn < best_j)) {
          best_diff = cur_diff;
          best_c = cn;
          best_j = jn;
        }
      }
    }

    cout << "Case #" << (test_num + 1) << ": " << to_string(n, best_c) << " "
         << to_string(n, best_j) << endl;
  }
  return 0;
}
