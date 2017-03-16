#include <iostream>
using namespace std;

#define _ long long

_ divisor(_ n) {
  for (_ k = 2; k < n && k < 10000; k++) {
    if (n % k == 0) {
      return k;
    }
  }
  return 0;
}

bool is_prime(_ n) {
  return divisor(n) == 0;
}

_ in_base(_ i, _ b) {
  _ d = 1;
  _ o = 0;

  while (i) {
    _ a = i % 2;

    o += a * d;

    i /= 2;
    d *= b;
  }

  return o;
}

int main() {

  _ N = 16;
  _ J = 50;

  _ a[N];

  _ x, d;

  _ y = (1 << 16) + 1;
    cout << "Case #1:\n";
  while(J > 0) {

    for (_ i = 2; i <= 10; i++) {
      if (is_prime(in_base(y, i))) {
        goto next;
      }
    }

    d = 1 << 16;
    while(d) {
      cout << (y / d) % 2;
      d >>= 1;
    }
    cout << " ";
    for (_ i = 2; i <= 9; i++) {
      cout << divisor(in_base(y, i)) << " ";
    }
    cout << divisor(in_base(y, 10)) << endl;
    J--;
  next:
    y += 2;
  }

  return 0;
}
