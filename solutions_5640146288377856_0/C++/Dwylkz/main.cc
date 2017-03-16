#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
  int T;
  scanf("%d", &T);
  for (int kas = 1; kas <= T; kas++) {
    printf("Case #%d: ", kas);
    int r, c, w;
    scanf("%d%d%d", &r, &c, &w);
    int base = (c+w-1)/w-1, ans = base+w;
    if (w < c)
    {
      if (w+1 < c) ans = max(ans, base+w-1);
      else ans = max(ans, base+w);
    }
    printf("%d\n", r*ans);
  }
  return 0;
}
