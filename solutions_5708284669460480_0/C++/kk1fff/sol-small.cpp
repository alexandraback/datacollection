#include<iostream>
#include <iomanip>

using namespace std;

char all[900000][8];

int powi(int len, int S) {
  int r = 1;
  while (S--) {
    r *= len;
  }
  return r;
}

int getall(const char* in, int len, int S) {
  int posslen = powi(len, S);
  for (int i = 0; i < posslen; i++) {
    memset(&(all[i][0]), 0, 8);
    int x = i;
    for (int j = 0; j < S; j++) {
      all[i][j] = in[x % len];
      x /= len;
    }
  }
  return posslen;
}

int countthis(int item, const char *tar, int tarlen, int S) {
  int c = 0;
  int lim = S - tarlen + 1;
  for (int i = 0; i < lim; i++) {
    if (strncmp(tar, all[item]+i, tarlen) == 0) {
      i += tarlen - 1;
      c++;
    }
  }
  return c;
}

int countall(int listlen, const char* tar, int tarlen, int S) {
  int c = 0;
  for (int i = 0; i < listlen; i++) {
    c += countthis(i, tar, tarlen, S);
  }
  return c;
}

void f(int T) {
  int K, L, S;
  string Ks;
  string Ts;
  cin >> K >> L >> S;
  cin >> Ks;
  cin >> Ts;
  for (auto c: Ts) {
    bool fnd = false;
    for (auto c1: Ks) {
      if (c1 == c) {
        fnd = true;
        break;
      }
    }
    if (!fnd) {
      printf("Case #%d: %.6lf\n", T,  0.0);
      return;
    }
  }
  int sz = getall(Ks.c_str(), K, S);
  int cntall = countall(sz, Ts.c_str(), L, S);
  //printf("cntall: %d, sz: %d\n", cntall, sz);
  double expVal = ((double)cntall) / ((double)sz);
  printf("Case #%d: %.6lf\n", T, ((double)(S/L)) - expVal);
}

int main() {
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    f(i);
  }
}








