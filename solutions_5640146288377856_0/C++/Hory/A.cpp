#include <cstdio>
using namespace std;

int main()
{
  int T = 0;
  scanf("%d", &T);
  for(int Case = 1; Case <= T; ++Case)
  {
    int r = 0, c = 0, w = 0;
    scanf("%d%d%d", &r, &c, &w);
    int ans = c / w * r + w - 1;
    if(c % w != 0)
      ++ans;
    printf("Case #%d: %d\n", Case, ans);
  }
  return 0;
}
