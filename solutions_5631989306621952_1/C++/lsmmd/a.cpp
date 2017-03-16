#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
#include <cmath>
#include <climits>
using namespace std;
int main() {
  int tk, tk1 = 0;
  cin >> tk;
  while (tk--) {
    tk1++;
    string ans = "";
    string s;
    cin >> s;
    ans += s[0];
    for (int i = 1; i < s.length(); i++) {
      if (s[i] >= ans[0]) {
        ans = s[i] + ans;
      }
      else {
        ans = ans + s[i];
      }
    }
    cout << "Case #" << tk1 << ": " << ans << endl;
  }
  return 0;
}
