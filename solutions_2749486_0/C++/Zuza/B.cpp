#include <algorithm>
#include <functional>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>

using namespace std;

int main(void)
{
  int T; scanf("%d", &T);

  for (int counter = 0; counter < T; ++counter) {
    int x, y; scanf("%d %d", &x, &y);

    printf("Case #%d: ", counter + 1);
    
    while (x > 0) {
      printf("WE");
      --x;
    }
    while (x < 0) {
      printf("EW");
      ++x;
    }

    while (y > 0) {
      printf("SN");
      --y;
    }

    while (y < 0) {
      printf("NS");
      ++y;
    }

    putchar('\n');
    fflush(stdout);
  }

  return (0-0);
}
