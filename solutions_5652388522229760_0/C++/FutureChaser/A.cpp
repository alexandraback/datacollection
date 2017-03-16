#include <stdio.h>
#include <set>

using namespace std;

set<int> s;

int get_ans(int n)
{
  if (n == 0) return -1;
  s.clear();
  char buf[256];
  for (int k = 1; k < 1000; ++k)
  {
    sprintf(buf, "%d", n * k);
    char *p = &buf[0];
    while (*p != 0) s.insert(*p++);
    if (s.size() == 10) return n * k;
  }
  return -1;
}

int main()
{
  int cases;
  scanf("%d", &cases);
  for (int k = 1; k <= cases; ++k)
//  for (int k = 0; k <= 1000000; ++k)
  {
    printf("Case #%d: ", k);
    int n;
    scanf("%d", &n);
    int ans = get_ans(n);
    if (ans == -1)
      printf("INSOMNIA\n");
    else
      printf("%d\n", ans);
  }
  return 0;
}
