/*
 * Round1C-B.cpp
 *
 *  Created on: May 11, 2014
 *      Author: Ghoooo
 */

#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>
//#include <windows.h>

using namespace std;

#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz(v) ((ll)v.size())
#define rep(i,m) for(int i=0;i<(int)(m);++i)
#define rep2(i,n,m) for(int i=n;i<(int)(m);i++)
#define For(it,c) for(__typeof(c.begin()) it=c.begin();it!=c.end();++it)
#define reset(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define dot(a,b) ((conj(a)*(b)).X)
#define X real()
#define Y imag()
#define length(V) (hypot((V).X,(V).Y))
#define vect(a,b) ((b)-(a))
#define cross(a,b) ((conj(a)*(b)).imag())
#define normalize(v) ((v)/length(v))
#define rotate(p,about,theta) ((p-about)*exp(point(0,theta))+about)
#define pointEqu(a,b) (comp(a.X,b.X)==0 && comp(a.Y,b.Y)==0)
#define clrq(x) while(!x.empty()) x.pop();
#define clrvv(v) rep(i,sz(v))v[i].clear();

typedef stringstream ss;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int> > vii;
typedef long double ld;
typedef complex<double> point;
typedef pair<point, point> segment;
typedef pair<double, point> circle;
typedef vector<point> polygon;
typedef unsigned long long ull;
typedef long long ll;

//==============================================================
// handling triples
typedef pair<ll,pair<ll,ll> > triple;
#define tfirst first
#define tsecond second.first
#define tthird second.second
#define mt(x,y,z) mp(x,mp(y,z))
//---------------------------------------------------------------


const int oo = (int) 1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-9;

int t, n;
string arr[101];
vector<int> grps[26];
bool visitedChars[26];
bool isAll(int idx, char c){
	string s = string(sz(arr[idx]), c);
	return s == arr[idx];
}
bool isValidStart(char c){
	int ret = 0;
	rep(i,n){
		int f = arr[i].find(c);
		if(f == -1) continue;
		if(f != 0) return false;
		ret = true;
	}
	return ret;
}
void go(char c, int idx, int prev){
	if(visitedChars[c-'a']){ grps[idx].pb(0); return;}
	visitedChars[c-'a'] = true;
	int cnt = 0;
	int nextStart = -1, cntValid = 0;
	rep(i,n){
		if(isAll(i,c)) cnt++;
		else {
			int f = arr[i].find(c);
			if(i != prev && f != -1 && f != 0) {grps[idx].pb(0); return;}
			if(arr[i][0] == c){
				cntValid++;
				nextStart = i;
			}
		}
	}
	if(cnt <= 1) grps[idx].pb(1);
	else grps[idx].pb(cnt);

	if(cntValid == 0) return;
	if(cntValid > 1) {grps[idx].pb(0); return;}

	bool flag = true;
	rep(i,sz(arr[nextStart])){
		if(arr[nextStart][i] == arr[nextStart][0] && flag) continue;
		flag = false;
		if(visitedChars[arr[nextStart][i] - 'a']){
			grps[idx].pb(0);
			return;
		}
	}
	rep(i,sz(arr[nextStart])){
		visitedChars[arr[nextStart][i] - 'a'] = true;
	}
	visitedChars[(*arr[nextStart].rbegin()) - 'a'] = false;
	go((*arr[nextStart].rbegin()), idx, nextStart);
}
long long perm[101];
long long MOD = (int)1e9 + 7;
void pre(){
	perm[0] = 0;
	rep2(i,1,101){
		perm[i] = 1;
		rep2(k,1,i+1){
			perm[i] = (perm[i] * k) % MOD;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	cin >> t;
	pre();
	rep2(casenum,1,t+1){
		cin >> n;
		reset(visitedChars,1);
		rep(i,n){
			cin>>arr[i];
			rep(k,sz(arr[i])){
				visitedChars[arr[i][k]-'a'] = false;
			}
		}
		rep(i,26)grps[i].clear();
		int grp_cnt = 0;
		rep(i,26){
			if(visitedChars[i]) continue;
			if(!isValidStart('a'+i)) continue;
			go('a'+i, grp_cnt++, -1);
		}
		long long ans = perm[grp_cnt];
		rep(i,grp_cnt){
			rep(k,sz(grps[i])){
				ans = (ans * perm[grps[i][k]]) % MOD;
			}
		}
		cout << "Case #" << casenum << ": ";
		cout << ans << endl;
	}
	return 0;
}
