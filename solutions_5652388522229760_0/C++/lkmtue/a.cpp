#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int ntest;
  cin >> ntest;

  for (int test = 1; test <= ntest; test++) {
    int n;
    cin >> n;

    cout << "Case #" << test << ": ";
    if (n == 0) {
      cout << "INSOMNIA" << endl;
    } else {
      vector<bool> d(10, false);

      int x = n;
      while (1) {
        int y = x;
        while (y) {
          d[y % 10] = true;
          y /= 10;
        }
        bool ok = true;
        for (int i = 0; i < 10; i++) {
          if (!d[i]) {
            ok = false;
          }
        }
        if (ok) {
          break;
        }
        x += n;
      }

      cout << x << endl;
    }
  }
}
