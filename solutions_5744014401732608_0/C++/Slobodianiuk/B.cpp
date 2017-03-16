#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

typedef long long lol;
typedef vector<int> VI;
typedef vector<VI> VVI;

void solve(lol &b, lol &m) {
  if (m > (1 << (b - 2))) {
    cout << "IMPOSSIBLE\n";
    return;
  }
  cout << "POSSIBLE\n";
  for (int i = 1; i < b; ++i) {
    for (int j = 1; j < b; ++j) {
      if (j > i) {
        cout << "1";
      } else {
        cout << "0";
      }
    }
    if (m & (1 << (i - 2)) || m == (1 << (b-2))) {
      cout << "1";
    } else {
      cout << "0";
    }
    cout << "\n";
  }
  for (int j = 0; j < b; ++j) {
    cout << "0";
  }
  cout << "\n";
}

int main() {

#ifdef LocalHost
  //freopen("input", "rt", stdin);
  //freopen("B-large.in", "rt", stdin);
  freopen("B-small-attempt1.in", "rt", stdin);
  freopen("outputB1.txt", "w", stdout);
#endif

  int line_num;
  cin >> line_num;
  for (int line = 0; line < line_num; ++line) {
    lol b, m;
    cin >> b >> m;
    printf("Case #%d: ", line + 1);
    solve(b, m);
  }
  return 0;
}
