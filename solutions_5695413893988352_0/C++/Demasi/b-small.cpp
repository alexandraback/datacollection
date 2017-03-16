#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <vector>

using namespace std;

int pode(int i, char *s) {
  char t[32];
  if (strlen(s) == 1) { if (i > 9) return 0; sprintf(t, "%d", i); }
  if (strlen(s) == 2) { if (i > 99) return 0; sprintf(t, "%02d", i); }
  if (strlen(s) == 3) { if (i > 999) return 0; sprintf(t, "%03d", i); }

  for(int j = 0; s[j]; j++) {
    if (s[j] != '?' && t[j] != s[j]) {
      return 0;
    }
  }

  return 1;
}

int main() {
  int T;

  scanf("%d", &T);
  for(int caso = 1; caso <= T; caso++) {
    char sc[32], sj[32];
    int C, J;
    scanf("%s %s", sc, sj);

    int d = 10000;
    C = J = 10000;
    for(int i = 0; i < 1000; i++) {
      if (pode(i, sc)) {
        for(int j = 0; j < 1000; j++) {
          if (pode(j, sj)) {
            //printf("[%d %d]", i, j);
            if (abs(i-j) < d || (abs(i-j) == d && i < C)) {
              C = i;
              J = j;
              d = abs(i-j);
            }
          }
        }
      }
    }

    if (strlen(sc) == 1) sprintf(sc, "%d", C);
    if (strlen(sc) == 2) sprintf(sc, "%02d", C);
    if (strlen(sc) == 3) sprintf(sc, "%03d", C);
    if (strlen(sj) == 1) sprintf(sj, "%d", J);
    if (strlen(sj) == 2) sprintf(sj, "%02d", J);
    if (strlen(sj) == 3) sprintf(sj, "%03d", J);
    printf("Case #%d: %s %s\n", caso, sc, sj);
  }
  return 0;
}

