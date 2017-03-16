//AV
//quasar

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 5;
int dp[N];

int rev(int n){
	int r = 0;
	while (n){
		r *= 10;
		r += n % 10;
		n /= 10;
	}
	return r;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	fill(dp, dp + N, 1 << 30);
	dp[1] = 1;
	const int M = 1e6;
	for (int i = 1; i < M; i++){
		dp[i + 1] = min(dp[i + 1], dp[i] + 1);
		int r = rev(i);
		dp[r] = min(dp[r], dp[i] + 1);
	}

	int t, n;
	int cs = 1;
	cin >> t;
	while (t--){
		cin >> n;
		cout << "Case #" << cs << ": " << dp[n] << "\n";
		cs++;
	}
}
