#include <cstdio>
#include <cmath>

using namespace std;

typedef unsigned long long ullong;
typedef unsigned long ulong;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
typedef long long llong;

void solve() {
  int x, y;
  int i = 1;
  scanf("%d%d", &x, &y);
    for (; x != 0; ++i) {
      if (abs(x) < i) {
	if (x < 0) {
	  printf("E");
	  x -= i;
	} else {
	  printf("W");
	  x += i;
	}
      } else {
	if (x < 0) {
	  printf("W");
	  x += i;
	} else {
	  printf("E");
	  x -= i;
	}
      }
    }
    for (; y != 0; ++i) {
      if (abs(y) < i) {
	if (y < 0) {
	  printf("N");
	  y -= i;
	} else {
	  printf("S");
	  y += i;
	}
      } else {
	if (y < 0) {
	  printf("S");
	  y += i;
	} else {
	  printf("N");
	  y -= i;
	}
      }
    }
  puts("");
}

int main() {
  int nc;
  scanf("%i", &nc);
  for (int i = 1; i <= nc; ++i) {
    printf("Case #%d: ", i);
    solve();
  }
}
