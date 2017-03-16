#include <bits/stdc++.h>
using namespace std;
#define int long long 
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

long long g(long long n){
	if( n == 0 ) return 0;
	if( rev(n) < n && f(rev(n))+1 == f(n) ){
		g(rev(n));
	}else{
		g(n-1);
	}
	cout << n << endl;
}
int digit(long long x){
	int c=0;
	while(x) x /= 10,c++;
	return c;
}
long long naive(long long cur,long long x){
	if( cur == x ) return 0;
	
	long long hoge = (digit(cur)+1) / 2;
	long long ten = 1;
	for(int i = 0 ; i <= hoge ; i++) ten *= 10;
	long long target = 1;
	
	if( digit(cur) < digit(x) ){
		for(int i = 0 ; i < digit(cur) ; i++) target *= 10;
	}else{
		target = x;
	}
	long long ans = target-cur;
	for(int i = 0 ; i < ten ; i++){
		long long v = rev(cur+i);
		if( cur+i > target ) continue;
		if( v > target ) continue;
		long long cnt = target - v + i + 1;
		ans = min(ans,cnt);
	}
	return naive(target,x)+ans;
}
signed main(){
	memset(dp,-1,sizeof(dp));
	int T;
	cin >> T;
	while(T--){
		long long N;
		cin >> N;
		//N = 100000000000000ll;
		putCase();
		cout << naive(0,N) << endl;
		
	}
}