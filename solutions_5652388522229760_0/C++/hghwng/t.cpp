#include <iostream>
#include <cstdio>
#include <cstdint>
using namespace std;
using ull = unsigned long long;

int count(bool ok[10]) {
  int n_ok = 0;
  for (int i = 0; i < 10; ++i) n_ok += ok[i];
  return n_ok == 10;
}

void flag(ull in, bool ok[10]) {
  while (in) {
    ok[in % 10] = true;
    in /= 10;
  }
}

ull test(ull n) {
  bool ok[10] = {0};
  for (int i = 1; i < 100; ++i) {
    flag(n * i, ok);
    if (count(ok)) return i;
  }
  return 0;
}

int main() {
  int t;
  cin >> t;

  for (int i = 1; i <= t; ++i) {
    ull n;
    cin >> n;
    printf("Case #%d: ", i);
    ull r = test(n);
    if (r == 0) printf("INSOMNIA\n");
    else        printf("%llu\n", test(n) * n);
  }
  return 0;
}
