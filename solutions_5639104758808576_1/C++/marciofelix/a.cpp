#include <bits/stdc++.h>

using namespace std;


int main () {
  ios_base::sync_with_stdio(false);
  int t, i, vm, caso, amigos, depe;
  char s[1010];
  
  cin >> t;
  
  for (caso = 1; caso <= t; caso++) {
    cin >> vm >> s;
    amigos = 0;
    depe = 0;
    
    for (i = 0; i <= vm; i++) {
      if (depe < i) {
        amigos += (i - depe);
        depe = i;
      }
      depe += s[i] - '0';
    }
    
    cout << "Case #" << caso << ": " << amigos << endl;
  }
  
  return 0;
}










