#include <iostream>

using namespace std;

int gcd ( int a, int b ) {
  int c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

int main() {
    int cases,x,y,g,ans;
    char a;
    cin >> cases;
    for (int caseno = 1; caseno <= cases; caseno++) {
        cout << "Case #" << caseno << ": ";
        cin >> x >> a >> y;
        g = gcd (x,y);
        x/=g;
        y/=g;
        ans = 0;
        while (y % 2 == 0) {
            if (x < y) {
                ans++;
            }
            y/=2;
        }
        if (y == 1) {
            cout << ans << endl;
        } else {
            cout << "impossible" << endl;
        }
    }
}