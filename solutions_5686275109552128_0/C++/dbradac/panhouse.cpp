#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 1<<10;

int p[MAX];

int main()
{
  int tt;

  scanf("%d", &tt);

  for (int ii=1; ii<=tt; ii++) {
    int n;
    scanf("%d", &n);

    for (int i=0; i<n; i++)
      scanf("%d", &p[i]);

    int rez=MAX;

    for (int i=1; i<MAX; i++) {
      int tmp=0;
      for (int j=0; j<n; j++)
        tmp += (p[j] - 1) / i;

      rez = min(rez, tmp + i);
    }

    printf("Case #%d: %d\n", ii, rez);
  }

  return 0;
}
