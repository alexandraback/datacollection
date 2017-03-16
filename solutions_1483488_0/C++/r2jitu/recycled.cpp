#include <iostream>

using namespace std;

int countDigits(int x, int &mult) {
  int digits = 0;
  mult = 1;
  while (x > 0) {
    x /= 10;
    mult *= 10;
    digits++;
  }
  mult /= 10;
  return digits;
}

bool shiftNum(int digits, int mult, int &m) {
  int d = m % 10;
  m = (m / 10) + mult * d;
  return d != 0;
}

int main() {
  int T, A, B;

  cin >> T;

  for (int i=0; i<T; i++) {
    cin >> A >> B;

    int count = 0, n, m, mult;
    int digits = countDigits(A, mult);
    int shifts[10];
    
    for (n=A; n<=B; n++) {
      m = n;
      for (int shift=1; shift<digits; shift++) {
        shifts[shift] = 0;
        if (shiftNum(digits, mult, m)) {
          if (n < m && m <= B) {
            bool found = false;
            for (int k=1; k<shift; k++)
              if (shifts[k] == m)
                found = true;
            if (!found) {
              count++;
              shifts[shift] = m;
            }
          }
        }
      }
    }

    cout << "Case #" << i+1 << ": " << count << endl;
  }
}

