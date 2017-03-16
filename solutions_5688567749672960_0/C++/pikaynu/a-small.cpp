#include <bits/stdc++.h>
using namespace std;
const int N = 1234567;
int dp[N];
int rev(int n){
	int q = 0;
	while (n){
		q = q * 10 + n % 10;
		n /= 10;
	}
	return q;
}
void solve(int t)
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i<N; i++)
		dp[i] = INT_MAX;
	dp[1] = 1;
	for (int i = 1; i<=n; i++){
		dp[i + 1] = min(dp[i + 1], dp[i] + 1);
		dp[rev(i)] = min(dp[rev(i)], dp[i] + 1);
	}
	printf("Case #%d: %d\n", t, dp[n]);
}

int main()
{
	int t;
	cin >> t;
	for (int i = 1; i<=t; i++)
		solve(i);
	return 0;
}