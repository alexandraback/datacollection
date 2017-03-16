#include <cstdio>
#include <vector>

using namespace std;

int main()
{
  int T; scanf("%d\n", &T); for (int ii = 1; ii <= T; ++ii)
  {
    int Smax; scanf("%d", &Smax); char A[2000]; scanf("%s\n", A);
    int c = 0, d = 0; for (int i = 0; i <= Smax; ++i)
    {
      if (c < i)
      {
        d += (i - c);
        c = i;
      }
      c += (A[i] - '0');
    }
    printf("Case #%d: %d\n", ii, d);
  }
  return 0;
}
