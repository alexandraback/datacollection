#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

long long solve(const long long &n) {
  long long ret = 0;
  set<int> digits;
  for (int d = 0; d < 10; ++d) {
    digits.insert(d);
  }
  while (digits.size() > 0) {
    ret += n;
    long long x = ret;
    while(x > 0) {
      int dig = x % 10;
      digits.erase(dig);
      x /= 10;
    }
  }
  return ret;
}

int main() {

#ifdef LocalHost
  //freopen("input", "rt", stdin);
  freopen("A-small-attempt0.in", "rt", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n; cin >> n;
  for (int t = 0; t < n; ++t) {
    string s, b, e, a;
    cin >> s;
    b.push_back(s[0]);
    for (size_t l = 1; l < s.size(); ++l) {
      char ch = s[l];
      if (ch < b.back()) {
        e.push_back(ch);
      } else {
        b.push_back(ch);
      }
    }
    for (size_t i = b.size(); i > 0; --i) {
      a.push_back(b[i-1]);
    }
    a = a + e;
    cout << "Case #" << t + 1 << ": " + a + "\n";
  }
  return 0;
}
