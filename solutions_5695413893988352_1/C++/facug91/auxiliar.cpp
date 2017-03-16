/*
	By: facug91
	From: 
	Name: 
	Date: 30/04/2016
*/

#include <bits/stdc++.h>
#define endl "\n"
#define next sbjkdfh329re9fdshfd98fyh
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = acos(-1.0);

#define INF 1000000000
#define MOD 1000000000ll
#define MAXN 100000005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

ll ansc, ansj;
string c, j;

void dfs (int idx, ll currc, ll currj) {
	//cerr<<"idx "<<idx<<" currc "<<currc<<" currj "<<currj<<endl;
	if (idx == c.length()) {
		if (abs(currc-currj) < abs(ansc-ansj)) {
			ansc = currc;
			ansj = currj;
		} else if (abs(currc-currj) == abs(ansc-ansj)) {
			if (currc < ansc) {
				ansc = currc;
				ansj = currj;
			} else if (currc == ansc) {
				if (currj < ansj) {
					ansc = currc;
					ansj = currj;
				}
			}
		}
		return;
	}
	if (c[idx] != '?' && j[idx] != '?') {
		dfs(idx+1, currc*10ll+(c[idx]-'0'), currj*10ll+(j[idx]-'0'));
		return;
	}
	if (c[idx] == '?' && j[idx] == '?') {
		if (currc == currj) {
			dfs(idx+1, currc*10ll+0, currj*10ll+1);
			dfs(idx+1, currc*10ll+1, currj*10ll+0);
			dfs(idx+1, currc*10ll+0, currj*10ll+0);
		} else if (currc > currj) {
			dfs(idx+1, currc*10ll+0, currj*10ll+9);
		} else {
			dfs(idx+1, currc*10ll+9, currj*10ll+0);
		}
		return;
	}
	if (c[idx] == '?') {
		ll jj = (j[idx]-'0');
		if (currc == currj) {
			dfs(idx+1, currc*10ll+jj, currj*10ll+jj);
			if (jj > 0ll) dfs(idx+1, currc*10ll+jj-1, currj*10ll+jj);
			if (jj < 9ll) dfs(idx+1, currc*10ll+jj+1, currj*10ll+jj);
		} else if (currc > currj) {
			dfs(idx+1, currc*10ll+0, currj*10ll+jj);
		} else {
			dfs(idx+1, currc*10ll+9, currj*10ll+jj);
		}
		return;
	}
	if (j[idx] == '?') {
		ll cc = (c[idx]-'0');
		if (currc == currj) {
			dfs(idx+1, currc*10ll+cc, currj*10ll+cc);
			if (cc > 0ll) dfs(idx+1, currc*10ll+cc, currj*10ll+cc-1);
			if (cc < 9ll) dfs(idx+1, currc*10ll+cc, currj*10ll+cc+1);
		} else if (currc > currj) {
			dfs(idx+1, currc*10ll+cc, currj*10ll+9);
		} else {
			dfs(idx+1, currc*10ll+cc, currj*10ll+0);
		}
		return;
	}
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(2); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	int tc = 1;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		cin>>c>>j;
		ansc = LLONG_MAX; ansj = 0;
		dfs(0, 0, 0);
		cout<<"Case #"<<it<<": "<<setfill('0')<<setw(c.length())<<ansc<<" "<<setfill('0')<<setw(c.length())<<ansj<<endl;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
