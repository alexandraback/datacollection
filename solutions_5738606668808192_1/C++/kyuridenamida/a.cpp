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

using Int = __int128;

Int conv(Int bit,int len,Int b){
	Int r = 1;
	for(int i = 0 ; i < len-2 ; i++)
		r = r * b + (bit >> i & 1);
	r = r * b + 1;
	return r;
}
Int divisor(Int n){
	if( n < 2 ) return -1;
	for(Int x = 2 ; x * x <= min((Int)1e9,n) ; x++){
		if( n % x == 0 ) return x;
	}
	return -1;
}
void solve(){
	int N;
	int J;
	cin >> N >> J;
	cout << "Case #1:" << endl;
	for(int i = 0 ; i < (1<<(N-2)) ; i++){
		vector<int> res;
		int f = 1;
		for(int j = 2 ; j <= 10 ; j++){
			res.push_back(divisor(conv(i,N,j)));
			if( res.back() == -1 ){ f = 0; break; }
		}
		if(f){
			cout << 1;
			for(int j = 0 ; j < N-2 ; j++)
				cout << (i>>j&1);
			cout << 1;
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