#include <iostream>

using namespace std;

long long gcd ( long long a, long long b ) {
  long long c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

int main() {
    long long cases,x,y,g,ans;
    char a;
    cin >> cases;
    for (long long caseno = 1; caseno <= cases; caseno++) {
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