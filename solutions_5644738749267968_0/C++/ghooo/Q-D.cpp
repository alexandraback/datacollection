/*
 * Q-D.cpp
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

int solve1(vector<double> p1, vector<double> p2){
	set<double> s;
	rep(i,sz(p2)) s.insert(p2[i]);
	sort(all(p1));

	int cnt = 0;
	rep(i,sz(p1)){
		set<double>::iterator it = s.lower_bound(p1[i]);
		if(it == s.end()) cnt++;
		else s.erase(it);
	}
	return cnt;
}
int solve2(vector<double> p1, vector<double> p2){
	set<double> s1, s2;
	rep(i,sz(p1)) s1.insert(p1[i]);
	rep(i,sz(p2)) s2.insert(p2[i]);
	double mx = *s1.rbegin();

	int cnt = 0;
	rep(i,sz(p1)){
		set<double>::iterator it2 = s2.lower_bound(mx);
		if(it2 == s2.end()){
			set<double>::iterator it1 = s1.lower_bound(*s2.begin());

			if(it1 != s1.end()){
				s1.erase(it1);
				cnt++;
			} else s1.erase(s1.begin());

			s2.erase(s2.begin());
		}
		else{
			s2.erase(it2);
			s1.erase(s1.begin());
		}
	}
	return cnt;
}
int main(){
	ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int t, n;
	double x;
	int casenum = 1;
	cin >> t;
	while(t--){
		cin >> n;
		vector<double> p1, p2;
		rep(i,n) cin >> x, p1.pb(x);
		rep(i,n) cin >> x, p2.pb(x);
		cout << "Case #" << casenum++ << ": ";
		cout << solve2(p1,p2) << " " << solve1(p1,p2) << endl;
	}

	return 0;
}
