#include <iostream>

using namespace std;

typedef unsigned long long ull;

int main() {
  int tc; cin >> tc;
  for (int t = 1; t <= tc; t++) {
    ull r, p; cin >> r >> p;
    
    ull c = 0;
    while (p > 0) {
      ull x = (r+1) * (r+1) - r * r;
      r += 2;
      if (x > p)
        break;
      c++;
      p -= x;
    }
        
    cout << "Case #" << t << ": ";
    cout << c;
    cout << endl;
  }

  return 0;
}
