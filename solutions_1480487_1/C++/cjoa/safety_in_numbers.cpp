#include <cstdio>

using namespace std;

int N;
int S[204];
int sum;

#define EPS 1e-11

bool check(int idx, double x) {
   double score = S[idx] + sum * x;
   double p = 0.0;
   for (int i = 0; i < N; ++i) {
      if (i == idx) continue;
      if (score <= S[i] + EPS) continue;
      double req_x = (score - S[i]) / sum;
      p += req_x;
   }
   return p+x > 1.0 + EPS;
}

double binary_search(int idx) {
   double lo = 0.0, hi = 1.0;
   for (int t = 1; t <= 200; ++t) {
      double mid = (lo+hi)/2;
      if (check(idx, mid))
         hi = mid;
      else
         lo = mid;
   }
   return (lo+hi)/2;
}

int main(int argc, char* argv[]) {
   int TC;
   scanf("%d", &TC);
   for (int tc = 1; tc <= TC; ++tc) {
      scanf("%d", &N);
      sum = 0;
      for (int i = 0; i < N; ++i) {
         scanf("%d", S+i);
         sum += S[i];
      }
      printf("Case #%d:", tc);
      for (int i = 0; i < N; ++i) {
         double res = binary_search(i);
         printf(" %.7lf", res*100);
      }
      putchar('\n');
   }
   return 0;
}
