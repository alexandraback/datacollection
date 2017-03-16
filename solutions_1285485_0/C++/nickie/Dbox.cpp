#undef DEBUG

#ifdef DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...) do ; while(0)
#define NDEBUG
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <set>

using namespace std;

typedef set< pair<int, int> > pointdb;

inline void consider (int x, int y, pointdb & refl, int d2)
{
  debug("considering (%d,%d): ", x, y);
  if (x == 0 && y == 0) {
    debug("discarded, origin\n");
    return;
  }
  if (x * x + y * y > d2) {
    debug("discarded, too far\n");
    return;
  }
  for (pointdb::const_iterator i = refl.begin(); i != refl.end(); i++)
    if (i->first * y == i->second * x &&
        x * i->first >= 0 && y * i->second >= 0) {
      debug("discarded because of (%d,%d)\n", i->first, i->second);
      return;
    }
  debug("reflection\n");
  refl.insert(make_pair(x, y));
}

int main ()
{
  int tests;

  scanf("%d\n", &tests);

  for (int test=1; test<=tests; test++) {
    // input and test if it's a box
    int w, h, d;
    scanf("%d %d %d\n", &h, &w, &d);
    int xw, xh;
    for (int j=0; j<h; j++) {
      for (int i=0; i<w; i++) {
        char c = getchar();
        if (i == 0 || i == w-1 || j == 0 || j == h-1) {
          if (c != '#') {
            fprintf(stderr, "not a box: border not made of mirrors\n");
            return 1;
          }
        }
        else {
          if (c == 'X') {
            xw = i; xh = j;
          }
          else if (c != '.') {
            fprintf(stderr, "not a box: interior contains mirror\n");
            return 1;
          }
        }        
      }
      scanf("\n");
    }
    // calculate
    w -= 2;
    h -= 2;
    int maxnw = d / (2*w) + 1;
    int maxnh = d / (2*h) + 1;
    int d2 = d*d;
    pointdb refl;
    for (int nw = -maxnw; nw <= maxnw; nw++)
      for (int nh = -maxnh; nh <= maxnh; nh++) {
        consider(2*nw*w, 2*nh*h, refl, d2);
        consider(2*nw*w, 2*nh*h + 2*xh-1, refl, d2);
        consider(2*nw*w + 2*xw-1, 2*nh*h, refl, d2);
        consider(2*nw*w + 2*xw-1, 2*nh*h + 2*xh-1, refl, d2);
      }
    // output
    printf("Case #%d: %d\n", test, refl.size());
  }
  return 0;
}
