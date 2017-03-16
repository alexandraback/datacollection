#include <stdio.h>

struct Size {
  Size(): R(0), C(0){
  }
  Size(int _R, int _C):R(_R), C(_C) {
  }
  int R, C;
} table[5] = {
  Size(1, 2),
  Size(2, 3),
  Size(3, 4),
  Size(3, 5),
  Size(4, 6)
};

int main() {
  int T;
  scanf("%d", &T);
for (int ic = 1; ic <= T; ++ic) {
  printf("Case #%d: ", ic);
  int R, C, X;
  int tmp;
  scanf("%d%d%d", &X, &R, &C);
  if (R > C) {
    tmp = R;
    R = C;
    C = tmp;
  }
  if (X == 1) {
    printf("GABRIEL");
  } else if (X >= 7) {
    printf("RICHARD");
  } else {
    // printf("%d %d\n", table[X-2].R, table[X-2].C);
    if (R < table[X-2].R || C < table[X-2].C) {
      printf("RICHARD");
    } else {
      printf("%s", R*C % X ? "RICHARD" : "GABRIEL");
    }
  }
  printf("\n");
}
}
