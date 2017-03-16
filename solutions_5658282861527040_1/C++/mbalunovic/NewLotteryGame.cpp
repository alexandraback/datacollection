#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

typedef long long llint;

const int MaxN = 35;
const int MAX = 30;

int A, B, K, a[MaxN], b[MaxN], k[MaxN];
llint dp[MaxN][4][4][4];

llint f (int i, int da, int db, int dk) {
  if (i == MAX) return (da == 0 && db == 0 && dk == 0) ? 1 : 0;
  if (dp[i][da][db][dk] != -1) return dp[i][da][db][dk];
  
  llint ret = 0;

  for (int x = 0; x <= 1; ++x)
    for (int y = 0; y <= 1; ++y) {
      int z = x & y;
      if ((!da || x <= a[i]) && (!db || y <= b[i]) && (!dk || z <= k[i])) {
	int nda = (da && x == a[i]) ? 1 : 0;
	int ndb = (db && y == b[i]) ? 1 : 0;
	int ndk = (dk && z == k[i]) ? 1 : 0;
	ret += f(i + 1, nda, ndb, ndk);
      }
    }

  return dp[i][da][db][dk] = ret;
}

void solve (int c) {
  memset(dp, -1, sizeof(dp));
  scanf("%d %d %d",&A,&B,&K);
  for (int i = 0; i < 30; ++i) {
    a[29 - i] = (A & (1 << i)) != 0 ? 1 : 0;
    b[29 - i] = (B & (1 << i)) != 0 ? 1 : 0;
    k[29 - i] = (K & (1 << i)) != 0 ? 1 : 0;
  }
  
  printf("Case #%d: %lld\n",c,f(0,1,1,1));
}

int main (void) {
  int t;
  scanf("%d",&t);
  for (int c = 1; c <= t; ++c)
    solve(c);
  return 0;
}
