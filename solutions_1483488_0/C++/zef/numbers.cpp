#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int shift(int i, int w) {
  return (i / 10) + w * (i % 10);
}

int main()
{
  int ncases, a, b, count;

  cin >> ncases;
  for (int caseno = 1; caseno <= ncases; caseno++) {
    cin >> a >> b;
    count = 0;

    int k = a, w = 0;
    while (k != 0) {
      k /= 10;
      w = w == 0 ? 1 : w * 10;
    }

    for (int i = a, j = a; i <= b; j = ++i) {
      while (1) {
        if ((j = shift(j, w)) == i)
          break;
        count += i < j && j <= b;
        /*
        if (i < j && j <= b) {
          printf("%i, %i\n", i, j);
        }
        */
      }
    }
    printf("Case #%i: %i\n", caseno, count);
  }
}
