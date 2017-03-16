#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <vector>

using namespace std;
char sc[32], sj[32], C[32], J[32];
long long r, A, B;

void faz(int i, char *sc, char *sj, int mode) {
  if (!sc[i]) {
    long long a, b;

    //printf("[%s %s]", sc, sj);
    a = 0;
    for(int i = 0; sc[i]; i++) {
      a *= 10LL;
      a += (long long)(sc[i]-'0');
    }
    b = 0;
    for(int i = 0; sj[i]; i++) {
      b *= 10LL;
      b += (long long)(sj[i]-'0');
    }
    if (b > a) swap(a, b);

    if (r < 0 || a-b < r || (a-b == r && (a < A || (a == A && b < B)))) {
      r = a-b;
      A = a;
      B = b;
      strcpy(C, sc);
      strcpy(J, sj);
    }
    return;
  }

  if (sc[i] != '?' && sj[i] != '?') {
    //printf("(%s %s %d)", sc, sj, mode);
    if (mode == 0 && sc[i] != sj[i]) {
      faz(i+1, sc, sj, (sc[i] > sj[i]) ? 1 : 2);
    } else {
      faz(i+1, sc, sj, mode);
    }
  } else if (sc[i] == '?' && sj[i] == '?') {
    if (mode == 0) {
      sc[i] = sj[i] = '0';
      faz(i+1, sc, sj, 0);
      sc[i] = '1';
      faz(i+1, sc, sj, 1);
      sc[i] = '0';
      sj[i] = '1';
      faz(i+1, sc, sj, 2);
    } else if (mode == 1) {
      sc[i] = '0';
      sj[i] = '9';
      faz(i+1, sc, sj, 1);
    } else if (mode == 2) {
      sc[i] = '9';
      sj[i] = '0';
      faz(i+1, sc, sj, 2);
    }
    sc[i] = sj[i] = '?';
  } else if (sc[i] == '?' && sj[i] != '?') {
    if (mode == 0) {
      sc[i] = sj[i];
      faz(i+1, sc, sj, 0);
      if (sj[i] < '9') {
        sc[i] = sj[i]+1;
        faz(i+1, sc, sj, 1);
      }
      if (sj[i] > '0') {
        sc[i] = sj[i]-1;
        faz(i+1, sc, sj, 2);
      }
    } else if (mode == 1) {
      sc[i] = '0';
      faz(i+1, sc, sj, mode);
    } else if (mode == 2) {
      sc[i] = '9';
      faz(i+1, sc, sj, mode);
    }
    sc[i] = '?';
  } else if (sc[i] != '?' && sj[i] == '?') {
    if (mode == 0) {
      sj[i] = sc[i];
      faz(i+1, sc, sj, 0);
      if (sc[i] < '9') {
        sj[i] = sc[i]+1;
        faz(i+1, sc, sj, 2);
      }
      if (sc[i] > '0') {
        sj[i] = sc[i]-1;
        faz(i+1, sc, sj, 1);
      }
    } else if (mode == 1) {
      sj[i] = '9';
      faz(i+1, sc, sj, mode);
    } else if (mode == 2) {
      sj[i] = '0';
      faz(i+1, sc, sj, mode);
    }
    sj[i] = '?';
  }
}

int main() {
  int T;

  scanf("%d", &T);
  for(int caso = 1; caso <= T; caso++) {

    scanf("%s %s", sc, sj);
    r = -1;
    faz(0, sc, sj, 0);

    printf("Case #%d: %s %s\n", caso, C, J);
  }
  return 0;
}

