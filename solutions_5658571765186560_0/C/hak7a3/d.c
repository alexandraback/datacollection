#include <stdio.h>
#include <stdlib.h>

#define WIN_G "GABRIEL"
#define WIN_R "RICHARD"


/* bad solusion ...orz */
void calc(int X, int R, int C)
{
  if(X == 1) {
    printf(WIN_G);
  } else if(X == 2) {
    if(R*C % 2 == 0) {
      printf(WIN_G);
    } else {
      printf(WIN_R);
    }
  } else if(X == 3) {
    if((R == 2 && C == 3) ||
       (R == 3 && C == 2) ||
       (R == 3 && C == 3) ||
       (R == 3 && C == 4) ||
       (R == 4 && C == 3)) {
      printf(WIN_G);
    } else {
      printf(WIN_R);
    }
  } else if(X == 4) {
    if((R == 3 && C == 4) ||
       (R == 4 && C == 3) ||
       (R == 4 && C == 4)) {
      printf(WIN_G);
    } else {
      printf(WIN_R);
    }
  } else {
    printf("???");
  }
  return;
}

int main()
{
  int T;
  scanf("%d", &T);

  int i;
  for (i = 0; i < T; i++) {
    printf("Case #%d: ", i + 1);

    int X, R ,C;
    scanf("%d %d %d", &X, &R, &C);
    calc(X, R, C);
    
    printf("\n");
  }

  
  return 0;
}

