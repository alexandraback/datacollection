#include<iostream>
#include<algorithm>
using namespace std;

long long dp[1000001], t, n;


int reverse(int v) {
	int tpow = 1;
		
	
	int result = 0;
	
	while(tpow <= v) {
		result *= 10;
		result += (v % (tpow * 10) ) / tpow;
		
		tpow *= 10;
	}
	
	return result;
}




int main() {
	
	fill(dp, dp + 1000001, 1000000000000000000LL);
	
	dp[1] = 1;
	
	for(int i=1;i<1000000;i++) {
		int rev = reverse(i);
		
		dp[i+1] = min(dp[i+1], dp[i] + 1);
		
		dp[rev] = min(dp[rev], dp[i] + 1);
	}
	
	
	cin >> t;
	
	for(int TCASE = 0; TCASE < t; TCASE++) {
		cin >> n;
		
		cout << "Case #" << TCASE + 1 << ": " << dp[n] << '\n';
	}
	
	return 0;
}
