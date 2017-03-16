#include <iostream>

using namespace std;

int main() {
  int tc_cnt;
  cin >> tc_cnt;
  for (int tc = 1; tc <= tc_cnt; tc++) {
    int n, s, p, x;
    int y = 0;
    cin >> n >> s >> p;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      int r = x % 3;
      int b = (x / 3) + (r != 0 ? 1 : 0);
      int m = b;
      if (r != 1 && b > 0) { m++; }
      
      if (b >= p) {
        y++;
      }
      else if (s > 0 && m >= p) {
        s--;
        y++;
      }
    }    
    cout << "Case #" << tc << ": " << y << endl;
  } 
}
