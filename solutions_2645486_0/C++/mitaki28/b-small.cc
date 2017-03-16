#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<string>
#include<functional>
#include<queue>

#define FOR(i, a, n) for(int i = (a); i < (n); i++)
#define FORN(i, a, n) for(int i = (a); i <= (n);i++)
#define REP(i, n) FOR(i, 0, n)
#define REPN(i, n) FORN(i, 1, n)
#define ABS(x) (x) > 0 ? (x) : -(x)
#define SIZE(vec) (int)vec.size()

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int MAX_N = 11;
const int MAX_E = 6;
const int INF = 1 << 28;
const double EPS = 1e-9;
const double PI = 3.14159265358979;

int E, R, N;
int a[MAX_N];
int dp[MAX_N][MAX_E];

int dfs(int d, int e){
  if(dp[d][e] != -1) return dp[d][e];
  if(d == N) return dp[d][e] = 0;
  int r = 0;
  FORN(j, 0, E) if(j <= e){
	r = max(r, dfs(d + 1, min(E, e - j + R)) + j * a[d]);
  }
  return dp[d][e] = r;
}

int solve(){
  memset(dp, -1, sizeof(dp));
  return dfs(0, E);
}

int main(){
  int T;
  cin >> T;
  REP(t, T){
	cin >> E >> R >> N;
	REP(i, N) cin >> a[i];
	printf("Case #%d: %d\n", t + 1, solve());
  }
  return 0;
}
