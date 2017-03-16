#include <bits/stdc++.h>

using namespace std;

int tsts, a, b, k;

int main()
{
  freopen("B-small-attempt0.in", "r", stdin);
  freopen("my.out", "w", stdout);
  cin >> tsts;
  for (int tno = 1; tno <= tsts; tno++)
  {
    cin >> a >> b >> k;
    int ret = 0;
    for (int i = 0; i < a; i++)
    {
      for (int j = 0; j < b; j++)
      {
        if ((i & j) < k)
        {
          ret++;
        }
      }
    }
    printf("Case #%d: %d\n", tno, ret);
  }
  return 0;
}
