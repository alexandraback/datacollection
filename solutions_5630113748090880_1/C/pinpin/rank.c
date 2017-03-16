#include <stdio.h>

int
main(int argc, char **argv)
{
  int T, N, M;
  int i, j, k, x;
  int cnt[3000];
  int ret[100];

  scanf("%d", &T);
  for(i=1;i<=T;i++) {
    scanf("%d", &N);
    memset(cnt, 0, sizeof(cnt));
    for(j=0;j<(2*N-1);j++) {
      for(k=0;k<N;k++) {
	scanf("%d", &x);
	cnt[x]++;
      }
    }
    M = 0;
    for(j=0;j<3000;j++) {
      if (cnt[j] % 2) {
	ret[M] = j;
	M++;
      }
    }

    printf("Case #%d:", i);
    for(j=0;j<M;j++) {
      printf(" %d", ret[j]);
    }
    printf("\n");
  }
  return 0;
}

