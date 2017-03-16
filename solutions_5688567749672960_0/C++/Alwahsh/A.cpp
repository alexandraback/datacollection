#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll t;

ll dp[10000005];
bool visited[10000005];
ll wanted;

ll reverse(int num) {
	ll s = 0;
	while(num) {
		ll to_add = num%10;
		num/= 10;
		s*= 10;
		s+= to_add;
	}
	return s;
}

int soln(int num) {
	if (num == 1)
		return 1;
	if (dp[num] != -1)
		return dp[num];
	if (visited[num])
		return 100000000;
	visited[num] = true;
	int first = soln(num-1);
	int second = 100000000;
	if (num%10)
		second = soln(reverse(num));
	dp[num] = 1 + min(first,second);
	return dp[num];
}

void preprocess() {
	dp[0] = 10000000;
	dp[1] = 1;
	for (int i = 2; i < 1000005; i++) {
		if (i % 10 == 0 || reverse(i) >= i)
			dp[i] = dp[i-1] + 1;
		else
			dp[i] = 1+min(dp[i-1],dp[reverse(i)]);
	}
}

int main() {
	ios::sync_with_stdio(0);
	freopen("A-small-attempt7.in","r",stdin);
	freopen("a.out","w",stdout);
	preprocess();
	/*
	for (int i = 1; i < 25; i++) {
		cout << dp[i] << endl;
	}
	*/
	cin >> t;
	for (int cntt = 1; cntt <= t; cntt++) {
		cout << "Case #" << cntt << ": ";
		cin >> wanted;
		cout << dp[wanted];
		cout << endl;
	}

	return 0;
}
