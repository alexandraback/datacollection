#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
    printf("Case #%d: ", caso);

    double r, t;
    scanf("%lf %lf", &r, &t);

    double a = 2.0;
    double b = 2.0*r-1.0;
    double c = -t;
    double delta = b*b-4.0*a*c;
    double x = (-b + sqrt(delta)) / (2.0*a);

    printf("%.0lf\n", floor(x));
  }
}
