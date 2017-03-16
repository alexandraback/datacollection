#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

using int64 = long long;

int main() {
  auto solve = [](string c, string j) {
    auto matches = [](string s, int n) {
      for (int i = s.size() - 1; i >= 0; --i, n /= 10) {
	if (s[i] == '?')
	  continue;
	if ((s[i] - '0') != (n % 10))
	  return false;
      }
      if (n != 0)
	return false;
      return true;
    };
    auto set = [](int n, string& s) {
      for (int i = s.size() - 1; i >= 0; --i, n /= 10) {
	s[i] = '0' + (n % 10);
      }
    };

    int64 mn = numeric_limits<int64>::max();
    int64 mnx = -1;
    int64 mny = -1;
    for (int x = 0; x <= 999; ++x) {
      if (!matches(c, x))
	continue;
      for (int y = 0; y <= 999; ++y) {
	if (!matches(j, y))
	  continue;

	int64 cur = abs(x - y);
	if (cur < mn) {
	  mn = cur;
	  mnx = x;
	  mny = y;
	}
      }
    }

    set(mnx, c);
    set(mny, j);
    return c + " " + j;
  };

  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    string c, j;
    cin >> c >> j;
    cout << "Case #" << i << ": " << solve(c, j) << "\n";
  }
}
