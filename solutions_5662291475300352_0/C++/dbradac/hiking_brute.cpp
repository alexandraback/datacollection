#include <cstdio>
#include <algorithm>

using namespace std;

const double EPS = 1e-10;

int pocpoz[2], t[2];

int main()
{
  int tt;

  scanf("%d", &tt);

  for (int iiii=1; iiii<=tt; iiii++) {
    printf("Case #%d: ", iiii);

    int brgr, n=0;
    scanf("%d", &brgr);
    for (int i=0; i<brgr; i++) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      for (int j=0; j<b; j++) {
        pocpoz[n] = a;
        t[n++] = c + j;
      }
    }

    int rez = 1;

    if (n < 2)
      rez = 0;
    else {
      double t0 = ((double) 360 - pocpoz[0]) / 360 * t[0];
      double t1 = ((double) 360 - pocpoz[1]) / 360 * t[1];
      if (t0 > t1) {
        swap(t0, t1);
        swap(pocpoz[0], pocpoz[1]);
        swap(t[0], t[1]);
      }

      if (pocpoz[0] + t1 * ((double) 360 / t[0]) + EPS < 720)
        rez = 0;
    }

    printf("%d\n", rez);
  }

  return 0;
}
