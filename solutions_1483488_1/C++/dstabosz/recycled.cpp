#include <stdio.h>
#include <assert.h>
#include <cstring>
#include <vector>

using namespace std;

int debug = 0;

int verbose = 10;

int main(int argc, char *argv[])
{
  int T;
  int A, B;
  int a;

  assert(scanf( "%d", &T) == 1);

  for (int t = 1; t <= T; t++)
  {
    int count = 0;
     int digits = 0;
     int scale = 1;

    printf ("Case #%d: ", t);
    assert(scanf("%d %d", &A, &B) == 2);
    a = A;
    while (a > 0)
    {
      digits++;
      a /= 10;
      if (a > 0)
        scale *= 10;
    }

    if (debug)
      printf("\nA %d B %d digits %d scale %d\n", A, B, digits, scale);

    for (int i = A; i <= B; i++)
    {
       int n;
       int list[8];
       int listIdx = 0;

       n = i;

       for (int j = 1; j < digits; j++)
       {
          int d = n % 10;
	  n /= 10;
	  n += d * scale;

          if ((verbose > 0) && (debug))
	  {
            printf ("%d] %d %d\n", j, i, n);
	    verbose--;
	  }

	  if ((n > i) && (n <= B))
	  {
	    bool repeat = false;

	    for (int k = 0; k < listIdx; k++)
	    {
              if (list[k] == n)
	        repeat = true;
	    }

	    if (!repeat)
	    {
	      list[listIdx++] = n;
	      count++;
	    }

          }
       }
       
    }

    printf ("%d\n", count);
  }

}
