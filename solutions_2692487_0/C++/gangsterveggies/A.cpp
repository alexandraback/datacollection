#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAX 10e6

int N;
long long int mote[122];

int pos(long long int size, int K, int curr)
{
  if (K < 0)
    return 0;
  if (curr == N)
    return 1;
  if (size <= mote[curr])
  {
    if (size > 1 && pos(size + size - 1, K - 1, curr))
      return 1;
    if (pos(size, K - 1, curr + 1))
      return 1;
    return 0;
  }
  return pos(size + mote[curr], K, curr + 1);
}

int main()
{
  int t, T, i;
  scanf("%d", &T);
  for (t = 1;  t <= T; t++)
  {
    long long int A;
    scanf("%lld %d", &A, &N);
    for (i = 0; i < N; i++)
      scanf("%lld", &mote[i]);
    sort(mote, mote + N);
    int a = 0, b = MAX + 2;
    while (a < b)
    {
      int med = (a + b) / 2;
//      if (b == med)
//        med--;
      if (pos(A, med, 0))
        b = med;
      else
        a = med + 1;
    }
    printf("Case #%d: %d\n", t, a);
  }
  return 0;
}
