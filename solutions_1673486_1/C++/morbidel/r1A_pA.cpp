#include <cstdio>
#include <vector>

using namespace std;

#define INPUT_FILE    "A-large.in"
#define OUTPUT_FILE   "A-large.out"
#define MIN(a, b)     ((a) > (b) ? (b) : (a))

int A, B;
vector<double> P, Prod;

double solve()
{
  int i;

  double all = 1, cont = 1, enter, bp, ans;

  Prod.clear();
  Prod.push_back(0);
  for (i = 0; i < A; ++i)
  {
    all *= P[i];
    Prod.push_back(all);
  }

  cont = all * (B - A + 1) + (1 - all) * (B - A + 1 + B + 1);
  enter = 1 + B + 1;

  ans = MIN(cont, enter);

  // dau i backspace-uri
  for (i = 1; i <= A; ++i)
  {
    bp = i + Prod[A - i] * (B - A + i + 1) + (1 - Prod[A - i]) * (B - A + i + 1 + B + 1);
    ans = MIN(ans, bp);
  }

  return ans;
}

int main()
{
  freopen(INPUT_FILE, "rt", stdin);
  freopen(OUTPUT_FILE, "wt", stdout);

  int t;

  scanf("%d", &t);

  for (int i = 1; i <= t; ++i)
  {
    scanf("%d %d", &A, &B);

    P.clear();
    for (int j = 0; j < A; ++j)
    {
      double p;

      scanf("%lf", &p);
      P.push_back(p);
    }

    printf("Case #%d: %.6lf\n", i, solve());
  }

  return 0;
}