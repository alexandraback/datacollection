#include <bits/stdc++.h>
using namespace std;

int t, l, x;
char buf[10010];
int m[5][5] = {
  {0, 0, 0, 0, 0},
  {0, 1, 2, 3, 4},
  {0, 2, 1, 4, 3},
  {0, 3, 4, 1, 2},
  {0, 4, 3, 2, 1},
};

int b[5][5] = {
  {0, 0, 0, 0, 0},
  {0, 1, 1, 1, 1},
  {0, 1,-1, 1,-1},
  {0, 1,-1,-1, 1},
  {0, 1, 1,-1,-1},
};

struct Digit { int v, par;
  Digit(int _v, int _p) : v(_v), par(_p) {};
  Digit mult(const Digit& other) {
    return Digit(m[v][other.v], b[v][other.v] * par * other.par);
  }
};

int main() {
  scanf("%d", &t);

  for (int ca=1; ca<=t; ca++) {
    scanf("%d %d", &l, &x);
    scanf("%s", buf);

    Digit c1(1, 1), c2(1,1);

    int idxI = -1;
    int idxK = -1;

    for (int i=0; i<l; i++) {
      c2 = Digit((int)(buf[i]-'g'), 1);
      c1 = c1.mult(c2);
      if (idxI == -1 && c1.par == 1 && c1.v == 2) { idxI = i; }
    }

    Digit Lcheck = c1;
    for (int i=0; i<(x%4)-1; i++) {
      Lcheck = Lcheck.mult(c1);
    }

    if ((Lcheck.v != 1 || Lcheck.par != -1) || (x % 4 == 0)) {
      printf("Case #%d: NO\n", ca);
      continue;
    }

    for (int i=0; idxI == -1 && i<l*min(3,x-1); i++) {
      c2 = Digit((int)(buf[i%l]-'g'), 1);
      c1 = c1.mult(c2);
      if (c1.par == 1 && c1.v == 2) { idxI = i+l; break;}
    }

    c1 = Digit(1,1);

    int count = 0;
    for (int i=x*l-1; idxK == -1 && i >= 0 && count <= 4*l; i--) {
      c2 = Digit((int)(buf[i%l]-'g'), 1);
      c1 = c2.mult(c1);
      if (c1.par == 1 && c1.v == 4) { idxK = i; break;}
      count++;
    }

    // cout << idxI  << " vs " << idxK << endl;

    if (idxI == -1 || idxK == -1 || idxI >= idxK || idxK >= l * x) {
      printf("Case #%d: NO\n", ca);
    } else {
      printf("Case #%d: YES\n", ca);
    }

  }
  return 0;
}
