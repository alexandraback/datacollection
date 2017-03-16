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
    int x; cin >> x;
    int y;

    set<char> st;
    for (y = 0; x != 0 && st.size() != 10; ) {
      y += x;
      string s = to_string(y);
      st.insert(s.begin(), s.end());
    }

    cout << "Case #" << t << ": ";
    if (x == 0) {
      cout << "INSOMNIA";
    } else {
      cout << y;
    }
    cout << '\n';
  }
  return 0;
}
