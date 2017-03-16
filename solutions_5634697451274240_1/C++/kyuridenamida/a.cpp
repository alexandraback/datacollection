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


string norm(string s){
	while( s.size() && s.back() == '+' ) s = s.substr(0,s.size()-1);
	return s;
}

string apply(string s,int k){
	for(int i = 0 ; i <= k ; i++)
		s[i] = s[i] == '+' ? '-' : '+';
	reverse(s.begin(),s.begin()+k+1);
	return norm(s);
}
void solve(){
	string s;
	cin >> s;
	s = norm(s);
	fbc.putCase();
	queue<string> Q;
	map<string,int> cost;
	Q.push(s);
	cost[s] = 0;
	while( Q.size() ){
		string q = Q.front(); Q.pop();
		if( q.size() == 0 ){
			cout << cost[q] << endl;
			break;
		}
		int lp = 0;
		while( lp < q.size() && q[lp] == '+' ) lp++;
		if( lp == 0 ){
			string t = apply(q,q.size()-1);
			if( cost.count(t) == 0 ){
				// cout << q << "(" << i << ")" << " to " << t << endl;
				cost[t] = cost[q] + 1;
				Q.push(t);
			}
		}else{
			string t = apply(q,lp-1);
			if( cost.count(t) == 0 ){
				// cout << q << "(" << i << ")" << " to " << t << endl;
				cost[t] = cost[q] + 1;
				Q.push(t);
			}
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