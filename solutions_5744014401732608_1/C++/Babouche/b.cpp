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

int B;
long long M;

void parse() {
  cin >> B >> M;
}

long long pow2(int i) {
  if(!i)
    return 1;
  long long l= pow2(i/2);
  if(i % 2)
    return l*l*2;
  return l*l;
}

void solve() {
  long long p2 = pow2(B-2);
  if(M > p2)
    printf("IMPOSSIBLE");
  else {
    printf("POSSIBLE\n0");
    if(M == p2)
      for(int i = 1; i < B; i++)
        printf("1");
    else {
      p2 /= 2;
      for(int i = 1; i < B; i++) {
        printf("%d", M & p2 ? 1 : 0);
        p2 /= 2;
      }
    }
    for(int j = 1; j < B; j++) {
      printf("\n");
      for(int i = 0; i < B; i++)
        printf("%d", i > j ? 1 : 0);
    }
  }
}

int main() {
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
