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

Int ipow(Int a,Int b){
	Int r = 1;
	for(int i = 0 ; i < b ; i++)
		r *= a;
	return r;
}
void solve(){
	fbc.putCase();
	long long K,C,S;
	cin >> K >> C >> S;
	if( C == 1 ){
		if( S < K ){
			cout << "IMPOSSIBLE" << endl;
			return;
		}else{
			for(int i = 0 ; i < K ; i++) cout << i+1 << (i+1==K?"\n":" ");
			return;
		}
	}else{
		long long span = ipow(K,(C-1));
		int req = (K+1) / 2;
		if( S < req ){
			cout << "IMPOSSIBLE" << endl;
			return;
		}else{
			vector<long long> r;
			for(int i = 0 ; i < K ; i += 2 ){
				if( i + 1 == K ){
					r.push_back(span*i+i);
				}else{
					// cout << span << "-" << i << endl;
					r.push_back(span*i+i+1);
				}
			}
			for(int i = 0 ; i < r.size() ; i++)
				cout << r[i]+1 << (i+1==r.size()?"\n":" ");
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