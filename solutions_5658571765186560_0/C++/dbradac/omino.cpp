#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
  int tt;
  char s[2][15] = { "RICHARD", "GABRIEL" };

  scanf("%d", &tt);

  for (int ii=1; ii<=tt; ii++) {
    int x, r, c;
    scanf("%d%d%d", &x, &r, &c);
    printf("Case #%d: ", ii);

    if (r > c)
      swap(r, c);

    int rje=1;
    if (x > c || (x+1) / 2 > r || ((x+1) / 2 == r && x > 3) || (r * c) % x)
      rje = 0;

    printf("%s\n", s[rje]);
  }

  return 0;
}
