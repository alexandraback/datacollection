//By Lin
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<cctype>
#include<cmath>

#define eps 1e-9
#define sqr(x) ((x)*(x))
#define Rep(i,n) for(int i = 0; i<n; i++)
#define foreach(i,n) for( __typeof(n.begin()) i = n.begin(); i!=n.end(); i++)
#define X first
#define Y second
#define mp(x,y) make_pair(x,y)

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define N 1010

int m, n[N], data[110][1010];
int dp[N], ans[110], cur[110];

int		main(){
	int cas, tt = 0;
	scanf("%d", &m);
	Rep(i, m) {
		scanf("%d", &n[i]);
		Rep(j, n[i]) scanf("%d", &data[i][j]);
	}
	Rep(i, m) ans[i] = 0x7fffffff;
	for (int val = 1; val <= 1000; val++) {
		for (int i = 1; i<= val; i++) dp[i] = 0;
		for (int i = val + 1; i<= 1000; i++) {
			dp[i] = 0x7fffffff;
			for (int k = 1; k <= i - 1; k++)
				dp[i] = min(dp[i], dp[k] + dp[i - k] + 1);
		}
		Rep(i, m) cur[i] = 0;
		Rep(i, m) Rep(j, n[i]) cur[i] += dp[data[i][j]];
		Rep(i, m) ans[i] = min(ans[i], cur[i] + val);
	}
	Rep(i, m)
		printf("Case #%d: %d\n", i + 1, ans[i]);
	return 0;
}
