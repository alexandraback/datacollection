#include <bits/stdc++.h>
using namespace std;

int putCase(){
	static int t = 1;
	cout << "Case #"<< t++ << ": ";
}
long long dp[1000010];
long long rev(long long a){
	long long b = 0;
	if( a % 10 == 0 ) return 1e18;
	while(a){
		
		b = b * 10 + a % 10;
		a /= 10;
	}
	return b;
}
long long f(long long n){
	if( n == 0 ) return 0;
	if( dp[n] != -1 ) return dp[n];
	long long ans = 1e18;
	if( rev(n) < n ){
		ans = min(ans,f(rev(n)) + 1);
	}
	ans = min(ans,f(n-1) + 1);
	
	return dp[n] = ans;
}
int main(){
	memset(dp,-1,sizeof(dp));
	for(int i = 0 ; i <= 1000000 ; i++)
		f(i);
	int T;
	cin >> T;
	while(T--){
		long long N;
		cin >> N;
		putCase();
		cout << f(N) << endl;
	}
}