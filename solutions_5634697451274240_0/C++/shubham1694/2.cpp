#include <bits/stdc++.h>

using namespace std;

#define sd(x) scanf("%d", &x)
#define boost ios_base::sync_with_stdio(false);
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define f first
#define s second

typedef pair<int, int> pii;
typedef long long ll;

const int mod = 1000000007;
const int inf = 50000000;
const int maxn = 110;

int dp[maxn][2], n;
char str[maxn];

int solve(int cur, int p)
{
	if(cur<=0)
		return 0;
	if(dp[cur][p]!=-1)
		return dp[cur][p];
	int ret;
	if(str[cur]=='+'){
		if(p)
			ret = solve(cur-1, p);
		else
			ret = 1+solve(cur-1, 1);
	}
	else{
		if(p)
			ret = 1+solve(cur-1, 0);
		else
			ret = solve(cur-1, p);
	}
	return dp[cur][p] = ret;
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);
	int t, i, cn=1, ans;
	scanf("%d", &t);
	while(t--){
		memset(dp, -1, sizeof(dp));
		scanf("%s", str+1);
		n = strlen(str+1);
		ans = solve(n, 1);
		printf("Case #%d: %d\n", cn++, ans);
	}
	
	return 0;
}
