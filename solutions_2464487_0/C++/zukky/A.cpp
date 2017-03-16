#include <iostream>
#include <algorithm>
using namespace std;

typedef long long lli;


int main() {
  int Tc;
  cin >> Tc;
  for(int tc = 0; tc < Tc; ++tc) {
    lli r, t;
    cin >> r >> t;
    lli ans = 0;
    for(lli cost = 0; ; ) {
      lli ncost = 2*r + 4*ans + 1;
      if(cost + ncost > t) break;
      cost += ncost;
      ++ans;
    }
    cout << "Case #" << tc+1 << ": " << ans << endl;
  }
  return 0;
}
