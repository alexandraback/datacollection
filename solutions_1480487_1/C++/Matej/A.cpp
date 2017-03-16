#include <cstdio>
#include <algorithm>
using namespace std;

typedef long double lod;

int N, X;
int S[209];

int main()
{
  int T;
  scanf("%d", &T);
  for (int Ti = 1; Ti <= T; Ti++)
  {
    //input
    scanf("%d", &N);
    X = 0;
    for (int i = 0; i < N; i++)
    {
      scanf("%d", &S[i]);
      X += S[i];
    }
    printf("Case #%d:", Ti);
    
    //binary search answer for each
    for (int i = 0; i < N; i++)
    {
      lod a = 0;
      lod b = 1;
      while (b - a >= 0.000000000001)
      {
        lod p = (a + b) / 2;
        lod I = S[i] + p * X;
        lod need = 0;
        for (int j = 0; j < N; j++)
          if ((i != j) && (S[j] < I))
            need += 1.0 * (I - S[j]) / X;
        if (need + p > 1)
          b = p;
        else
          a = p;
      }
      printf(" %.12Lf", 100.0 * b);
    }
    printf("\n");
  }
  return 0;
}