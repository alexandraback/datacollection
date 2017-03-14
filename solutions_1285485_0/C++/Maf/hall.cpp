#include <cstdio>
#include <cmath>
#include <set>

using namespace std;

struct p {
  int x, y;
  bool operator <(const p& other) const {
    return atan2(y,x) + 0.000001 < atan2(other.y, other.x);
  }
};

int main(int argc, char *argv[])
{
  int T;
  scanf("%d", &T);
  for (int t=0; t<T; ++t) {
    int H, W, D, x, y;
    scanf("%d%d%d ", &H, &W, &D);
    int d2 = D*D;
    for (int h=0; h<H; ++h) {
      for (int w=0; w<W; ++w) {
	char c = getchar();
	if(c == 'X') {
	  x = w; y = h;
	}
	//printf("%c", c);
      }
      //printf("\n");
      scanf(" ");
    }
    W -= 2; H -= 2;
    x -= 1; y -= 1;
    set<p> images = set<p>();

    int xrep = D / W + 1
      , yrep = D / H + 1;

    int xmod = W - 2*x - 1
      , ymod = H - 2*y - 1;

    for (int kx = -xrep; kx <= xrep; ++kx) {
      for (int ky = -yrep; ky <= yrep; ++ky) {
	if(kx == 0 && ky == 0) continue;
	p point;
	point.y = ky * H;
	point.x = kx * W;

	if(kx % 2) point.x += xmod;
	if(ky % 2) point.y += ymod;

	if(point.x*point.x + point.y*point.y > d2) continue;

	images.insert(point);
	//printf("Inserting %d, %d\n", point.x, point.y);
      }
    }
    printf("Case #%d: %d\n", t+1, images.size());
    //printf(" W: %d H: %d\n", W, H);
    //printf(" x: %d y: %d\n", x, y);
  }
  return 0;
}
