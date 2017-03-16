#include <iostream>
using namespace std;
int main() {
  int t,r,c,w;
  cin >> t;
  for (int casecnt = 1; casecnt <=t; ++casecnt) {
    cin >> r >> c >> w;
    int ans = 0;
    ans = ((c+w-1)/w)+(w-1) + (c/w) *(r-1);
    cout << "Case #" << casecnt << ": " << ans << endl;
  }
}
