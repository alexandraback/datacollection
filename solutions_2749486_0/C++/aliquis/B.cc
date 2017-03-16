#include <cstdio>

int main()
{
  int T;
  scanf("%d", &T);
  for (int cases=1; cases<=T; ++cases) {
    int X, Y;
    scanf("%d%d", &X, &Y);
    printf("Case #%d: ", cases);
    if (X < 0) {
      for (int i=0; i>X; --i)
        printf("EW");
    } else {
      for (int i=0; i<X; ++i)
        printf("WE");
    }
    if (Y < 0) {
      for (int i=0; i>Y; --i)
        printf("NS");
    } else {
      for (int i=0; i<Y; ++i)
        printf("SN");
    }
    printf("\n");
  }
  return 0;
}
