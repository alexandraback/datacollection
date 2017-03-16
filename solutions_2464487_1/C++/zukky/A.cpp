#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long lli;


int main() {
  int Tc;
  cin >> Tc;
  for(int tc = 0; tc < Tc; ++tc) {
    lli r, t;
    cin >> r >> t;
    lli ans = 0;
    /*
    for(lli cost = 0; ; ) {
      lli ncost = 2*r + 4*ans + 1;
      if(cost + ncost > t) break;
      cost += ncost;
      ++ans;
    }
    */
    lli low = 0LL;
    lli high = 9999999999LL;
    while(high-low) {
      lli m = (low+high)/2;
      lli tmp = (2*(r+m)+1);
      if(tmp > 2*1000000000000000000LL/(m+1)) {
	high = m;
	continue;
      }
      lli cost = (m+1)*(2*(r+m)+1);
      if(cost <= t) {
	low = m+1;
      } else {
	high = m;
      }
    }
    ans = low;
    cout << "Case #" << tc+1 << ": " << ans << endl;
  }
  return 0;
}
