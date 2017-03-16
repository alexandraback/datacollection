#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define MAX 128
int v[MAX];

int main(void)
{
  int T, A, N;

  scanf("%d", &T);
  for(int caso = 1; caso <= T; caso++)
  {
    printf("Case #%d: ", caso);

    scanf("%d %d", &A, &N);
    for(int i = 0; i < N; i++)
      scanf("%d", v+i);
    sort(v, v+N);
    
    int r = N;
    if (A > 1)
    {
      for(int i = 0; i < N; i++)
      {
        int t = i;
        int a = A;
        for(int j = 0; j < N-i && t < N; j++)
        {
          while(A <= v[j])
          {
            A += (A-1);
            t++;
          }
          A += v[j];
        }
        A = a;

        r = min(r,t);
      }
    }

    printf("%d\n", r);
  }
}
