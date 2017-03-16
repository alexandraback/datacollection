#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

using namespace std;

int main() {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    string s;
    cin >> s;
    s += "+";

    int result = 0;
    for (int i = 1; i < s.size(); i++) {
      if (s[i] != s[i - 1]) {
        ++result;
      }
    }
    cout << "Case #" << t << ": " << result << endl;
  }
  return 0;
}
