#include <bits/stdc++.h>

using namespace std;

struct Ans {
  string s1;
  string s2;
  long long diff;
  bool ok;
};

void solveTest() {
  string s1, s2;
  cin >> s1 >> s2;
  int n;
  n = s1.size();
  Ans more = {"", "", 10000000, false};
  Ans less = {"", "", -10000000, false};
  Ans zero = {"A", "A", 0, false};
  Ans curMore = {"", "", 10000000, false};
  Ans curLess = {"", "", -10000000, false};
  Ans curZero = {"", "", 0, true};

  auto cmp = [](const Ans& a1, const Ans& a2) {
    if (a1.ok != a2.ok) {
      return a1.ok;
    }
    if (abs(a1.diff) != abs(a2.diff)) {
      return abs(a1.diff) < abs(a2.diff);
    } else if (a1.s1 != a2.s1) {
      return a1.s1 < a2.s1;
    } else {
      return a1.s2 < a2.s2;
    }
  };

  auto tryApply = [&](const Ans& a) {
    if (a.diff > 0 && cmp(a, more)) {
      more = a;
    } else if (a.diff == 0 && cmp(a, zero)) {
      zero = a;
    } else if (a.diff < 0 && cmp(a, less)) {
      less = a;
    }
  };

  auto apply2 = [&](Ans x, int dig1, int dig2) {
    if (!x.ok) {
      return;
    }
    x.s1 = x.s1 + to_string(dig1);
    x.s2 = x.s2 + to_string(dig2);
    x.diff = x.diff * 10 + dig1 - dig2;
    tryApply(x);
  };
  
  for (int i = n - 1; i >= 0; i--) {
    for (int x = 0; x < 10; x++) {
      for (int y = 0; y < 10; y++) {
	if (s1[n - i - 1] != '?' && s1[n - i - 1] != x + '0')
	  continue;
	if (s2[n - i - 1] != '?' && s2[n - i - 1] != y + '0')
	  continue;
	apply2(curMore, x, y);
	apply2(curLess, x, y);
	apply2(curZero, x, y);
      }
    }
    curMore = more;
    curLess = less;
    curZero = zero;
    more = {"", "", 10000000, false};
    less = {"", "", -10000000, false};
    zero = {"", "", 0, false};
  }
  Ans a(curMore);
  if (cmp(curLess, a)) {
    a = curLess;
  }
  if (cmp(curZero, a)) {
    a = curZero;
  }
  cout << a.s1 << " " << a.s2 << "\n";
}

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cout << "Case #" << i << ": ";
    solveTest();
  }
  return 0;
}
