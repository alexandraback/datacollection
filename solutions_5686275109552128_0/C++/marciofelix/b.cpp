#include <bits/stdc++.h>

using namespace std;


int main () {
  ios_base::sync_with_stdio(false);
  int i, t, caso, resp, d, p[1010], la, special;
  
  cin >> t;
  
  for (caso = 1; caso <= t; caso++) {
    resp = 1;
    
    cin >> d;
    for (i = 0; i < d; i++) {
      cin >> p[i];
      resp = max (resp, p[i]);
    }
    
    for (la = 1; la < resp; la++) {
      special = 0;
      for (i = 0; i < d && (special + la) < resp; i++) {
        special += ceil (p[i] / (double) la) - 1;
      }
      resp = min (resp, special + la);
    }
    
    cout << "Case #" << caso << ": " << resp << endl;
  }
  
  
  
  return 0;
}





