#include <stdio.h>
int mSwap(int* a, int* b)
{
  int t = *a;
  *a = *b;
  *b = t;
}
int main()
{
  int T;
  int X, R, C;
  int i;

  scanf("%d",&T);
  for(i=0;i<T;i++){

    scanf("%d%d%d",&X, &R, &C);

    printf("Case #%d: ",i+1);
    if( R > C )
      mSwap( &R, &C );

    switch(X) {

    case 1: printf("GABRIEL"); break;
    case 2: 
      if( (R*C) % 2 == 0 )
	printf("GABRIEL");
      else
	printf("RICHARD");
      break;
    case 3:
      if( (R*C) % 3 == 0 && R > 1 )
	printf("GABRIEL");
      else
	printf("RICHARD");
      break;
    case 4:
      if( (R*C) % 4 == 0 && R > 2 )
	printf("GABRIEL");
      else
	printf("RICHARD");
      break;
    case 5:
      if( (R*C) % 5 == 0 && R > 2 )
	printf("GABRIEL");
      else
	printf("RICHARD");
      break;
    case 6:
      if( (R*C) % 6 == 0 && R > 3 )
	printf("GABRIEL");
      else
	printf("RICHARD");
      break;
    default: // bigger than 6
      printf("RICHARD");
      break;
    }
    printf("\n");
  }
}
