#include <cstdio>

#include <algorithm>

using namespace std;

int A, B;
double P[100004];
double PCorr[100004];

void preprocess() {
   PCorr[0] = 1;
   for (int i = 1; i <= A; ++i) {
      PCorr[i] = PCorr[i-1] * P[i];
   // fprintf(stderr, "%d: %3lf\n", i, PCorr[i]);
   }
}

double solve0() {
   // press enter and the whole password
   double res = 1 + B + 1;
// fprintf(stderr, "res0 = %.3lf\n", res);
   return res;
}

double solve1() {
   // keep typing
   double p = PCorr[A];
// fprintf(stderr, "p = %.3lf\n", p);
   double res = (B - A + 1) + (1-p) * (B + 1);
// fprintf(stderr, "res1 = %.3lf\n", res);
   return res;
}

double solve2() {
   double res = 1e10;
   for (int i = 1; i <= A; ++i) {
      // delete upto ith character
      double cur = 
         PCorr[i-1] * (A-i+1+ B-i+1 + 1) +
         (1-PCorr[i-1]) * (A-i+1+ B-i+1 + 1 + B + 1);
   // fprintf(stderr, "Deleting upto %d: %.3lf %.3lf\n", i, PCorr[i-1], cur);
      res = min(res, cur);
   }
// fprintf(stderr, "res2 = %.3lf\n", res);
   return res;
}

int main(int argc, char* argv[]) {
   int TC;
   scanf("%d", &TC);
   for (int tc = 1; tc <= TC; ++tc) {
      scanf("%d %d", &A, &B);
      for (int i = 1; i <= A; ++i)
         scanf("%lf", P+i);
      preprocess();
      double res = solve0();
      res = min(res, solve1());
      res = min(res, solve2());
      printf("Case #%d: %.7lf\n", tc, res);
   }
   return 0;
}
