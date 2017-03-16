#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
typedef long long i64;

char digits[200];

bool is_fair(i64 x) {
  int len = 0;
  i64 y = x;
  while (y) {
    digits[len++] = y % 10;
    y /= 10;
  }
  int k = len / 2;
  for (int i = 0; i < k; ++i)
    if (digits[i] != digits[len - i - 1])
      return false;
  return true;
}

int num_digits(i64 x) {
  int len = 0;
  while (x) {
    x /= 10;
    ++len;
  }
  return len;
}

i64 fair(i64 x, int o) {
  int len = 0;
  i64 y = x;
  while (y) {
    digits[len++] = y % 10;
    y /= 10;
  }
  for (int k = o; k < len; ++k) {
    x *= 10;
    x += digits[k];
  }
  return x;
}

struct Pal {
  i64 val;
  int len;
  bool operator<= (const Pal& o) {
    if (len == o.len)
      return val <= o.val;
    else
      return len < o.len;
  }
};

void incr(Pal& x) {
  int k = num_digits(++x.val);
  if (k > (x.len + 1) / 2) {
    if (x.len % 2 != 0) {
      x.val /= 10;
    }
    ++x.len;
  }
}

void decr(Pal& x) {
  int k = num_digits(--x.val);
  if (k < (x.len + 1) / 2) {
    if (x.len % 2 == 0) {
      x.val *= 10;
      x.val += 9;
    }
    --x.len;
  }
}

i64 pal_to_int(Pal x) {
  return fair(x.val, x.len % 2);
}

Pal int_to_pal(i64 i) {
  //fprintf(stderr, "int_to_pal: %lld\n", i);
  Pal x;
  x.len = num_digits(i);
  x.val = i;
  for (int k = x.len / 2; k; --k) {
    x.val /= 10;
  }
  //fprintf(stderr, "val=%lld, len=%d\n", x.val, x.len);
  return x;
}

Pal prev_pal(i64 x) {
  Pal p = int_to_pal(x);
  i64 z = pal_to_int(p);
  //fprintf(stderr, "prev_pal(%lld): z=%lld\n", x, z);
  if (z > x)
    decr(p);
  return p;
}

Pal next_pal(i64 x) {
  Pal p = int_to_pal(x);
  i64 z = pal_to_int(p);
  //fprintf(stderr, "next_pal(%lld): z=%lld\n", x, z);
  if (z < x)
    incr(p);
  return p;
}

int main() {
  int num_tests = 0;
  scanf("%d", &num_tests);
  for (int test = 1; test <= num_tests; ++test) {
    i64 a, b;
    scanf("%lld%lld", &a, &b);
    fprintf(stderr, "a=%lld, b=%lld\n", a, b);
    i64 count = 0;
    Pal p = next_pal(ceil(sqrt(a)));
    Pal e = prev_pal(floor(sqrt(b) + 1e-100));
    fprintf(stderr, "[%lld, %lld]\n", pal_to_int(p), pal_to_int(e));
    for (; p <= e; incr(p)) {
      i64 s = pal_to_int(p);
      //fprintf(stderr, "%lld^2=", s);
      s *= s;
      //fprintf(stderr, "%lld\n", s);
      if (is_fair(s)) {
        fprintf(stderr, "%lld is fair and square\n", s);
        ++count;
      }
    }
    printf("Case #%d: %lld\n", test, count);
  }
  return 0;
}
