#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int foi[10], achou;

void marca(int q, int c)
{
  if (foi[q] < c)
  {
    achou += (c - foi[q]);
    foi[q] = c;
  }
}

int main(void)
{
  int T;

  scanf("%d", &T);
  for(int caso = 1; caso <= T; caso++)
  {
    printf("Case #%d:\n", caso);

    int R,N,M,K;
    scanf("%d %d %d %d", &R, &N, &M, &K);

    for(int i = 0; i < R; i++)
    {
      memset(foi, 0, sizeof(foi));
      achou = 0;
      for(int j = 0; j < K; j++)
      {
        int v, x;
        scanf("%d", &v);

        x = 6561;
        for(int c = 8; c > 0; c--)
        {
          if (v%x == 0)
          {
            marca(3,c);
            break;
          }
          x /= 3;
        }

        x = 390625;
        for(int c = 8; c > 0; c--)
        {
          if (v%x == 0)
          {
            marca(5,c);
            break;
          }
          x /= 5;
        }

        if (v%2 == 0 && v%4 != 0) marca(2,1);
        else if (v%2 == 0 && v%4 == 0)
        {
          x = 0;
          int k = v;
          while(k%2 == 0 && k > 0)
          {
            x++;
            k /= 2;
          }
          marca(4, x/2);
          if (x%2 == 1) marca(2, 1);
        }
      }

      for(int i = 0; i < 10; i++)
        for(int j = 0; j < foi[i]; j++)
          printf("%d", i);
      while(achou < N)
      {
        printf("%d", (rand()%(M-1))+2);
        achou++;
      }
      printf("\n");
    }
  }
}
