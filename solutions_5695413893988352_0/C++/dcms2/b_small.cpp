#include <bits/stdc++.h>

using namespace std;

char C[20], J[20];
char aux[20];

bool ok(char* str, int num) {
  if (strlen(str) == 3) sprintf(aux, "%03d", num);
  else if (strlen(str) == 2) sprintf(aux, "%02d", num);
  else sprintf(aux, "%d", num);
  for (int i = 0; aux[i]; ++i) {
    if (str[i] != '?' && str[i] != aux[i]) return false;
  }
  return true;
}

int main() {
  int nt; scanf("%d", &nt);
  for (int caso = 1; caso <= nt; ++caso) {
    scanf("%s %s", C, J);

    int sz = strlen(C);
    
    int best_x = 999, best_y = 0;

    for (int x = 0; x <= 999; ++x) {
      for (int y = 0; y <= 999; ++y) {
        if (ok(C, x) && ok(J, y)) {
          if (abs(x - y) < abs(best_y - best_x)) {
            best_x = x; best_y = y;
          } else if (abs(x - y) == abs(best_x - best_y)) {
            if (x < best_x) {
              best_x = x; best_y = y;
            } else if (x == best_x && y < best_y) {
              best_y = y;
            }
          }
        }
      }
    }

    if (sz == 3) {
      sprintf(C, "%03d", best_x);
      sprintf(J, "%03d", best_y);
    } else if (sz == 2) {
      sprintf(C, "%02d", best_x);
      sprintf(J, "%02d", best_y);
    } else {
      sprintf(C, "%d", best_x);
      sprintf(J, "%d", best_y);
    }

    printf("Case #%d: %s %s\n", caso, C, J);
  }
  return 0;
}