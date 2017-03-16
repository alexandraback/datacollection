#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 110;
const int M = 1e6+10;
const int inf = -1u/2;

#define c(i) min (i, M-1)

int dp[2][M];
int x[N];

inline int solve () {
  int A,n;
  scanf ("%d %d", &A, &n);

  for (int i = 0;i < M;i ++) dp[1][i] = inf;
  dp[1][A] = 0;

  for (int i = 1;i <= n;i ++) {
    scanf ("%d", x+i);
  }

  sort (x+1, x+n+1);

  for (int i = 1;i <= n;i ++) {
    for (int j = 0;j < M;j ++) dp[i+1&1][j] = inf;
    for (int j = 0;j < M;j ++) {
      if (dp[i&1][j] != inf) {
	if (j > x[i]) {
	  dp[i+1&1][c (j+x[i])] = min (dp[i+1&1][c (j+x[i])], dp[i&1][j]);
	} else {
	  dp[i+1&1][j] = min (dp[i+1&1][j], dp[i&1][j]+1);
	  if (j > 1) {
	    int cnt = 1,k = j+j-1;
	    while (k <= x[i]) {
	      k += k-1;
	      cnt ++;
	    }
	    k += x[i];
	    dp[i+1&1][c (k)] = min (dp[i+1&1][c (k)], dp[i&1][j]+cnt);
	  }
	}
      }
    }
  }

  int sol = inf;
  for (int i = 0;i < M;i ++) {
    sol = min (sol, dp[n+1&1][i]);
  }
  return sol;
}

int main () {
  int test;
  scanf ("%d ", &test);

  for (int Case = 1;Case <= test;Case ++) {
    printf ("Case #%d: %d\n", Case, solve ());
  }
}
