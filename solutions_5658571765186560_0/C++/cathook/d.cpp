#include <stdio.h>

#include <algorithm>


int main() {
  int num_cases, case_i;
  for (scanf("%d", &num_cases), case_i = 1; case_i <= num_cases; ++case_i) {
    int x, r, c;
    scanf("%d %d %d", &x, &r, &c);
    
    if (r < c) {
      std::swap(r, c);
    }
    
    bool first_win;
    if (x == 1) {
      first_win = false;
    } else {
      if (x > r * c) {
        first_win = true;
      } else {
        if (r * c % x != 0) {
          first_win = true;
        } else {
          if (c == 1) {
            if (x >= 3) {
              first_win = true;
            } else {
              first_win = false;
            }
          } else if (c == 2) {
            if (x >= 4) {
              first_win = true;
            } else {
              first_win = false;
            }
          } else if (c == 3) {
            if (x >= 6) {
              first_win = true;
            } else {
              first_win = false;
            }
          } else if (c == 4) {
            if (x >= 7) {
              first_win = true;
            } else {
              first_win = false;
            }
          } else {
            if (x >= 7) {
              first_win = true;
            } else {
              first_win = false;
            }
          }
        }
      }
    }
    printf("Case #%d: %s\n", case_i, first_win ? "RICHARD" : "GABRIEL");
  }
  return 0;
}
