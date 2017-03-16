#include <iostream>
using namespace std;

int transform(int n, int bs) {
  int d = n % 10;
  int m = d * bs + n;
  return m / 10;
}

int main() {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int A, B; cin >> A >> B;
    int bs = 10;
    while (bs <= B) bs *= 10;
    int x = 0;
    for (int n = A; n <= B; n++) {
      int m = n;
      do {
        m = transform(m, bs);
        if (n < m && m <= B) x++;
      } while (m != n);
    }
    cout << "Case #" << t << ": " << x << endl;
  }
  return 0;
}

