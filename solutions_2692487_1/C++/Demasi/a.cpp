#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

typedef long long huge;

#define MAX 128
huge v[MAX];

int main(void)
{
  huge T, A, N;

  scanf("%lld", &T);
  for(int caso = 1; caso <= T; caso++)
  {
    printf("Case #%d: ", caso);

    scanf("%lld %lld", &A, &N);
    for(int i = 0; i < N; i++)
      scanf("%lld", v+i);
    sort(v, v+N);
    
    huge r = N;
    if (A > 1)
    {
      for(int i = 0; i < N; i++)
      {
        huge t = i;
        huge a = A;
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

    printf("%lld\n", r);
  }
}
