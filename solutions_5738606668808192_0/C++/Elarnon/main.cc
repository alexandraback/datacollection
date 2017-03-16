#include <cstdio>
#include <array>

long divisor(long n)
{
  for (long p = 2; p * p < n; ++p) {
    if (n % p == 0)
      return p;
  }
  return 0;
}

void display(long N, long i)
{
  long bit = 1 << (N - 3);
  printf("1");
  for (int k = N - 3; k >= 0; --k) {
    printf("%c", '0' + ((i & bit) >> k));
    bit >>= 1;
  }
  printf("1 ");
}

int main()
{
  long T;
  std::array<long, 12> divisors {};
  scanf("%ld ", &T);
  for (long i = 0; i < T; ++i) {
    long N, J;
    scanf("%ld %ld ", &N, &J);
    printf("Case #%ld: \n", i + 1);

    long nb = 0;
    for (long i = 0; i < (1 << (N - 2)); ++i) {
      bool bad = false;
      for (int b = 2; b < 11; ++b) {
	long coin = 1;
	for (int k = N - 3; k >= 0; --k) {
	  long bit = 1 << k;
	  coin = coin * b + ((i & bit) >> k);
	}
	coin = coin * b + 1;
	divisors[b] = divisor(coin);
	if (!divisors[b]) {
	  bad = true;
	  break;
	}
      }
      if (!bad) {
	++nb;
	display(N, i);
	for (int b = 2; b < 11; ++b)
	  printf("%ld ", divisors[b]);
	printf("\n");
      }
      if (nb == J)
	break;
    }
  }
  return 0;
}
