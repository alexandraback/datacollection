#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <math.h>
#include <map>

using namespace std;

int main() 
{
  int T;
  scanf("%d\n", &T);
  for(int tc = 1; tc <= T; ++tc)
  {
    int N;
    int X = 0;
    int s[201];
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
    {
      int S;
      scanf("%d", &S);
      X += S;
      s[i] = S;
    }
    printf("Case #%d:", tc);
    double th = (double) X*2/N;
    for(int i = 0; i < N; ++i) 
    {
      int j = s[i];
      double y = 0;
      if(j >= th) {
        printf(" %lf", y);
        continue;
      }
      y = (th - j)/X;
      printf(" %lf", y*100);
    }
    printf("\n");
  }
}
