#include <iostream>
using namespace std;

int main() {
  int t; cin >> t;
  for (int c = 1; c <= t; c++) {
    int n, s, p; cin >> n >> s >> p;
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++) {
      int a; cin >> a;
      if (a >= p + 2*max(p-1, 0)) c1++;
      else if (a >= p + 2*max(p-2, 0)) c2++;
    }

    int res = c1 + min(s, c2);
    cout << "Case #" << c << ": " << res << endl;
  }
  return 0;
}
