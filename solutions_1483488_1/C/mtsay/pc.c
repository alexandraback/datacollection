#include<stdio.h>

int m[10];
int mc = 0;

int next(int n, int hi)
{
  return (n % 10) * hi + n / 10;
}

void generate(int n)
{
  int hi = 1, cand;

  while (n / hi >= 10)
    hi *= 10;

  for(cand = next(n, hi), mc = 0; n != cand; cand = next(cand, hi))
    m[mc++] = cand;
}

int main(int argc, char** argv)
{
  int T, t, A, B, n, i;

  scanf("%d\n", &T);

  for(t = 1; t <= T; t++)
    {
      int y = 0;

      scanf("%d %d\n", &A, &B);

      for (n = A; n < B; n++)
	{
	  generate(n);

	  for (i = 0; i < mc; i++)
	    if (m[i] > n && m[i] <= B)
	      y++;
	}

      printf("Case #%d: %d\n", t, y);
    }
}
