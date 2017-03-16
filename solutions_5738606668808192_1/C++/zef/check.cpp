#include <iostream>
#include <cstdio>
#include <algorithm>

typedef long long int big;

using namespace std;

bool interp(string n, int b, int d) {
  int t = 0, m = 1;
  for (int i = n.length() - 1; i >= 0; i--) {
    t = (t + m * (n[i] - '0')) % d;
    m = m * b % d;
  }
  return t % d == 0;
}

int main () {
  string n;
  int d;
  while (cin >> n) {
    bool good = true;
    for (int b = 2; b <= 10; b++) {
      cin >> d;
      good &= interp(n, b, d);
    }
    printf("%s: %s\n", n.c_str(), good ? "YES" : "NO");
  }
}
