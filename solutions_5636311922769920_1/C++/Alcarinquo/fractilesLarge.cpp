#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>

using namespace std;

int main() {
  int T;
  int k, c, s;

  scanf("%d", &T);

  for(int caso = 1; caso <= T; caso++) {
    scanf("%d %d %d", &k, &c, &s);

    printf("Case #%d:", caso);

    if(s < ceil(((double) k) / (double)c))
      printf(" IMPOSSIBLE\n");
    else {
      if(c == 1) {
        for(int i = 1; i <= k; i++) printf(" %d", i);
        printf("\n");
      } else {
        long long int K, C, N, D, P, pot;
        K = k;
        C = c;
        N = 0;


        while(N < K) {
          D = min(C, K-N) - 1;
          P = 0LL;
          pot = 1LL;
          for(int exp = 1; exp < c; exp++)
            pot = pot*K;

          for(int exp = 0; exp < c; exp++) {
            P += N*pot + D*pot;
            pot = pot/K;
            D = max(0LL, D-1);
          }

          printf(" %lld", P+1);
          N = N+min(C, K-N);
        }
        printf("\n");
      }
    }

  }

  return 0;
}
