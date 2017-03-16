/* Written by Filip Hlasek 2013 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 1111111
int a[MAXN], A, N;
int dp[2][2*MAXN];

int main(int argc, char *argv[]){
  int T;
  scanf("%d", &T);
  REP(t, T) {
    printf("Case #%d: ", t + 1); 
    scanf("%d%d", &A, &N);
    REP(i, N) scanf("%d", a + i);
    sort(a, a + N);
    REP(i, a[N-1] + 2) dp[0][i] = dp[1][i] = MAXN;
    dp[0][min(a[N-1]+1, A)] = 0; 
    REP(n, N) {
      int act = n % 2, nact = 1 - act;
      FOR(i, 1, a[N-1] + 1) {
        // printf("n: %d i: %d dp: %d a[n]: %d\n", n, i, dp[act][i], a[n]);
        if(i > a[n]) {
          dp[nact][min(a[N-1]+1,i+a[n])] = min(dp[nact][min(a[N-1]+1,i+a[n])], dp[act][i]);
          // printf("updating: %d = %d\n", min(a[N-1]+1,i+a[n]), dp[act][i]);
        }
        else {
          dp[nact][i] = min(dp[nact][i], dp[act][i] + 1);
          dp[act][min(a[N-1]+1, 2*i-1)] = min(dp[act][min(a[N-1]+1,2*i-1)], dp[act][i] + 1);
        }
        dp[act][i] = MAXN;
      }
    }
    int ans = MAXN;
    REP(i, a[N-1] + 2) ans = min(ans, dp[N%2][i]);
    printf("%d\n", ans);
  }
  return 0;
}
