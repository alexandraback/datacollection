#include <stdio.h>
#include <assert.h>
#include <cstring>
#include <vector>

using namespace std;

int debug = 1;

template <typename T> T max(T a, T b)
{
  if (a > b)
    return a;
  else
    return b;
}

template <typename T> T min(T a, T b)
{
  if (a < b)
    return a;
  else
    return b;
}

int A, B;

int main(int argc, char *argv[])
{
  int T;
  
  assert(scanf("%d", &T) == 1);

  for (int t = 1; t <= T; t++)
  {
    assert(scanf("%d %d", &A, &B) == 2); 

    double pct = 1.0;
    double minCost = 2.0 + B;
    double bsCost = A - 1;
    double typeCost = B - 1;
    double enterCost = 1;

    for(int i = 0; i < A; i++)
    {  
       double x;
       assert(scanf("%lf", &x) == 1);
       pct *= x;

       double cost1 = bsCost + typeCost + enterCost;
       double cost2 = cost1 + B + 1;

       double eCost = pct * cost1 + (1.0 - pct) * cost2;

       if (eCost < minCost)
         minCost = eCost;

       bsCost--;
       typeCost--;
    }

    double cost1 = (B - A) + 1;
    double cost2 = cost1 + B + 1;
       double eCost = pct * cost1 + (1.0 - pct) * cost2;

       if (eCost < minCost)
         minCost = eCost;





    printf("Case #%d: %f\n", t, minCost);

  }
}
