#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define MAXN 1050
using namespace std;
double N[MAXN], K[MAXN];
int main(){
   int t, n, sum;
   freopen("in.in", "r", stdin);
   freopen("out.out", "w", stdout);
   scanf("%d", &t);
   for (int kl = 1; kl<=t; kl++){
      scanf("%d", &n);
      for (int i = 0; i!=n; i++) scanf("%lf", &N[i]);
      for (int i = 0; i!=n; i++) scanf("%lf", &K[i]);
      sort(N, N+n);
      sort(K, K+n);
      // for (int i = 0; i!=n; i++) printf("%.lf ", 1000*N[i]);
      // printf("\n");
      // for (int i = 0; i!=n; i++) printf("%.lf ", 1000*K[i]);
      sum = 0;
      int i1 = n-1, i2 = 0;
      for (int i = n-1; i>=0; i--) {
         if (N[i] > K[i1]){
            sum++;
            i2++;
         }
         else i1--;
      }
      int sum2 = 0, j1 = n-1, j2 = 0;
      i1 = n-1; i2 = 0;
      for (int i = n-1; i>=0; i--) {
         if (N[j2] > K[i2]){
            sum2++;
            j2++;
            i2++;
         }
         else {
            i1--;
            j2++;
         }
      }
      printf("Case #%d: %d %d\n", kl, sum2, sum);
   }
   return 0;
}

