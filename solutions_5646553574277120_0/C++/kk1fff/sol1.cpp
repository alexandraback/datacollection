#include <iostream>

using namespace std;

int AllD[1000];

int powi(int b, int p) {
  int s = 1;
  while (p--) {
    s *= b;
  }
  return s;
}

int fvcny(int dlen, int c, int v) {
  int alln[31];
  c++; // number sys
  memset(alln, 0, sizeof(alln));
  int maxn = powi(c, dlen);
  for (int i = 0; i < maxn; i++) {
    int k = i;
    int r = 0;
    for (int j = 0; j < dlen; j++) {
      r += (AllD[j] * (k % c));
      k /= c;
    }
    //printf("r = %d\n", r);
    if (r <= v) {
      alln[r] = 1;
    }
  }
  for (int i = 0; i <= v; i++) {
    if (alln[i] == 0) {
      return i;
    }
  }
  return -1;
}

void f(int T) {
  int C, D, V;
  cin >> C >> D >> V;
  memset(AllD, 0, sizeof(AllD));
  for (int i = 0; i < D; i++) {
    cin >> AllD[i];
  }
  int d = D;
  while (1) {
    int vcny = fvcny(d, C, V);
    //break;
    if (vcny != -1) {
      AllD[d++] = vcny;
    } else {
      break;
    }
  }
  printf("Case #%d: %d\n", T, d - D);
}

int main() {
  int T;
  cin >> T;
  for (int i = 1; i < T+1; i++) {
    f(i);
  }
}
