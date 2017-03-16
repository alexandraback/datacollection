#include<cstdio>
#include<map>
#include<algorithm>

using namespace std;

#define range(i, a, b) for(int i(a); i < (b); i++)
#define rep(i, n) range(i, 0, n)

#define long long long
#define pll pair<long, long>

const int MAX_N = 105;

int n, m;
long a[MAX_N], b[MAX_N];
long A[MAX_N], B[MAX_N];
map<pll, long> dp[MAX_N][MAX_N];

inline long OPT(int i, int j, long x, long y){
  if(i == 0 or j == 0){
    return 0;
  }
  if(not dp[i][j].count(pll(x, y))){
    if(A[i] == B[j]){
      if(x < y){
	dp[i][j][pll(x, y)] = OPT(i - 1, j, a[i - 1], y - x) + x;
      }
      else if(x > y){
	dp[i][j][pll(x, y)] = OPT(i, j - 1, x - y, b[j - 1]) + y;
      }
      else{
	dp[i][j][pll(x, y)] = OPT(i - 1, j - 1, a[i - 1], b[j - 1]) + x;
      }
    }
    else{
      dp[i][j][pll(x, y)] = max(OPT(i - 1, j, a[i - 1], y), OPT(i, j - 1, x, b[j - 1]));
    }
  }
  return dp[i][j][pll(x, y)];
}

int main(){
  int T;
  freopen("ans3.txt", "w", stdout);
  scanf("%d", &T);
  range(t, 1, T + 1){
    scanf("%d %d", &n, &m);
    rep(i, n + 1){
      rep(j, m + 1){
	dp[i][j].clear();
      }
    }
    range(i, 1, n + 1){
      scanf("%lld %lld", &a[i], &A[i]);
    }
    range(i, 1, m + 1){
      scanf("%lld %lld", &b[i], &B[i]);
    }
    printf("Case #%d: %lld\n", t, OPT(n, m, a[n], b[m]));
  }
}
