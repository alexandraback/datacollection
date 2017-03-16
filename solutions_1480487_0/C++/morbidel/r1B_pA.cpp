#include <cstdio>
#include <vector>

using namespace std;

#define INPUT_FILE    "A-small-attempt2.in"
#define OUTPUT_FILE   "A-small-attempt2.out"
#define MIN(a, b)     ((a) > (b) ? (b) : (a))


int main()
{
  freopen(INPUT_FILE, "rt", stdin);
  freopen(OUTPUT_FILE, "wt", stdout);

  int t;
  int n, s;
  int v[300];
  double x;

  scanf("%d", &t);

  for (int i = 1; i <= t; ++i)
  {
    scanf("%d", &n);

    s = 0;
    for (int j = 0; j < n; ++j)
    {
      scanf("%d", &v[j]);
      s += v[j];
    }

    x = 2 * (double)s / (double)n;

    printf("Case #%d: ", i);

    for (int j = 0; j < n; ++j)
    {
      double proc = (double)(x - v[j]) * 100 / s;
      if (proc < 0)
        proc = 0;

      printf("%.6lf ", proc);
    }
    printf("\n");
  }

  return 0;
}