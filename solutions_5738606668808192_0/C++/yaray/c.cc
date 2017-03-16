#include <cstdio>
#include <cstdint>
using namespace std;

typedef int64_t i64;
typedef uint64_t u64;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define REP1(i, n) for (int i = 1; i <= (n); i++)
#define ROF(i, a, b) for (int i = (b); --i >= (a); )

int ri()
{
  int x;
  scanf("%d", &x);
  return x;
}

u64 mul_mod(u64 a, u64 b, u64 m)
{
  u64 x = a*b;
  u64 y = m*(u64)(double(a)*double(b)/m+0.5);
  u64 r = x-y;
  if ((i64)r < 0)
    r += m;
  return r;
}

long pow_mod(long a, long b, long mod)
{
  long r = 1;
  for (; b; b >>= 1) {
    if (b & 1)
      r = mul_mod(r, a, mod);
    a = mul_mod(a, a, mod);
  }
  return r;
}

bool miller_rabin(long n)
{
  if (n < 2) return false;
  long primes[] = {2,3,5,7,11,0};
  for (long *a = primes; *a; a++) {
    long x = n-1, t = 0;
    while (x % 2 == 0)
      x >>= 1, t++;
    x = pow_mod(*a, x, n);
    if (x == 1 || x == n-1) return true;
    REP(i, t-1) {
      x = mul_mod(x, x, n);
      if (x == 1) return false;
      if (x == n-1) return true;
    }
  }
  return false;
}

long gcd(long a, long b)
{
  long t;
  while (t = a%b, a = b, b = t);
  return a;
}

long pollard_rho(long n, int c)
{
  for (int i = 2; i < 10; i++)
    if (n%i == 0) return i;
  long x = 2, y = 2, d = 1;
  while (d == 1) {
    x = (mul_mod(x, x, n) + c) % n;
    y = (mul_mod(y, y, n) + c) % n;
    y = (mul_mod(y, y, n) + c) % n;
    d = gcd(x > y ? x-y : y-x, n);
  }
  return d;
}

long f(int x, int n, int b)
{
  long y = 0;
  ROF(j, 0, n) {
    y *= b;
    if (x>>j & 1)
      y++;
  }
  return y;
}

int main()
{
  int cases = ri();
  REP1(cc, cases) {
    int n = ri(), m = ri();
    printf("Case #%d:\n", cc);
    REP(i, 1 << n-2) {
      int x = (1<<n-1) + (i<<1) + 1;
      bool tak = true;
      FOR(b, 2, 11) {
        long y = f(x, n, b);
        if (miller_rabin(y)) {
          tak = false;
          break;
        }
      }
      if (tak) {
        printf("%ld", f(x, n, 10));
        FOR(b, 2, 11) {
          long y = f(x, n, b), c = 73, z = y;
          for (int i = 2; i < 10; i++)
            if (y%i == 0) {
              z = i;
              break;
            }
          while (z == y)
            z = pollard_rho(y, c--);
          //printf(" %ld", f(x,n,b));
          printf(" %ld", z);
        }
        puts("");
        if (! --m) break;
      }
    }
  }
}
