#include <stdio.h>
#include <assert.h>
#include <cstring>
#include <vector>

using namespace std;

int debug = 0;

int main(int argc, char *argv[])
{
  int T;
  int N, S, p;
  int total[100];

  assert(scanf( "%d", &T) == 1);

  for (int t = 1; t <= T; t++)
  {
    int count = 0;
    printf ("Case #%d: ", t);
    assert(scanf("%d %d %d", &N, &S, &p) == 3);

    if (debug)
      printf("\nN %d S %d p %d\n", N, S, p);

    for (int n = 0; n < N; n++)
    {
      int tot;
      int maxS;
      int maxNotS;

      scanf("%d", &tot);
      
      switch(tot % 3)
      {
         case 0:
	 {
	   if (tot == 30)
	   {
             maxNotS = 10;
	     maxS = 10;
	   }
	   else if (tot == 0)
	   {
             maxNotS = 0;
	     maxS = 0;
	   }
	   else
	   {
             maxNotS = tot/3;
	     maxS = maxNotS+1;
	   }
         }
	   break;

	 case 1:
	 {
	   maxNotS = tot/3+1;
           maxS = -1;
         }
	 break;

         case 2:
	 {
           maxNotS = tot/3 + 1;
	   maxS = tot/3 + 2;
	 }
	 break;
       }

       if (debug)
         printf("S %d tot %d maxNotS %d maxS %d\n", S, tot, maxNotS, maxS);

       if (maxNotS >= p)
       {
         count++;
       }
       else
       {
         if (maxS >= p)
	 {
           if (S > 0)
	   {
             S--;
	     count++;
	   }
	 }
       }

      }
      printf ("%d\n", count);
    
  }

}
