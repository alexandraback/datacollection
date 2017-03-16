#include <stdio.h>

long long divisor(long long ll)
{
  long long n;

  for(n=3;n<10000;n+=2) {
    if ((ll % n) == 0) {
      return n;
    }
  }
  return 0;
}

long long base(long long j, long long k)
{
  long long ret, n;
  long long i;

  ret = 0;

  n = 1;
  for(i=0;i<40;i++) {
    ret = ret + n*((j >> i) & 1);
    n *= k;
  }

  return ret;
}

int
main(int argc, char **argv)
{
  int T, N, J;
  long long i, j, k, flag;
  long long ll;
  long long div[11];

  scanf("%d", &T);
  for(i=1;i<=T;i++) {
    scanf("%d %d", &N, &J);
    printf("Case #%lld:\n", i);
    for(j=(1LL << (N-1))+1;j<(1LL << N);j+=2) {
      flag = 1;
      for(k=2;k<=10;k++) {
	ll = base(j, k);
	div[k] = divisor(ll);
	if (div[k] == 0) {
	  flag = 0;
	  break;
	}
      }
      if (!flag)
	continue;
      for(k=N-1;k>=0;k--) {
	printf("%lld", (j >> k) & 1);
      }
      for(k=2;k<=10;k++) {
	printf(" %lld", div[k]);
      }
      printf("\n");
      J--;
      if (J == 0)
	break;
    }
  }
  return 0;
}
