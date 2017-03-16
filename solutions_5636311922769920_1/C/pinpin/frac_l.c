#include <stdio.h>

int
main(int argc, char **argv)
{
  int T, K, C, S, KK;
  int i, j, k, c;
  long long pos;

  scanf("%d", &T);
  for(i=1;i<=T;i++) {
    scanf("%d %d %d", &K, &C, &S);
    printf("Case #%d:", i);
    if ((C*S) < K) {
      printf(" IMPOSSIBLE\n");
      continue;
    }

    for(j=0;j<K;j+=C) {
      pos = j;
      for(k=1;k<C;k++) {
	pos = pos*K+(((j+k) < (K-1)) ? (j+k) : (K-1));
      }
      printf(" %lld", pos+1);
    }
    printf("\n");
  }
  return 0;
}
