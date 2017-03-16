#include <cstdio>

inline int rotate(int v, int d) {
  return (d * (v % 10)) + v / 10;
}

int caseCount = 0;
void make() {
  int A, B, C, D; scanf("%d %d", &A, &B);
  int res = 0;
  int d = 1;
  while(d*10 <= A) d *= 10; 
  for (int C=A; C<=B; ++C) {
    int D = rotate(C, d);
    while (D != C) {
      if ((A <= D) && (D <= B)) {
        ++res;
      }
      D = rotate(D, d);
    }
  }

  printf("Case #%d: %d\n", ++caseCount, res/2);
}

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    make();
  }
  return 0;
}
