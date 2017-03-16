#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int foi[10], achou;
int R,N,M,K;

void marca(int q, int c)
{
  if (foi[q] < c)
  {
    achou += (c - foi[q]);
    foi[q] = c;
    if (achou > N)
    {
      foi[q] -= (achou-N);
      achou = N;
    }
  }
}

int main(void)
{
  int T;

  srand(time(NULL));

  scanf("%d", &T);
  for(int caso = 1; caso <= T; caso++)
  {
    printf("Case #%d:\n", caso);

    scanf("%d %d %d %d", &R, &N, &M, &K);

    for(int i = 0; i < R; i++)
    {
      memset(foi, 0, sizeof(foi));
      achou = 0;
      for(int j = 0; j < K; j++)
      {
        int v, x;
        scanf("%d", &v);

        x = 1594323;
        for(int c = 13; c > 0; c--)
        {
          if (v%x == 0)
          {
            marca(3,c);
            break;
          }
          x /= 3;
        }

        x = 244140625;
        for(int c = 12; c > 0; c--)
        {
          if (v%x == 0)
          {
            marca(5,c);
            break;
          }
          x /= 5;
        }

        x = 282475249;
        for(int c = 10; c > 0; c--)
        {
          if (v%x == 0)
          {
            marca(7,c);
            break;
          }
          x /= 7;
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
