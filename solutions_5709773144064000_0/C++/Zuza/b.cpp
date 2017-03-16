#include <algorithm>
#include <functional>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>

using namespace std;

int main(void)
{
  int T; scanf("%d", &T);

  for (int counter = 0; counter < T; ++counter) {
    double c, f, x; scanf("%lf %lf %lf", &c, &f, &x);
    double mini = 1e100;
    double t = 0;

    double prod = 2;

    do {
      double val = t + x/prod;
      if (val < mini)
        mini = val;
      else
        break;

      t += c / prod;
      prod += f;
    } while (true);

    printf("Case #%d: %.7lf\n", counter + 1, mini);
    fflush(stdout);
  }

  return (0-0);
}
