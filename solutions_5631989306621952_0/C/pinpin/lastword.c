#include <stdio.h>

int
main(int argc, char **argv)
{
  int T;
  char S[2000];
  char SS[3000];
  int i, j, k;
  int head, tail;

  scanf("%d", &T);
  for(i=1;i<=T;i++) {
    scanf("%s", &S);
    memset(SS, 0, sizeof(SS));
    head = tail = 1500;
    SS[head] = S[0];
    for(j=1;S[j];j++) {
      if (S[j] >= SS[head]) {
	SS[head-1] = S[j];
	head--;
      } else {
	SS[tail+1] = S[j];
	tail++;
      }
    }
    for(j=0;j<3000;j++) {
      if (SS[j])
	break;
    }
    printf("Case #%d: %s\n", i, &SS[j]);
  }
  return 0;
}

