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
    if (x > c || (x+1) / 2 > r || (r * c) % x)
      rje = 0;

    if ((x+1) / 2 == r) {
      for (int i=1; i<=r*r - (2 * r - 1); i++) {
        int ne=0;
        for (int j=0; j<=c-r; j++)
          if (!((j * r + i) % x))
            ne = 1;

        if (!ne) {
          rje = 0;
          break;
        }
      }
    }

    printf("%s\n", s[rje]);
  }

  return 0;
}
