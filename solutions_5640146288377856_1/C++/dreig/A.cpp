#include <iostream>

using namespace std;

int main() {
  int T, R, C, W, ans = -1;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> R >> C >> W;
    
    if (W == 1)
      ans = R*C;
    else {
      if (C % W == 0)
        ans = (R-1)*(C / W) + (C / W) - 1;
      else
        ans = R * (C / W);
      
      ans += W;
    }
    cout << "Case #" << t << ": " << ans << '\n';  
  }

  return 0;
}
