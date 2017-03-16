#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  int n,m;
  int x;
  scanf("%d", &t);
  int cs = 0;
  while (t--) {
    scanf("%d %d %d", &x, &n, &m);
    printf("Case #%d: ", ++cs);
    if (x == 1) {
      printf("GABRIEL\n");
    } else if (x == 2) {
      if ((n * m) % 2 == 0) {
        printf("GABRIEL\n");
      } else {
        printf("RICHARD\n");
      }
    } else if (x == 3) {
      if ((n * m) % 3 != 0) {
        printf("RICHARD\n");
      } else {
        if (n > 1 &&  m > 1) {
          printf("GABRIEL\n");
        } else {
          printf("RICHARD\n");
        }
      }
    } else if (x == 4) {
      if ((n * m) % 4 != 0) {
        printf("RICHARD\n");
      } else {
        if (n > 2 && m > 2) {
          printf("GABRIEL\n");
        } else {
          printf("RICHARD\n");
        }
      }
    } else if (x == 5) {
      if ((n * m) % 5 != 0) {
        printf("RICHARD\n");
      } else {
        if (n > 3 && m > 3) {
          printf("GABRIEL\n");
        } else {
          printf("RICHARD\n");
        }
      }
    } else if (x == 6) {
      if ((n * m) % 6 != 0) {
        printf("RICHARD\n");
      } else {
        if (n > 3 && m > 3) {
          printf("GABRIEL\n");
        } else {
          printf("RICHARD\n");
        }
      }
    }
    else {
      printf("RICHARD\n");
    }
  }
}
