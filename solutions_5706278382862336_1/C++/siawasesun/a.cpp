#include <bits/stdc++.h>

using namespace std;

int64_t P, Q;
const int64_t INF = 1024;

template<typename T> inline T _GCD(T a, T b) { return __gcd(a, b); }
#define GCD(a, b) _GCD<__typeof(a)>((a),(b))
template<typename T> inline T _LCM(T a, T b) { return a / _GCD<T>(a, b) * b; }
#define LCM(a, b) _LCM<__typeof(a)>((a),(b))

void Input() {
  char tmp;
  cin >> P >> tmp >> Q;
  int64_t gcd = GCD(P, Q);
  P /= gcd;
  Q /= gcd;
}

bool Check(int64_t q) {
  while (q > 1) {
    if (q % 2 != 0) {
      return false;
    }
    q /= 2;
  }
  return true;
}

void Solve() {
  if (!Check(Q)) {
    printf("impossible");
    return;
  }

  if (P == Q) {
    printf("0");
    return;
  }

  int64_t R = Q - P;
  int64_t sum = 1;
  int64_t current = Q / 2;
  int res = 1;
  while (true) {
    sum += current;
    if (R < sum) {
      break;
    }
    res++;
    current /= 2;
  }
  printf("%d", res);
}

int main(int argc, char **argv) {
  int T;
  scanf("%d", &T);

  for (int test_case = 1; test_case <= T; ++test_case) {
    Input();
    printf("Case #%d: ", test_case);
    Solve();
    printf("\n");
  }
  return 0;
}
