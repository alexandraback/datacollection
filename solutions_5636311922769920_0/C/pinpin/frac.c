#include <stdio.h>

int
main(int argc, char **argv)
{
  int T, K, C, S, KK;
  int i, j, k;
  long long pos[200];

  scanf("%d", &T);
  for(i=1;i<=T;i++) {
    scanf("%d %d %d", &K, &C, &S);
    printf("Case #%d:", i);
    for(j=0;j<K;j++) {
      pos[j] = j;
    }
    for(k=1;k<C;k++) {
      for(j=0;j<K;j++) {
	pos[j] = pos[j]*K+j;
      }
    }
    for(j=0;j<K;j++) {
      printf(" %lld", pos[j]+1);
    }
    printf("\n");
  }
  return 0;
}
