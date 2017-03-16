#include<stdio.h>

#define max(a, b) ((a)<(b)?(b):(a))
#define min(a, b) ((a)>(b)?(b):(a))

inline int get(int x, int p) {
  return (x >> p) & 1;
}

#define MAX 100000002

long tabl[MAX];

long rec(int a, int b, int k, int pos) {
  if (a < 0)
    return 0;
  if (b < 0)
    return 0;
  if (pos == -1) {
    // win!
    return a*b;
  }
  if (a == b && a < MAX) {
    // precalc case
    if (tabl[a] >= 0)
      return tabl[a];
  }
  //printf("rec %d %d at pos %d\n", a, b, pos);
  int mp = 1 << pos;
  int la = min(a, mp);
  int lb = min(b, mp);
  int ra = a - mp;
  int rb = b - mp;
  long res;
  int bit = get(k, pos);
  if (bit == 0) {
    // need to do zero
    long n1, n2, n3;
    n1 = rec(la, lb, k, pos-1);
    n2 = rec(la, rb, k, pos-1);
    n3 = rec(ra, lb, k, pos-1);
    res = n1 + n2 + n3;
    //printf("returns %d case ZERO pos %d\n", res, pos);
  } else {
    // doing zero wins, otherwise be careful
    long n1, n2, n3, n4;
    n1 = max(0, la)*max(0, lb);
    n2 = max(0, ra)*max(0, lb);
    n3 = max(0, la)*max(0, rb);
    n4 = rec(ra, rb, k, pos-1);
    res = n1 + n2 + n3 + n4;
    //printf("returns %d+%d+%d+%d case ONE pos %d\n", n1, n2, n3, n4, pos);
  }
  if (a == b && a < MAX) {
    // cache
    tabl[a] = res;
  }
  return res;
}

int main() {
  int T;
  scanf("%d", &T);
  int ncase;
  for (ncase = 0; ncase < T; ncase++) {
    int A, B, K;
    long ans = 0;
    scanf("%d %d %d", &A, &B, &K);
    int i;
    for (i=0; i<MAX; i++)
      tabl[i] = -1;
    ans = rec(A, B, K-1, 21);
    printf("Case #%d: %ld\n", ncase+1, ans);
  }
  return 0;
}
