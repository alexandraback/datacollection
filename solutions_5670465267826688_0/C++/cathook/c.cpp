#include <stdio.h>

#include <algorithm>


const int O = 1, I = 2, J = 3, K = 4;

int Mult(int a, int b) {
  int f = 1;
  if (a < 0) {
    f *= -1;
    a *= -1;
  }
  if (b < 0) {
    f *= -1;
    b *= -1;
  }
  if (a == O) return f * b;
  if (b == O) return f * a;
  if (a == I && b == I) return f * -O;
  if (a == I && b == J) return f *  K;
  if (a == I && b == K) return f * -J;
  if (a == J && b == I) return f * -K;
  if (a == J && b == J) return f * -O;
  if (a == J && b == K) return f *  I;
  if (a == K && b == I) return f *  J;
  if (a == K && b == J) return f * -I;
  if (a == K && b == K) return f * -O;
}

const int LMAX = 10000;

char str[LMAX + 2];

int sum[8 * LMAX + 1];

int main() {
  int num_cases, case_i;
  for (scanf("%d", &num_cases), case_i = 1; case_i <= num_cases; ++case_i) {
    long long len, times;
    scanf("%lld %lld %s", &len, &times, str + 1);

    long long chklen = len * std::min(8LL, times);
    sum[0] = O;
    for (int ct = 1; ct <= chklen; ++ct) {
      int i = (ct - 1) % len + 1;
      sum[ct] = Mult(sum[ct - 1], str[i] - 'i' + I);
    }

    bool ok = true;
    if (sum[len] == O) {
      ok = false;
    } else if (sum[len] == -O) {
      ok = (times % 2 == 1);
    } else {
      ok = (times % 4 == 2);
    }

    if (ok) {
      int left_i;
      for (left_i = 1; left_i <= chklen; ++left_i) {
        if (sum[left_i] == I) {
          break;
        }
      }
      int right_k;
      for (right_k = chklen; 1 <= right_k; --right_k) {
        if (sum[right_k] == K) {
          break;
        }
      }
      ok = (left_i < right_k);
    }

    printf("Case #%d: %s\n", case_i, ok ? "YES" : "NO");
  }
  return 0;
}
