#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int abs(int a) { return a < 0 ? -a : a; }
int sgn(int a) { return a < 0 ? -1 : 1; }

int main() {
  int examples;
  scanf("%d", &examples);
  for (int ex = 1; ex <= examples; ex++) {
    printf("Case #%d: ", ex);

    // input
    int x, y;
    scanf("%d%d", &x, &y);
    for (int s = 1; abs(x) >= s || abs(y) >= s; s++) {
      char move_x = x < 0 ? 'W' : 'E';
      char move_y = y < 0 ? 'S' : 'N';
      if (x != 0 && abs(x - sgn(x)*s) < abs(y - sgn(y)*s)) {
        x -= sgn(x)*s;
        printf("%c", move_x);
      } else if (y != 0) {
        y -= sgn(y)*s;
        printf("%c", move_y);
      } else {
        break;
      }
//      printf("(%d, %d)", x, y);
    }
    for (; x > 0; x--) printf("WE");
    for (; x < 0; x++) printf("EW");
    for (; y > 0; y--) printf("SN");
    for (; y < 0; y++) printf("NS");
    // output
    printf("\n");
  }
}
