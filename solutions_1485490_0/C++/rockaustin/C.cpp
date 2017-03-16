using namespace std;
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
pair<long long, int> A[102];
pair<long long, int> B[102];
int n,m;
long long dp[110][110];
bool memo[110][110];
long long solve(int i, int j) {
	if (memo[i][j]) return dp[i][j];
	memo[i][j] = true;
	if (i>=n || j>=m) return dp[i][j] = 0;
	long long ret = max(solve(i+1, j), solve(i, j+1));
	// You are going to use the upper one;
	long long AI = 0, BI = 0;
	for (int k=i;k<n;k++) {
		if (A[k].second == A[i].second) AI += A[k].first;
		if (A[k].second == B[j].second) BI += A[k].first;
		long long  AJ = 0 , BJ = 0;
		for (int l=j;l<m;l++) {
			if (B[l].second == A[i].second) AJ += B[l].first;
			if (B[l].second == B[j].second) BJ += B[l].first;
			long long take = max(min(BI, BJ) + solve(k+1, l+1), min(AI, AJ) + solve(k+1, l+1));
			ret = max(ret, take);
		}
	}
	return dp[i][j] = ret;
}
// check for long long.
int main() {
	int tc;
	cin>>tc;
	int caseno = 1;
	while(tc--) {
		memset(memo, 0, sizeof(memo));
		scanf("%d%d",&n,&m);
		for (int i=0;i<n;i++) {
			scanf("%lld%d", &A[i].first, &A[i].second);
		}
		for (int i=0;i<m;i++) {
			scanf("%lld%d", &B[i].first, &B[i].second);
		}
		long long take = solve(0, 0);
		printf("Case #%d: %lld\n", caseno++, take);
	}
	return 0;
}