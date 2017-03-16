#include <iostream>
using namespace std;

int main() {
  int T, ny, nx, my[100], mx[100], a[100][100];
  int x, y;
  cin >> T;
  for (int cases = 1; cases <= T; cases++) {
    cin >> ny >> nx;
    memset(my, 0, sizeof(my));
    memset(mx, 0, sizeof(mx));
    for (y = 0; y < ny; y++) {
      for (x = 0; x < nx; x++) {
	cin >> a[y][x];
	my[y] >?= a[y][x];
	mx[x] >?= a[y][x];
      }
    }
    for (y = 0; y < ny; y++) {
      for (x = 0; x < nx; x++) {
	if (a[y][x] < my[y] && a[y][x] < mx[x]) break;
      }
      if (x < nx) break;
    }
    if (y < ny) printf("Case #%d: NO\n", cases);
    else printf("Case #%d: YES\n", cases);
  }
  return 0;
}
