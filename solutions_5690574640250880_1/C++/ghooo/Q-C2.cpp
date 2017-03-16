/*
 * Q-C2.cpp
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
char arr[60][60];

int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[] = {-1, 0, 1,  -1, 1, -1, 0, 1};
inline bool isZero(int ri, int ci, int r, int c){
	if(arr[ri][ci] == '*') return false;
	int nr, nc;
	rep(k,8){
		nr = ri+dr[k]; nc = ci+dc[k];
		if(nr == r || nr < 0 || nc == c || nc < 0) continue;
		if(arr[nr][nc] == '*') return false;
	}
	return true;
}

bool visited[60][60];
int dfs(int ri, int ci, int r, int c){
	if(visited[ri][ci]) return 0;
	visited[ri][ci] = true;
	if(isZero(ri,ci,r,c)){
		int nr, nc, ret = 1;
		rep(k,8){
			nr = ri+dr[k]; nc = ci+dc[k];
			if(nr == r || nr < 0 || nc == c || nc < 0 || arr[nr][nc] == '*') continue;
			ret += dfs(nr,nc,r,c);
		}
		return ret;

	}
	return 1;
}
bool test(int r, int c, int req){
	if(!isZero(0,0,r,c) && req != 1) return false;
	reset(visited,0);
	return dfs(0,0,r,c) == req;
}
bool solve(int r, int c, int m){
	int original_m = m;
	int n = min(r-c, m/c);
	for(int i = r-1; i > r-1-n; i--)
		rep(k,c) arr[i][k] = '*';

	m-=c*n;
	if(m == 0) return true;
	int st = r-n-1;
	int curr_width = c-1;
	while(m > 1){
		int ic;
		for(ic = curr_width; ic >= 0 && m > 1; ic--, m--)
			arr[st][ic] = '*';

		int ir = st-1;
		for(ic = curr_width; ir >= 0 && m > 1; ir--,m--)
			arr[ir][ic] = '*';
		--st;
		--curr_width;
	}
	rep(i,r)
	rep(k,c){
		if(arr[i][k] == '.'){
			arr[i][k] = '*';
			if(test(r,c,r*c-original_m)) return true;
			arr[i][k] = '.';
		}

	}
	return false;
}
int main(){
	ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int casenum = 1;
	int r, c, m,t;
	cin >> t;
	while(t--){
		cin >> r >> c >> m;
		reset(arr,'.');
		cout << "Case #" << casenum++ << ": " << endl;

		if(m == r*c-1){
			reset(arr,'*');
			arr[0][0] = 'c';
			rep(i,r){
				rep(k,c) cout << arr[i][k];
				cout << endl;
			}
		} else if(r >= c) {
			if(!solve(r,c,m))cout << "Impossible" << endl;
			else {
				arr[0][0] = 'c';
				rep(i,r){
					rep(k,c) cout << arr[i][k];
					cout << endl;
				}
			}

		} else {
			if(!solve(c,r,m))cout << "Impossible" << endl;
			else {
				arr[0][0] = 'c';
				rep(i,r){
					rep(k,c) cout << arr[k][i];
					cout << endl;
				}
			}
		}
	}
	return 0;
}
