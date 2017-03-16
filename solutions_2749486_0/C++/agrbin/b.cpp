#include <cstdio>

void solve(int x, int y) {
  int px = x > 0 ? 0 : 1;
  int py = y > 0 ? 0 : 1;
  if (x < 0) x *= -1;
  if (y < 0) y *= -1;
  while (x) {
    if (px == 0) {
      printf("WE");
    } else {
      printf("EW");
    }
    --x;
  }
  while (y) {
    if (py == 0) {
      printf("SN");
    } else {
      printf("NS");
    }
    --y;
  }
  printf("\n");
}

int main() {
  int casen;
  scanf("%d", &casen);
  for (int j = 0; j < casen; ++j) {
    int x, y;
    scanf("%d%d", &x, &y);
    printf("Case #%d: ", j + 1);
    solve(x, y);
  }
  return 0;
}
