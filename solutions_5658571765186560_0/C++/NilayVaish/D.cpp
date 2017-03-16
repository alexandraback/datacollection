#include <cstdio>

int main()
{
  int T; scanf("%d\n", &T); for (int ii = 1; ii <= T; ++ii)
  {
    int X, R, C; scanf("%d %d %d\n", &X, &R, &C);

    if ((R * C) % X != 0)
    {
      printf("Case #%d: RICHARD\n", ii);
      continue;
    }

    if (X == 1 || X == 2) printf("Case #%d: GABRIEL\n", ii);
    else if (X == 3)
    {
      if (R == 1 || C == 1)
      {
        printf("Case #%d: RICHARD\n", ii);
        continue;
      }
      printf("Case #%d: GABRIEL\n", ii);
    }
    else if (X == 4)
    {
      if (R == 4 || C == 4)
      {
        if (R == 1 || R == 2 || C == 1 || C == 2)
        {
          printf("Case #%d: RICHARD\n", ii);
          continue;
        }
        printf("Case #%d: GABRIEL\n", ii);
      }
      else
      {
        printf("Case #%d: RICHARD\n", ii);
        continue;
      }
    }
  }
  return 0;
}
