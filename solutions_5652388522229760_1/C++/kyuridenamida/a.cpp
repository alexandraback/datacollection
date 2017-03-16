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

string A,B;
int dp[100010][26][2];
int dp2[100010][26][2];

int dfs1(int x,int col,int unchg){
	if( x == -1 ) return 0;
	if( dp[x][col][unchg] != -1 ) return dp[x][col][unchg];
	int ans;
	if( (unchg?A[x]:col + 'A') != B[x] ){
		ans = dfs1(x-1,B[x]-'A',0) + 1;
	}else{
		ans = dfs1(x-1,col,unchg);
	}
	return dp[x][col][unchg] = ans;
}
int dfs2(int x,int col,int unchg){
	if( x == B.size() ) return 0;
	if( dp2[x][col][unchg] != -1 ) return dp2[x][col][unchg];
	int ans;
	if( (unchg?A[x]:col + 'A') != B[x] ){
		ans = dfs2(x+1,B[x]-'A',0) + 1;
	}else{
		ans = dfs2(x+1,col,unchg);
	}
	return dp2[x][col][unchg] = ans;
}

#define cin fbc.ifs
void solve(){
	long long N;
	cin >> N;
	fbc.putCase();
	int f = 0;
	int bit = 0;
	for(int i = 1 ; i < 10000000 ; i++){
		long long v = i * N;
		while( v ) {
			bit |= 1<<(v%10);
			v /= 10;
		}
		if( bit == 1023 ) {
			cout << N*i << endl;
			f = 1;
			break;
		}
	}
	if( !f ){
		cout << "INSOMNIA" << endl;
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