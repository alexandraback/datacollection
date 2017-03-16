#include <cstdio>
#include <algorithm>
using namespace std;

typedef long double lod;

int N, X;
int S[209];

int W[2000009];

void printMask (int mask)
{
  bool first = true;
  for (int k = 0; k < N; (k++, mask /= 2))
    if (mask % 2 == 1)
    {
      if (first)
      {
        first = false;
        printf("%d", S[k]);
      }
      else
        printf(" %d", S[k]);
    }
  printf("\n");
}

int main()
{
  int T;
  scanf("%d", &T);
  for (int Ti = 1; Ti <= T; Ti++)
  {
    //input
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
      scanf("%d", &S[i]);
    
    //init
    for (int i = 0; i < N * 100000 + 9; i++)
      W[i] = 0;
    
    //do
    printf("Case #%d:\n", Ti);
    bool solution = false;
    for (int i = 1; i < 1 << N; i++)
    {
      int sum = 0;
      int mask = i;
      for (int k = 0; k < N; k++)
      {
        if (mask % 2 == 1)
          sum += S[k];
        mask /= 2;
      }
      
      if (W[sum] == 0)
        W[sum] = i;
      else
      {
        solution = true;
        printMask(i);
        printMask(W[sum]);
        break;
      }
    }
    
    //output
    if (!solution)
      printf("Impossible\n");
  }
  return 0;
}