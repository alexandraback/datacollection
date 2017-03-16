#include <cstdio>
#include <array>
#include <cinttypes>
#include <random>

__int128 divisor(__int128 n)
{
  //for (__int128 p = 2; p * p < n; ++p) {
  for (__int128 p = 2; p < 10000; ++p) {
    if (n % p == 0)
      return p;
  }
  return 0;
}

void display(__int128 N, __int128 i)
{
  __int128 bit = 1 << (N - 3);
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
  std::array<__int128, 12> divisors {};
  scanf("%ld ", &T);
  for (__int128 i = 0; i < T; ++i) {
    long N, J;
    scanf("%ld %ld ", &N, &J);
    printf("Case #%ld: \n", i + 1);

    __int128 nb = 0;
    for (__int128 i = 0; i < (1 << (N - 2)); ++i) {
      bool bad = false;
      for (int b = 2; b < 11; ++b) {
	__int128 coin = 1;
	for (int k = N - 3; k >= 0; --k) {
	  __int128 bit = 1 << k;
	  coin = coin * b + ((i & bit) >> k);
	}
	coin = coin * b + 1;
	if (coin < 0) {
	  printf("%d\n", b);
	  exit(1);
	}
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
