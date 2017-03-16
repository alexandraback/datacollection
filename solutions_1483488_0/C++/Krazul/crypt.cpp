#include <iostream>
#include <string>

using namespace std;

int t;
int a, b;
int digits;
int result;

int cycle(int n) {
  int last = n % 10;
  n /= 10;
  for (int i = 1; i < digits; ++i) last *= 10;
  return n + last;
}

int main () {
  cin >> t;
  for (int ii = 1; ii <= t; ++ii) {
    cout << "Case #" << ii << ": ";

    cin >> a >> b;

    digits = 0;
    int curr = a;
    while (curr) {
      curr /= 10;
      ++digits;
    }

    result = 0;
    for (int i = a; i <= b; ++i) {
      for (int curr = cycle(i); curr != i; curr = cycle(curr)) {
        if (curr > i && a <= curr && curr <= b) {
          ++result;
        }
      }
    }

    cout << result << endl;
  }
  return 0;
}