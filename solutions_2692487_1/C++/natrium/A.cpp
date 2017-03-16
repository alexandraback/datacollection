#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define reps(i,f,n) for(int i=f; i<int(n); ++i)
#define rep(i,n) reps(i,0,n)

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

const int INF = 1001001001;
const double EPS = 1e-10;
const int MAX = 2000000;

int solve()
{
	int a, n;
	scanf("%d%d", &a, &n);
	
	vi mote(n);
	rep(i, n)
		scanf("%d", &mote[i]);
	sort(mote.begin(), mote.end());
	
	if(a == 1)
		return n;
	
	vvi dp(n+1, vi(21, 0));
	dp[0][0] = a;
	reps(j, 1, 21)
		dp[0][j] = min(dp[0][j-1]*2-1, MAX);
	
	for(int i=1; i<=n; ++i){
		dp[i][0] = dp[i-1][0]>mote[i-1] ? dp[i-1][0]+mote[i-1] : 0;
		dp[i][0] = min(dp[i][0], MAX);
		reps(j, 1, 21){
			dp[i][j] = dp[i][j-1]*2 - 1;
			dp[i][j] = max(dp[i][j], dp[i-1][j]>mote[i-1] ? dp[i-1][j]+mote[i-1] : 0);
			dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
			dp[i][j] = min(dp[i][j], MAX);
		}
	}
	
	rep(j, 21){
		if(dp[n][j])
			return j;
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	rep(i, t){
		printf("Case #%d: %d\n", i+1, solve());
	}
	return 0;
}