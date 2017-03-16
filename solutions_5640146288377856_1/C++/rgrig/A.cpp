#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
  int tests; scanf("%d",&tests);
  for (int t = 1; t <= tests; ++t) {
    int r, c, w; scanf("%d %d %d",&r,&c,&w);
    printf("Case #%d: %d\n", t, (c/w)*r+w-(c%w==0));
  }
}
