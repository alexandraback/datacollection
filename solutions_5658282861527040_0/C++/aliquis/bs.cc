#include <cstdio>

int main()
{
  int T;
  scanf("%d", &T);
  for (int t=1; t<=T; ++t) {
    int A, B, K;
    scanf("%d%d%d", &A, &B, &K);
    int sum=0;
    for (int a=0; a<A; ++a)
      for (int b=0; b<B; ++b)
	if ((a&b) < K)
	  ++sum;
    printf("Case #%d: %d\n", t, sum);
  }
  return 0;
}
