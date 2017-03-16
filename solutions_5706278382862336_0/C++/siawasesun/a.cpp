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
  vector<int> count(Q + 1, -1);
  count[0] = INF;
  count[Q] = 0;

  for (int i = 0; i < 40; i++) {
    for (int i = 0; i <= Q; i++) {
      if (count[i] == -1) continue;
      for (int j = i + 1; j <= Q; j++) {
        if (count[j] == -1) continue;
        if ((i + j) % 2 == 1) continue;
        int to = (i + j) / 2;
        if (count[to] == -1) {
          count[to] = min(count[i], count[j]) + 1;
        } else {
          count[to] = min(count[to], min(count[i], count[j]) + 1);
        }
      }
    }
  }

  if (count[P] == -1) {
    printf("impossible");
  } else {
    printf("%d", count[P]);
  }
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
