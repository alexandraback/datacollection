#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

bool mat[110][110];

void solve(int n, ll m) {
  memset(mat, 0, sizeof(mat));

  for (int i = n-2; i > 0; i--) {
    for (int j = i+1; j < n; j++) mat[i][j] = 1;
  }

  ll maxi = 1LL<<(n-2);

  if (m > maxi) puts("IMPOSSIBLE");
  else {
    puts("POSSIBLE");
    if (m == maxi) {
      for (int j = 1; j < n; j++) {
        mat[0][j] = 1;
      }
    }
    else {
      for (int k = 0; n-2-k >= 0; k++) {
        if ((m>>k)&1) mat[0][n-2-k] = 1;
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        printf("%d", mat[i][j]);
      }
      puts("");
    }
  }
}


int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    ll B, M;
    scanf("%lld%lld", &B, &M);
    printf("Case #%d: ", t);
    solve(B, M);
  }

  return 0;
}
