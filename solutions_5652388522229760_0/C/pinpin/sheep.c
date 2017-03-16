#include <stdio.h>

int
main(int argc, char **argv)
{
  int T, N, NN;
  int i, j;
  int mask;

  scanf("%d", &T);
  for(i=1;i<=T;i++) {
    scanf("%d", &N);
    if (N == 0) {
      printf("Case #%d: INSOMNIA\n", i);
      continue;
    }
    mask = 0;
    for(j=1;;j++) {
      NN = N*j;
      while (NN > 0) {
	mask |= (1 << (NN % 10));
	NN /= 10;
      }
      if (mask == 0x3ff)
	break;
    }
    printf("Case #%d: %d\n", i, N*j);
  }
  return 0;
}
