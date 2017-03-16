#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main(void)
{
  int T;

  scanf("%d", &T);
  for(int caso = 1; caso <= T; caso++)
  {
    double C,F,X;
    scanf("%lf %lf %lf", &C, &F, &X);
    double left = 0.0;
    double right = 2.0*X;

    for(int passos = 0; passos < 100000; passos++)
    {
      double m = (left+right)/2.0;
      //printf("[%lf %lf %lf]", left, m, right);

      int pode = 0;

      double t = 0;
      for(int i = 0; i <= (int)X && !pode; i++)
      {
        double f = 2.0+F*(double)i;
        if (t+(X/f) <= m) pode = 1;
        t += C/f;
      }

      if (!pode) left = m;
      else right = m;
    }
    printf("Case #%d: %.10lf\n", caso, (left+right)/2.0);
  }
}
