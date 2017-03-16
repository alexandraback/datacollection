#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

int main() {

#ifdef LocalHost
  //freopen("input", "rt", stdin);
  freopen("B-large.in", "rt", stdin);
  //freopen("B-small-attempt0.in", "rt", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int line_num;
  cin >> line_num;
  for (int line = 0; line < line_num; ++line) {
    int l;
    cin >> l;
    VI sset(2501);
    for (int i = 0; i < (2 * l - 1) * l; ++i) {
      int x; cin >> x;
      sset[x] = 1 - sset[x];
    }
    VI ans;
    for (int i = 0; i < 2501; ++i) {
      if (sset[i]) {
        ans.push_back(i);
      }
    }
    printf("Case #%d: ", line + 1);
    for (int i = 0; i < ans.size(); ++i) {
      cout << ans[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}
