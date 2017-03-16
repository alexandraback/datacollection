#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int MAXL = 110;

int f[MAXL][2];

int main()
{
  int cases;
  scanf("%d", &cases);
  char buf[MAXL];
  for (int k = 1; k <= cases; ++k)
  {
    printf("Case #%d: ", k);
    scanf("%s", buf);
    int n = strlen(buf);
    for (int i = 0; i < n; ++i) f[i][0] = f[i][1] = MAXL;
    if (buf[0] == '+')
      f[0][0] = 0, f[0][1] = 1;
    else
      f[0][1] = 0, f[0][0] = 1;

    for (int i = 1; i < n; ++i)
    {
      if (buf[i] == '+')
      {
        f[i][0] = f[i - 1][0];
      }
      else
      {
        f[i][1] = f[i - 1][1];
      }
      if (f[i][0] < f[i][1])
        f[i][1] = min(f[i][0] + 1, f[i][1]);
      else
        f[i][0] = min(f[i][1] + 1, f[i][0]);
    }

    int ans = f[n - 1][0];
    printf("%d\n", ans);
  }
}
