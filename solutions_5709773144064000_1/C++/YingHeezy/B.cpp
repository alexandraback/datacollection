#include <cstdio>
#include <math.h>
using namespace std;

#define REP(i, n) for(int (i)=0; (i)<(n); (i)++)

int main() {
  int T;
  double C,F,X;
  scanf("%d", &T);
  REP(iii, T) {
    //C*(1/2 + 1/2+F + ... + 1/2+(n-1)F) + X/2+nF
    // C/(2+n*F) < X/(2+n*F) - X/(2+(n+1)*F) = X*F/(2+n*F)(2+(n+1)*F)
    // 2+(n+1)*F < X*F/C
    // n < X/C - 2/F - 1
    scanf("%lf%lf%lf", &C, &F, &X);
    int n;
    double db = X/C - 2/F - 1;
    if (db <= 0) n = -1;
    else n = (int)db;
    //printf("%lf\n", X/C - 2/F -1);
    double answer = 0;
    REP(i, n+1) answer += C/(2+i*F);
    answer += X/(2+(n+1)*F);
    printf("Case #%d: %.7lf\n", iii+1, answer);
  }
}
