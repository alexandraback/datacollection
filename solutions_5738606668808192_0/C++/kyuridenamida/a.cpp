/*
	[Solution]
	Facebook Hacker Cup 2016 Round 2
	Boomerang Decoration
	https://www.facebook.com/hackercup/problem/424794494381569/
*/
#include <bits/stdc++.h>
#include <alloca.h>
#include "./fbclib.hpp"
using namespace std;

FBC fbc;
#define cin fbc.ifs


long long conv(long long n,long long b){
	stringstream ss;
	ss << n;
	string s = ss.str();
	long long r = 0;
	for(int i = 0 ; i < s.size() ; i++)
		r = r * b + s[i] - '0';
	return r;
}
long long divisor(long long n){
	if( n < 2 ) return -1;
	for(long long x = 2 ; x * x <= n ; x++){
		if( n % x == 0 ) return x;
	}
	return -1;
}
void solve(){
	int N;
	int J;
	cin >> N >> J;
	cout << "Case #1:" << endl;
	for(int i = 0 ; i < (1<<14) ; i++){
		long long v = 1;
		for(int j = 0 ; j < 14 ; j++)
			v = v * 10 + (i >> j & 1 );
		v = v * 10 + 1;
		vector<int> res;
		int f = 1;
		for(int j = 2 ; j <= 10 ; j++){
			res.push_back(divisor(conv(v,j)));
			if( res.back() == -1 ){ f = 0; break; }
		}
		if(f){
			cout << v;
			for(int j = 0 ; j < res.size() ; j++) cout << " " << res[j];
			cout << endl;
			--J;
			if( J == 0 ) break;
		}
	}
	
}
#undef cin


int main(int argc,char *argv[]){
	if( argc < 2 ) {
		cerr << "[Error] no input" << endl;
		exit(1);
	}else{
		fbc.init(argv[1]);
	}
	for( auto ____ : fbc ){
		solve();
	}
}