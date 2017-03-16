#include <iostream>
using namespace std;

int main()
{
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int r, c, w;
    cin >> r >> c >> w;
    int ans = (r) * (c/w) + (w-1);
    ans += (c % w != 0);
    cout << "Case #" << t+1 << ": " << ans << endl;
  }
}