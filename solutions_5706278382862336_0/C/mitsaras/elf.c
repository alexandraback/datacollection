#include <stdio.h>
#include <stdlib.h>

int gcd (int a, int b) {
  int c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

int ispow2 (int x) {
    while ((x & 1) == 0) x /= 2;
    if (x == 1)
        return 1;
    else
        return 0;
}

int main () {
    int T, t;
    scanf("%d\n", &T);
    for (t = 1; t <= T; t++) {
        int P, Q;
        scanf("%d/%d\n", &P, &Q);
        int g = gcd(P,Q);
        P /= g;
        Q /= g;
        if (ispow2(Q) != 1) {
            printf("Case #%d: impossible\n", t);
        } else {
            int a = 1;
            while (P < Q / 2) {
                a++;
                Q /= 2;
            }
            printf("Case #%d: %d\n", t, a);
        }
        
    }
    return 0;
}
