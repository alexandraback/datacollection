#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int T; scanf("%d\n", &T); for (int ii = 1; ii <= T; ++ii)
  {
    int D; scanf("%d\n", &D); vector<int> P(D);
    for (int i = 0; i < D; ++i)
    {
      int x; scanf("%d", &x); P[i] = x;
    }

    sort(P.begin(), P.end());
    int tx = P[D-1];
    for (int i = 1; i <= P[D-1]; ++i)
    {
      int movetime = 0;
      for (int j = 0; j < D; ++j) movetime += ((P[j] - 1) / i);
      if (tx > movetime + i) tx = movetime + i;
    }
    printf("Case #%d: %d\n", ii, tx);
  }
  return 0;
}
