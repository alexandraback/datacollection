#include <bits/stdc++.h>
using namespace std;

long long N, T;

long long max(long long a, long long b){return a>b ? a : b;}
long long lg(long long x){return x ? 1+lg(x/10) : 0;}
long long power(long long x){return x ? 10*power(x-1) : 1;}
long long rpower(long long x){return x ? power(x)-1 : 0;}
long long reverse(long long x){
	long long ret = 0;
	while(x){
		ret *= 10;
		ret += x % 10;
		x/= 10;
	}
	return ret;
}

long long moves(long long n){
	if(!n) return 0;
	long long digits = lg(n);
	long long base = power(digits-1);
	long long ret = moves(base-1) + 1;
	if(n == base) return ret;
	--n;
	++ret;
	long long best = n - base;
	for(int i=0; i<2; ++i){
		long long dig = i ? digits/2 : digits-digits/2;
		long long stem = n / power(dig);
		long long leaf = n % power(dig);
		long long working = 0;
		working += reverse(stem);
		working += leaf;
		best = min(best, working);
	}
	ret += best;
	return ret;
}

int main() {
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	cin >> T;
	for(int t=1; t<=T; ++t){
		cin >> N;
		cout << "Case #" << t << ": " << moves(N) << '\n';
	}
}
