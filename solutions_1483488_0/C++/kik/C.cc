#include <iostream>
#include <set>

using namespace std;

int main()
{
  int T;
  cin >> T;
  for (int cas = 1; cas <= T; cas++) {
    int a, b;
    cin >> a >> b;

    int res = 0;
    int dd;
    for (dd = 1; dd <= a; dd *= 10)
      ;
    for (int x = a; x < b; x++) {
      set<int> st;
      for (int d = 10; d <= a; d *= 10) {
        int y = x / d + x % d * (dd / d);
        if (x < y && y <= b) st.insert(y);
      }
      res += st.size();
    }
    cout << "Case #" << cas << ": " << res << endl;
  }
  return 0;
}
