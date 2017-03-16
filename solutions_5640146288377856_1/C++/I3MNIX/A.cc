#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
int R, C, W;

int main(){
  int t;
  cin >> t;
  for (int idx = 1; idx <= t; idx++){
    cout << "Case #" << idx << ": ";
    cin >> R >> C >> W;
    int div = C / W;
    int rem = C % W;
    
    int res = (R - 1) * div;
    
    if (rem == 0) {
      res += div + (W - 1);
    }
    else {
      res += div + W;
    }
    cout << res << endl;
  }
  return 0;
}
