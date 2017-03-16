#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void one_case(int t) {
  int i, P, Q, num;
  scanf("%d/%d", &P, &Q);
  printf("Case #%d: ", t+1);
  if(P == Q) {
    printf("1\n");
    return;
  }

  num = -1;
  for(i = 0; i < 40; i++) {
    if(Q == P) {
      if(num == -1)
        num = i;
      break;
    }
    else if(P > Q) {
      P = P % Q;
      if(num == -1)
        num = i;
    }

    P *= 2;
  }

  if(P == Q)
    printf("%d\n", num);
  else
    printf("impossible\n");
}

int main(void) {
  int i, t;
  scanf("%d", &t);
  for(i = 0; i < t; i++) {
    one_case(i);
  }
}
