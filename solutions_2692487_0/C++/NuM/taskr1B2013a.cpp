#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <sstream>

#define pb push_back
#define mp make_pair
#define PI 3.14159265358979
#define sqr(x) (x)*(x)
#define forn(i, n) for(int i = 0; i < n; ++i)
#define ALL(x) x.begin(), x.end()
#define sz(x) int((x).size())
#define X first
#define Y second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
typedef pair<int,int> pii;
const int INF = 2147483647;
const ll LLINF = 9223372036854775807LL;
const int maxn = 110;
int a[maxn];
int dp[maxn][maxn];
const int maxval = 1000000000;

void solve() {
  int A,n; scanf("%d%d", &A, &n);
  forn(i, n) scanf("%d", &a[i]);
  sort(a,a+n);
  forn(i, n+1) forn(j, n+1) dp[i][j] = -1;
  dp[0][0] = A;
  for(int i = 0; i < n; ++i) for (int j = 0; j <= n; ++j) {
    dp[i][j] = min(dp[i][j],maxval); 
    if (dp[i][j] == -1) continue;
    dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j]);
    if (dp[i][j] > a[i]) dp[i+1][j] = max(dp[i+1][j], dp[i][j]+a[i]);
    dp[i][j+1] = max(dp[i][j+1], 2*dp[i][j]-1);
  }
  int ans = 0;
  while (dp[n][ans] == -1) ++ans;
  printf("%d\n", ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
  int T; scanf("%d", &T); forn(test, T) {
    printf("Case #%d: ", test+1);
    solve();
  }
	return 0;
}