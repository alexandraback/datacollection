#include <bits/stdc++.h>

using namespace std;


int main () {
  ios_base::sync_with_stdio(false);
  int t, caso, x, r, c;
  
  cin >> t;
  
  for (caso = 1; caso <= t; caso++) {
    cin >> x >> r >> c;
    cout << "Case #" << caso << ": ";
    
    if (x == 1)
      cout << "GABRIEL" << endl;
    else if (x == 2) {
      if ((r * c) % 2 == 0)
        cout << "GABRIEL" << endl;
      else
        cout << "RICHARD" << endl;
    }
    else if (x == 3) {
      if ((r * c) % 3 != 0 || r * c == 3)// || r * c == 9)
        cout << "RICHARD" << endl;
      else
        cout << "GABRIEL" << endl;
    }
    else {
      if ((r * c) % 4 != 0 || r * c <= 8)
        cout << "RICHARD" << endl;
      else
        cout << "GABRIEL" << endl;
    }
  }
  
  return 0;
}










