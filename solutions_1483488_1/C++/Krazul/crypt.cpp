#include <iostream>
#include <string>

using namespace std;

int t;
unsigned long long a, b;
int digits;
unsigned long long result;

unsigned long long cycle(unsigned long long n) {
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
    unsigned long long curr = b;
    while (curr) {
      curr /= 10;
      ++digits;
    }

    result = 0;
    for (unsigned long long i = a; i <= b; ++i) {
      for (unsigned long long curr = cycle(i); curr != i; curr = cycle(curr)) {
        if (curr > i && a <= curr && curr <= b) {
          ++result;
        }
      }
    }

    cout << result << endl;
  }
  return 0;
}