/*
 * Q-C.cpp
 *
 *  Created on: Apr 12, 2014
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

char arr[11][11];
int t, m, r, c;
int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[] = {-1, 0, 1,  -1, 1, -1, 0, 1};
inline bool isZero(int ri, int ci){
	if(arr[ri][ci]) return false;
	int nr, nc;
	rep(k,8){
		nr = ri+dr[k]; nc = ci+dc[k];
		if(nr == r || nr < 0 || nc == c || nc < 0) continue;
		if(arr[nr][nc]) return false;
	}
	return true;
}
bool visited[11][11];
int dfs(int ri, int ci){
	if(visited[ri][ci]) return 0;
	visited[ri][ci] = true;
	if(isZero(ri,ci)){
		int nr, nc, ret = 1;
		rep(k,8){
			nr = ri+dr[k]; nc = ci+dc[k];
			if(nr == r || nr < 0 || nc == c || nc < 0) continue;
			ret += dfs(nr,nc);
		}
		return ret;

	}
	return 1;
}
bool test(){
	rep(ri,r) rep(ci,c){
		if(isZero(ri,ci)){
			reset(visited,0);
			bool ret = (r*c-m == dfs(ri,ci));
			if(ret) arr[ri][ci]=2;
			return ret;
		}
	}
	return false;
}
bool rec(int ri, int ci, int rem){
	if(rem == 0)
		return test();
	if(ri == r) return false;
	arr[ri][ci] = 1;
	if(ci == c-1){ if(rec(ri+1,0,rem-1)) return true;}
	else {if(rec(ri,ci+1,rem-1)) return true;}

	arr[ri][ci] = 0;
	if(ci == c-1) {if (rec(ri+1,0,rem)) return true;}
	else {if(rec(ri,ci+1,rem)) return true;}
	return false;
}
int main(){
	ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int casenum = 1;
	cin >> t;
	while(t--){
		cin >> r >> c >> m;

		cout << "Case #" << casenum++ << ": " << endl;
		reset(arr,0);
		if(m == r*c-1){
			reset(arr,1);
			arr[0][0]=2;
		} else if(!rec(0,0,m)){
			cout << "Impossible" << endl;
			continue;
		}
		rep(ri,r){
			rep(ci,c){
				if(arr[ri][ci]==1)cout<<"*";
				else if(arr[ri][ci]==0) cout << ".";
				else cout <<"c";
			}
			cout << endl;
		}
	}
	return 0;
}
