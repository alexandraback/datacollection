#include <cstdio>

int N, X, Y;

double ncr(double n, int r) {
    double ans = 1;
    int i;
    for (i = 1; i <= r; i++)
        ans*=(n+1-i)/i;
    return ans;
}

int main() {
    int T, TT;
    scanf("%d", &TT);
    for (T = 1; T <= TT; T++) {
         printf("Case #%d: ", T);
         scanf("%d%d%d", &N, &X, &Y);
         if (X < 0)
             X = -X;
         int n;
         for (n = 1; n*(n+1)/2<=N; n+=2);
         n-=2;
         if (X + Y <= n-1) {
             printf("1\n");
             continue;
         }
         if (X + Y > n+1) {
             printf("0\n");
             continue;
         }
         if (Y == n + 1) {
             printf("0\n");
             continue;
         }
         int r = N - n*(n+1)/2;
         double ans = 0;
         double div = 1;
         int i;
         for (i = 0; i < r; i++)
             div/=2;
         for (i = 0; i <= r; i++) {
             double p = ncr(r, i) * div;
             if (i > Y)
                 ans+=p;
             else if (r-(n+1) > Y)
                 ans+=p;
         }
         printf("%lf\n", ans);
    }
}