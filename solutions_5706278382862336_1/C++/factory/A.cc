#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

inline __int64 Calc2To40() {
  __int64 res = 1;
  for (int i = 0; i < 40; ++i) {
    res <<= 1;
  }
  return res;
}

inline bool IsPowerOf2(__int64 x) {
  return !(x == 0) && !(x & (x - 1));
}

inline int FindMinGen(__int64 p, __int64 q, int n) {
  if (p * 2 < q) {
    return FindMinGen(p * 2, q, n + 1);
  }
  return n;
}

/*
__int64 GetInt64() {
  char a;
  __int64 res = 0;
  bool read = false;
  while (scanf("%c", &a) == 1) {
    if (a == '/' || a == '\n') {
      if (!read) {
        continue;
      }
      return res;
    }
    if (a >= '0' && a <= '9') {
      res = res * 10 + (a - '0');
      read = true;
    }
  }
  return res;
}
*/

int main() {
  const __int64 twoto40 = Calc2To40();

  int T = 0;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    //__int64 P = GetInt64();
    //__int64 Q = GetInt64();
    __int64 P = 0;
    __int64 Q = 0;
    scanf("%I64d/%I64d", &P, &Q);

    if (P > Q) {
      printf("Case #%d: impossible\n", t);
      continue;
    }

    __int64 a = Q;
    {
      __int64 b = P, c = 0;
      do {
        c = a % b;
        a = b;
        b = c;
      } while (b != 0);
    }

    P /= a;
    Q /= a;

    if (Q > twoto40 || !IsPowerOf2(Q)) {
      printf("Case #%d: impossible\n", t);
      continue;
    }

    printf("Case #%d: %d\n", t, FindMinGen(P, Q, 1));
  }
  return 0;
}
