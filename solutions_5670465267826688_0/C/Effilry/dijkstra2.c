#include <stdio.h>
#include <string.h>

long min(long a, long b) { return a < b? a : b; }

const char *symbols = "1ijk";
enum { _1 = 0, _I = 1, _J = 2, _K = 3 };
enum { PLUS  = 0, MINUS = 1 };

int mul_magn(int a, int b) {
  int sgn = a % 2? -1 : +1;
  return (a + sgn * b + 4) % 4;
}
int mul_sign(int a, int b) {
  return (a == 1 && (b == 1 || b == 3)) ||
         (a == 2 && (b == 1 || b == 2)) ||
         (a == 3 && (b == 2 || b == 3));
}

int read(char ch) {
  for (int i = 0; symbols[i]; i++) if (ch == symbols[i]) return i;
  return -1;
}

int solve(const char *str, long X) {
  int L = strlen(str);

  long i    = 0,
       last = 0;

  const char *chars = "ijk";
  for (const char *p = chars; *p != '\0'; p++) {
    int sym = read(*p);
    last = i;

    int curr_magn = _1,
        curr_sign = 0;
    do {
      int v = read(str[i % L]);
      curr_sign ^= mul_sign(curr_magn, v);
      curr_magn = mul_magn(curr_magn, v);
      i++;
    } while ((curr_magn != sym || curr_sign != 0) && i < L * X);

    // In case we couldn't construct the right letter, bail
    if (curr_magn != sym || curr_sign != 0) return 0;
  }

  // Eat rest of input, assert that it is 1
  last = i;
  int curr_magn = _1,
      curr_sign = 0;
  while (i < L * X) {
    int v = read(str[i % L]);
    curr_sign ^= mul_sign(curr_magn, v);
    curr_magn = mul_magn(curr_magn, v);
    i++;
  }

  return curr_magn == _1 && curr_sign == 0;
}


int main(void) {
  int N;
  scanf("%d", &N);
  getchar();

  char buf[10001];

  for (int n = 1; n <= N; n++) {
    long L, X;
    scanf("%ld %ld\n%s", &L, &X, buf);
    printf("Case #%d: %s\n", n, solve(buf, X)? "YES" : "NO");
  }
}
