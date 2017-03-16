#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 100007;
int A, B;
double p[maxn];
double P[maxn];
void init()
{
     scanf("%d%d", &A, &B);
     P[0] = 0;
     for (int i=1; i<=A; i++) {
          scanf("%lf", &p[i]);
          P[i] = P[i-1] * p[i] + (1-P[i-1]) * (1-p[i]) + P[i-1] * (1-p[i]);
          // printf("i=%d: %lf\n", i, P[i]);
     }
}

double calc()
{
     double ans = B+2;
     for (int k=0; k<=A; k++) {
          ans = min(ans, (B-A+2*k+1)+P[A-k]*(B+1));
          // printf("%d: %lf\n", k, (B-A+2*k+1)+P[A-k]*(B+1));
     }
     return ans;
}

int main()
{
     int T;
     scanf("%d", &T);
     for (int t=1; t<=T; t++) {
          init();
          printf("Case #%d: %.6lf\n", t, calc());
     }
     return 0;
}
