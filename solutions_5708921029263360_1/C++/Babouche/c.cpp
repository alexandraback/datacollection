// solution by Olivier Marty

//#define ONLINE_JUDGE
#include <bits/stdc++.h>
#define fin(i, n) for(int i = 0; i < n; i++)
#define fin2(i, a, b) for(int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
using namespace std;

#ifndef ONLINE_JUDGE
  #define debug(a) cerr << #a << " = " << (a) << endl
#else
  #define debug(a)
#endif

int J, P, S, K;

void parse() {
  scanf("%d%d%d%d", &J, &P, &S, &K);
}

void solve() {
  printf("%d", J*P*min(S,K));
  int sj[J], sp[P];
  memset(sj, 0, sizeof(sj));
  memset(sp, 0, sizeof(sp));
  for(int j = 1; j <= J; j++)
    for(int p = 1; p <= P; p++)
      for(int s = 1; s <= min(S, K); s++) {
        int *sjp = sj + (j-1);
        int *spp = sp + (p-1);
        int r = max(*sjp, *spp) + 1;
        if(r > S)
          r = 1;
        *sjp = *spp = r;
        printf("\n%d %d %d", j, p, r);
      }
}

int main() {
  //ios::sync_with_stdio(false);
  int T;
  scanf("%d", &T);
  for(int i = 1; i <= T; i++) {
    parse();
    printf("Case #%d: ", i);
    solve();
    printf("\n");
    #ifdef DEBUG
		  fprintf(stderr, "%d / %d = %.2fs | %.2fs\n", i, T, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / i * T) / CLOCKS_PER_SEC);
    #endif
  }
  return 0;
}
