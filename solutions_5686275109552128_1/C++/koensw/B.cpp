#include <iostream>
#include <cmath>

int am[1001];
long long dpz[1001][1001];

long long dp(long long n, int k){
	if(n <= k) return 0;
	if(dpz[n][k] != -1) return dpz[n][k];
	long long b = 1001;
	for(int i=2; i*i<=n; ++i){
		long long p = n/i;
		long long k2 = n%i;
		long long k1 = i-k2;
		b = std::min(b, i-1+k1*dp(p, k)+k2*dp(p+1, k));
	}
	return dpz[n][k] = b;
}

void solve(long long n){
	long long N;
	std::cin >> N;
	for(int i=0; i<N; ++i){
		std::cin >> am[i];
	}
	long long fa = 1001;
	for(long long j=2; j<1001; ++j){
		long long a = 0;
		long long m = 0;
		for(long long i=0; i<N; ++i){
			long long k = am[i];
			m = std::max(m, std::min(k, j));
			a += dp(k, j);
		}
		fa = std::min(fa, a+m);
	}
	std::cout << "Case #" << n << ": " << fa << std::endl;
}

int main(){
	for(long long i=0; i<1001; ++i) for(long long j=0; j<1001; ++j) dpz[i][j] = -1;
	long long T;
	std::cin >> T;
	long long n = 1;
	while(T--) solve(n), ++n;
}