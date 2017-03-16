#include <cstdio>
#include <stdint.h>
#include <gmpxx.h>
using namespace std;

typedef int64_t i64;
typedef uint64_t u64;

#define FOR(i, a, b) for (long i = (a); i < (b); i++)
#define REP(i, n) for (long i = 0; i < (n); i++)
#define REP1(i, n) for (long i = 1; i <= (n); i++)
#define ROF(i, a, b) for (long i = (b); --i >= (a); )

int ri()
{
  int x;
  scanf("%d", &x);
  return x;
}

bool miller_rabin(mpz_class n)
{
  if (n < 2) return false;
  long primes[] = {2,3,5,7,11,0};
  for (long *a = primes; *a; a++) {
    mpz_class x = n-1;
    long t = 0;
    while (x % 2 == 0)
      x >>= 1, t++;
    x = x * *a % n;
    if (x == 1 || x == n-1) return true;
    REP(i, t-1) {
      x = x * x % n;
      if (x == 1) return false;
      if (x == n-1) return true;
    }
  }
  return false;
}

mpz_class pollard_rho(mpz_class n, long c)
{
  for (long i = 2; i < 10; i++)
    if (mpz_divisible_ui_p(n.get_mpz_t(), i))
      return i;
  mpz_class x = 2, y = 2, d = 1;
  while (d == 1) {
    x = (x * x + c) % n;
    y = (y * y + c) % n;
    y = (y * y + c) % n;
    d = gcd(x > y ? x-y : y-x, n);
  }
  return d;
}

mpz_class f(long x, long n, long b)
{
  mpz_class y = 0;
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
    REP(i, 1L << n-2) {
      long x = (1L<<n-1) + (long(i)<<1) + 1;
      bool tak = true;
      FOR(b, 2, 11) {
        mpz_class y = f(x, n, b);
        //if (miller_rabin(y)) {
        if (mpz_probab_prime_p(y.get_mpz_t(), 5)) {
          tak = false;
          break;
        }
      }
      if (tak) {
        mpz_out_str(stdout, 10, f(x, n, 10).get_mpz_t());
        FOR(b, 2, 11) {
          long c = 73;
          mpz_class y = f(x, n, b), z = y;
          for (long i = 2; i < 10; i++)
            if (y%i == 0) {
              z = i;
              break;
            }
          while (z == y)
            z = pollard_rho(y, c--);
          //printf(" %ld", f(x,n,b));
          putchar(' ');
          mpz_out_str(stdout, 10, z.get_mpz_t());
        }
        puts("");
        if (! --m) break;
      }
    }
  }
}
