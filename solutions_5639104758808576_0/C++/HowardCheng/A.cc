#include <iostream>
#include <algorithm>

using namespace std;

void solve()
{
  int ans = 0;

  int Smax;
  cin >> Smax;

  int total = 0;
  for (int k = 0; k <= Smax; k++) {
    char c;
    cin >> c;
    int n = c - '0';

    if (k > 0 && n > 0) {
      int add = max(0, k - total);
      ans += add;
      total += add;
    }
    total += n;
  }
  cout << ans << endl;
}

int main()
{
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
