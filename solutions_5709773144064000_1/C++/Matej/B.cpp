#include <cstdio>
#include <algorithm>
using namespace std;

double C, F, X;
double s, t, tn;
int n;

int main()
{
  int T;
  scanf("%d", &T);
  for (int Ti = 1; Ti <= T; Ti++)
  {
    // input
    scanf("%lf %lf %lf", &C, &F, &X);
    
    // solve
    n = 0;       // number of factories
    s = 0.0;     // time to build n factories
    tn = X / 2.0; // time to reach target with n factories
    while (true)
    {
      t = tn;
      s += C / (2.0 + F * n);
      n++;
      tn = s + X / (2.0 + F * n);
      if (tn > t)
        break;
    }

    // output
    printf("Case #%d: %.8lf\n", Ti, t);
  }
  return 0;
}
