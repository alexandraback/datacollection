#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

void solve(const int &l, const int &n) {
  for (int i = 0; i < n; ++i) {
    string s;
    s.assign(l, '0');
    s[0] = s[1] = s[l-1] = s[l-2] = '1';
    int j = i;
    int pos = 2;
    while (j > 0) {
      if (j % 2) {
        s[pos] = '1';
        s[pos+1] = '1';
      }
      pos += 2;
      j /= 2;
    }
    cout << s;
    for (int k = 3; k < 12; ++k) {
      cout << " " << k;
    }
    cout << "\n";
  }
}

int main() {

#ifdef LocalHost
  freopen("input", "rt", stdin);
  //freopen("B-large.in", "rt", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int line_num;
  cin >> line_num;
  for (int line = 0; line < line_num; ++line) {
    int l, n;
    cin >> l >> n;
    printf("Case #%d:\n", line+1);
    solve(l, n);
  }
  return 0;
}
