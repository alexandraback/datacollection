#include<stdio.h>

int main(int argc, char** argv)
{
  int T, t, N, n, S, p;

  scanf("%d\n", &T);

  for(t = 1; t <= T; t++)
    {
      int y = 0;

      scanf("%d %d %d ", &N, &S, &p);

      for(n = 0; n < N; n++)
	{
	  int ti;

	  scanf("%d", &ti);

	  switch(ti % 3)
	    {
	    case 0:
	      if (ti / 3 >= p)
		y++;
	      else if (ti / 3 + 1 == p && S > 0 && ti / 3 > 0 && ti / 3 < 10)
		y++, S--;
	      break;
	    case 1:
	      if (ti / 3 + 1 >= p && ti / 3 < 10)
		y++;
	      break;
	    case 2:
	      if (ti / 3 + 1 >= p && ti / 3 < 10)
		y++;
	      else if (ti / 3 + 2 == p && S > 0 && ti / 3 < 9)
		y++, S--;
	      break;
	    }
	}

      printf("Case #%d: %d\n", t, y);
    }
}
