#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <cmath>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cassert>
using namespace std;

#define EPS 1e-12
#define ull unsigned long long
#define ll long long
#define VI vector<ll>
#define PII pair<ll, ll> 
#define VVI vector<vector<ll> >
#define REP(i,n) for(int i=0,_n=(n);(i)<(int)_n;++i)
#define RANGE(i,a,b) for(int i=(int)a,_b=(int)(b);(i)<_b;++i)
#define RANGE_R(i,a,b) for(int i=(int)b-1,_a=(int)(a);(i)>=_a;--i)
#define IN_RANGE(v, a, b) ((a)<=(v) && (v)<(b))
#define MIN_UPDATE(target, value) target = min(target, value)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
#define POPCOUNT __builtin_popcount
#define POPCOUNTLL __builtin_popcountll
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define PRINT1(table, D0) REP(d0, D0) cout<<table[d0]<<" "; cout<<"\n";
#define PRINT2(table, D0, D1) REP(d0, D0) { REP(d1, D1) cout<<table[d0][d1]<<" "; cout<<"\n"; }
#define PRINT3(table, D0, D1, D2) REP(d0, D0) { REP(d1, D1) { REP(d2, D2) cout<<table[d0][d1][d2]<<" "; cout<<"\n"; } cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v);
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
struct Point{
	int x, y;
	bool operator<(const Point& a) const {
		if(x==a.x) return y<a.y;
		return x<a.x;
	}
	bool operator==(const Point& a) const {
		return x==a.x && y==a.y;
	}
};
Point operator+(const Point&a, const Point& b) {return {a.x+b.x, a.y+b.y};}
Point operator-(const Point&a, const Point& b) {return {a.x-b.x, a.y-b.y};}
std::ostream& operator<<(std::ostream& os, const Point& v) { os << "("<<v.x<<" "<<v.y << ")"<<endl; return os; }

vector<vector<vector<Point>>> shapesN;
vector<vector<VI>> shapeSameN;

void printShape(vector<Point> sh) {
	int L = 7;
	vector<string> s(2*L, string(2*L, ' '));
	for(auto& p : sh) {
//		cout<<":: "<<p.x<<" "<<p.y<<endl;
		s[p.y+L][p.x+L] = '*';
	}
	cout<<s<<endl;
}


bool sameTranslate(const vector<Point>& a, const vector<Point>& b) {
	Point tr;
	REP(i, a.size()) {
		Point ltr = b[i]-a[i];
		if(i==0) {
			tr = ltr;
		} else {
			if(!(tr==ltr)) return false;
		}
	}
	return true;
}

bool same(const vector<Point>& a, const vector<Point>& b) {
	REP(r, 2) {
		vector<Point> neu(ALL(b));
		if(r) for(auto& p : neu) p.x*=-1;
		REP(i, 4) {
			for(auto& p : neu) {
				swap(p.x, p.y);
				p.y*=-1;
			}
			if(sameTranslate(a, neu)) return true;
		}
	}
	return false;
}


bool dup(vector<Point>& shape, vector<vector<Point>>& shapes) {
	for(auto& orig : shapes) {
		if(sameTranslate(shape, orig)) return true;
	}
	return false;
}

void init(int N) {
	if(N==1) {
		vector<Point> shape;
		shape.PB({0, 0});
		shapesN[0].PB(shape);
		shapeSameN[0] = vector<VI>(1);
		return;
	}
	init(N-1);
	vector<vector<Point>> ns;
	auto& shapes = shapesN[N-2];
	for(auto& orig : shapes) {
//		cout<<"For orig "<<orig<<endl;
		for(auto& p : orig) {
			REP(dir, 4) {
				Point np = {dx[dir]+p.x, dy[dir]+p.y};
				vector<Point> neu(orig);
				if(find(ALL(neu), np)==neu.end()) {
					neu.PB(np);
					sort(ALL(neu));
					if(!dup(neu, ns)) ns.PB(neu);
				}
//				cout<<"Add "<<neu<<endl;
			}
		}
	}
	// make same info
	shapeSameN[N-1] = vector<VI>(ns.size());
	REP(i, ns.size()) {
		REP(j, ns.size()) {
			if(same(ns[i], ns[j])) {
				shapeSameN[N-1][i].PB(j);
				shapeSameN[N-1][j].PB(i);
			}
		}
	}
	shapesN[N-1] = ns;
}

map<pair<int, pair<int, int>>, bool> ansMemo;
void initAnsMemo() {
ansMemo[MP(1, MP(1, 1))] = false;
ansMemo[MP(1, MP(2, 1))] = false;
ansMemo[MP(1, MP(2, 2))] = false;
ansMemo[MP(1, MP(3, 1))] = false;
ansMemo[MP(1, MP(3, 2))] = false;
ansMemo[MP(1, MP(3, 3))] = false;
ansMemo[MP(1, MP(4, 1))] = false;
ansMemo[MP(1, MP(4, 2))] = false;
ansMemo[MP(1, MP(4, 3))] = false;
ansMemo[MP(1, MP(4, 4))] = false;
ansMemo[MP(1, MP(5, 1))] = false;
ansMemo[MP(1, MP(5, 2))] = false;
ansMemo[MP(1, MP(5, 3))] = false;
ansMemo[MP(1, MP(5, 4))] = false;
ansMemo[MP(1, MP(5, 5))] = false;
ansMemo[MP(1, MP(6, 1))] = false;
ansMemo[MP(1, MP(6, 2))] = false;
ansMemo[MP(1, MP(6, 3))] = false;
ansMemo[MP(1, MP(6, 4))] = false;
ansMemo[MP(1, MP(6, 5))] = false;
ansMemo[MP(1, MP(6, 6))] = false;
ansMemo[MP(1, MP(7, 1))] = false;
ansMemo[MP(1, MP(7, 2))] = false;
ansMemo[MP(1, MP(7, 3))] = false;
ansMemo[MP(1, MP(7, 4))] = false;
ansMemo[MP(1, MP(7, 5))] = false;
ansMemo[MP(1, MP(7, 6))] = false;
ansMemo[MP(1, MP(7, 7))] = false;
ansMemo[MP(1, MP(8, 1))] = false;
ansMemo[MP(1, MP(8, 2))] = false;
ansMemo[MP(1, MP(8, 3))] = false;
ansMemo[MP(1, MP(8, 4))] = false;
ansMemo[MP(1, MP(8, 5))] = false;
ansMemo[MP(1, MP(8, 6))] = false;
ansMemo[MP(1, MP(8, 7))] = false;
ansMemo[MP(1, MP(8, 8))] = false;
ansMemo[MP(1, MP(9, 1))] = false;
ansMemo[MP(1, MP(9, 2))] = false;
ansMemo[MP(1, MP(9, 3))] = false;
ansMemo[MP(1, MP(9, 4))] = false;
ansMemo[MP(1, MP(9, 5))] = false;
ansMemo[MP(1, MP(9, 6))] = false;
ansMemo[MP(1, MP(9, 7))] = false;
ansMemo[MP(1, MP(9, 8))] = false;
ansMemo[MP(1, MP(9, 9))] = false;
ansMemo[MP(1, MP(10, 1))] = false;
ansMemo[MP(1, MP(10, 2))] = false;
ansMemo[MP(1, MP(10, 3))] = false;
ansMemo[MP(1, MP(10, 4))] = false;
ansMemo[MP(1, MP(10, 5))] = false;
ansMemo[MP(1, MP(10, 6))] = false;
ansMemo[MP(1, MP(10, 7))] = false;
ansMemo[MP(1, MP(10, 8))] = false;
ansMemo[MP(1, MP(10, 9))] = false;
ansMemo[MP(1, MP(10, 10))] = false;
ansMemo[MP(1, MP(11, 1))] = false;
ansMemo[MP(1, MP(11, 2))] = false;
ansMemo[MP(1, MP(11, 3))] = false;
ansMemo[MP(1, MP(11, 4))] = false;
ansMemo[MP(1, MP(11, 5))] = false;
ansMemo[MP(1, MP(11, 6))] = false;
ansMemo[MP(1, MP(11, 7))] = false;
ansMemo[MP(1, MP(11, 8))] = false;
ansMemo[MP(1, MP(11, 9))] = false;
ansMemo[MP(1, MP(11, 10))] = false;
ansMemo[MP(1, MP(11, 11))] = false;
ansMemo[MP(1, MP(12, 1))] = false;
ansMemo[MP(1, MP(12, 2))] = false;
ansMemo[MP(1, MP(12, 3))] = false;
ansMemo[MP(1, MP(12, 4))] = false;
ansMemo[MP(1, MP(12, 5))] = false;
ansMemo[MP(1, MP(12, 6))] = false;
ansMemo[MP(1, MP(12, 7))] = false;
ansMemo[MP(1, MP(12, 8))] = false;
ansMemo[MP(1, MP(12, 9))] = false;
ansMemo[MP(1, MP(12, 10))] = false;
ansMemo[MP(1, MP(12, 11))] = false;
ansMemo[MP(1, MP(12, 12))] = false;
ansMemo[MP(1, MP(13, 1))] = false;
ansMemo[MP(1, MP(13, 2))] = false;
ansMemo[MP(1, MP(13, 3))] = false;
ansMemo[MP(1, MP(13, 4))] = false;
ansMemo[MP(1, MP(13, 5))] = false;
ansMemo[MP(1, MP(13, 6))] = false;
ansMemo[MP(1, MP(13, 7))] = false;
ansMemo[MP(1, MP(13, 8))] = false;
ansMemo[MP(1, MP(13, 9))] = false;
ansMemo[MP(1, MP(13, 10))] = false;
ansMemo[MP(1, MP(13, 11))] = false;
ansMemo[MP(1, MP(13, 12))] = false;
ansMemo[MP(1, MP(13, 13))] = false;
ansMemo[MP(1, MP(14, 1))] = false;
ansMemo[MP(1, MP(14, 2))] = false;
ansMemo[MP(1, MP(14, 3))] = false;
ansMemo[MP(1, MP(14, 4))] = false;
ansMemo[MP(1, MP(14, 5))] = false;
ansMemo[MP(1, MP(14, 6))] = false;
ansMemo[MP(1, MP(14, 7))] = false;
ansMemo[MP(1, MP(14, 8))] = false;
ansMemo[MP(1, MP(14, 9))] = false;
ansMemo[MP(1, MP(14, 10))] = false;
ansMemo[MP(1, MP(14, 11))] = false;
ansMemo[MP(1, MP(14, 12))] = false;
ansMemo[MP(1, MP(14, 13))] = false;
ansMemo[MP(1, MP(14, 14))] = false;
ansMemo[MP(1, MP(15, 1))] = false;
ansMemo[MP(1, MP(15, 2))] = false;
ansMemo[MP(1, MP(15, 3))] = false;
ansMemo[MP(1, MP(15, 4))] = false;
ansMemo[MP(1, MP(15, 5))] = false;
ansMemo[MP(1, MP(15, 6))] = false;
ansMemo[MP(1, MP(15, 7))] = false;
ansMemo[MP(1, MP(15, 8))] = false;
ansMemo[MP(1, MP(15, 9))] = false;
ansMemo[MP(1, MP(15, 10))] = false;
ansMemo[MP(1, MP(15, 11))] = false;
ansMemo[MP(1, MP(15, 12))] = false;
ansMemo[MP(1, MP(15, 13))] = false;
ansMemo[MP(1, MP(15, 14))] = false;
ansMemo[MP(1, MP(15, 15))] = false;
ansMemo[MP(1, MP(16, 1))] = false;
ansMemo[MP(1, MP(16, 2))] = false;
ansMemo[MP(1, MP(16, 3))] = false;
ansMemo[MP(1, MP(16, 4))] = false;
ansMemo[MP(1, MP(16, 5))] = false;
ansMemo[MP(1, MP(16, 6))] = false;
ansMemo[MP(1, MP(16, 7))] = false;
ansMemo[MP(1, MP(16, 8))] = false;
ansMemo[MP(1, MP(16, 9))] = false;
ansMemo[MP(1, MP(16, 10))] = false;
ansMemo[MP(1, MP(16, 11))] = false;
ansMemo[MP(1, MP(16, 12))] = false;
ansMemo[MP(1, MP(16, 13))] = false;
ansMemo[MP(1, MP(16, 14))] = false;
ansMemo[MP(1, MP(16, 15))] = false;
ansMemo[MP(1, MP(16, 16))] = false;
ansMemo[MP(1, MP(17, 1))] = false;
ansMemo[MP(1, MP(17, 2))] = false;
ansMemo[MP(1, MP(17, 3))] = false;
ansMemo[MP(1, MP(17, 4))] = false;
ansMemo[MP(1, MP(17, 5))] = false;
ansMemo[MP(1, MP(17, 6))] = false;
ansMemo[MP(1, MP(17, 7))] = false;
ansMemo[MP(1, MP(17, 8))] = false;
ansMemo[MP(1, MP(17, 9))] = false;
ansMemo[MP(1, MP(17, 10))] = false;
ansMemo[MP(1, MP(17, 11))] = false;
ansMemo[MP(1, MP(17, 12))] = false;
ansMemo[MP(1, MP(17, 13))] = false;
ansMemo[MP(1, MP(17, 14))] = false;
ansMemo[MP(1, MP(17, 15))] = false;
ansMemo[MP(1, MP(17, 16))] = false;
ansMemo[MP(1, MP(17, 17))] = false;
ansMemo[MP(1, MP(18, 1))] = false;
ansMemo[MP(1, MP(18, 2))] = false;
ansMemo[MP(1, MP(18, 3))] = false;
ansMemo[MP(1, MP(18, 4))] = false;
ansMemo[MP(1, MP(18, 5))] = false;
ansMemo[MP(1, MP(18, 6))] = false;
ansMemo[MP(1, MP(18, 7))] = false;
ansMemo[MP(1, MP(18, 8))] = false;
ansMemo[MP(1, MP(18, 9))] = false;
ansMemo[MP(1, MP(18, 10))] = false;
ansMemo[MP(1, MP(18, 11))] = false;
ansMemo[MP(1, MP(18, 12))] = false;
ansMemo[MP(1, MP(18, 13))] = false;
ansMemo[MP(1, MP(18, 14))] = false;
ansMemo[MP(1, MP(18, 15))] = false;
ansMemo[MP(1, MP(18, 16))] = false;
ansMemo[MP(1, MP(18, 17))] = false;
ansMemo[MP(1, MP(18, 18))] = false;
ansMemo[MP(1, MP(19, 1))] = false;
ansMemo[MP(1, MP(19, 2))] = false;
ansMemo[MP(1, MP(19, 3))] = false;
ansMemo[MP(1, MP(19, 4))] = false;
ansMemo[MP(1, MP(19, 5))] = false;
ansMemo[MP(1, MP(19, 6))] = false;
ansMemo[MP(1, MP(19, 7))] = false;
ansMemo[MP(1, MP(19, 8))] = false;
ansMemo[MP(1, MP(19, 9))] = false;
ansMemo[MP(1, MP(19, 10))] = false;
ansMemo[MP(1, MP(19, 11))] = false;
ansMemo[MP(1, MP(19, 12))] = false;
ansMemo[MP(1, MP(19, 13))] = false;
ansMemo[MP(1, MP(19, 14))] = false;
ansMemo[MP(1, MP(19, 15))] = false;
ansMemo[MP(1, MP(19, 16))] = false;
ansMemo[MP(1, MP(19, 17))] = false;
ansMemo[MP(1, MP(19, 18))] = false;
ansMemo[MP(1, MP(19, 19))] = false;
ansMemo[MP(2, MP(2, 1))] = false;
ansMemo[MP(2, MP(2, 2))] = false;
ansMemo[MP(2, MP(3, 2))] = false;
ansMemo[MP(2, MP(4, 1))] = false;
ansMemo[MP(2, MP(4, 2))] = false;
ansMemo[MP(2, MP(4, 3))] = false;
ansMemo[MP(2, MP(4, 4))] = false;
ansMemo[MP(2, MP(5, 2))] = false;
ansMemo[MP(2, MP(5, 4))] = false;
ansMemo[MP(2, MP(6, 1))] = false;
ansMemo[MP(2, MP(6, 2))] = false;
ansMemo[MP(2, MP(6, 3))] = false;
ansMemo[MP(2, MP(6, 4))] = false;
ansMemo[MP(2, MP(6, 5))] = false;
ansMemo[MP(2, MP(6, 6))] = false;
ansMemo[MP(2, MP(7, 2))] = false;
ansMemo[MP(2, MP(7, 4))] = false;
ansMemo[MP(2, MP(7, 6))] = false;
ansMemo[MP(2, MP(8, 1))] = false;
ansMemo[MP(2, MP(8, 2))] = false;
ansMemo[MP(2, MP(8, 3))] = false;
ansMemo[MP(2, MP(8, 4))] = false;
ansMemo[MP(2, MP(8, 5))] = false;
ansMemo[MP(2, MP(8, 6))] = false;
ansMemo[MP(2, MP(8, 7))] = false;
ansMemo[MP(2, MP(8, 8))] = false;
ansMemo[MP(2, MP(9, 2))] = false;
ansMemo[MP(2, MP(9, 4))] = false;
ansMemo[MP(2, MP(9, 6))] = false;
ansMemo[MP(2, MP(9, 8))] = false;
ansMemo[MP(2, MP(10, 1))] = false;
ansMemo[MP(2, MP(10, 2))] = false;
ansMemo[MP(2, MP(10, 3))] = false;
ansMemo[MP(2, MP(10, 4))] = false;
ansMemo[MP(2, MP(10, 5))] = false;
ansMemo[MP(2, MP(10, 6))] = false;
ansMemo[MP(2, MP(10, 7))] = false;
ansMemo[MP(2, MP(10, 8))] = false;
ansMemo[MP(2, MP(10, 9))] = false;
ansMemo[MP(2, MP(10, 10))] = false;
ansMemo[MP(2, MP(11, 2))] = false;
ansMemo[MP(2, MP(11, 4))] = false;
ansMemo[MP(2, MP(11, 6))] = false;
ansMemo[MP(2, MP(11, 8))] = false;
ansMemo[MP(2, MP(11, 10))] = false;
ansMemo[MP(2, MP(12, 1))] = false;
ansMemo[MP(2, MP(12, 2))] = false;
ansMemo[MP(2, MP(12, 3))] = false;
ansMemo[MP(2, MP(12, 4))] = false;
ansMemo[MP(2, MP(12, 5))] = false;
ansMemo[MP(2, MP(12, 6))] = false;
ansMemo[MP(2, MP(12, 7))] = false;
ansMemo[MP(2, MP(12, 8))] = false;
ansMemo[MP(2, MP(12, 9))] = false;
ansMemo[MP(2, MP(12, 10))] = false;
ansMemo[MP(2, MP(12, 11))] = false;
ansMemo[MP(2, MP(12, 12))] = false;
ansMemo[MP(2, MP(13, 2))] = false;
ansMemo[MP(2, MP(13, 4))] = false;
ansMemo[MP(2, MP(13, 6))] = false;
ansMemo[MP(2, MP(13, 8))] = false;
ansMemo[MP(2, MP(13, 10))] = false;
ansMemo[MP(2, MP(13, 12))] = false;
ansMemo[MP(2, MP(14, 1))] = false;
ansMemo[MP(2, MP(14, 2))] = false;
ansMemo[MP(2, MP(14, 3))] = false;
ansMemo[MP(2, MP(14, 4))] = false;
ansMemo[MP(2, MP(14, 5))] = false;
ansMemo[MP(2, MP(14, 6))] = false;
ansMemo[MP(2, MP(14, 7))] = false;
ansMemo[MP(2, MP(14, 8))] = false;
ansMemo[MP(2, MP(14, 9))] = false;
ansMemo[MP(2, MP(14, 10))] = false;
ansMemo[MP(2, MP(14, 11))] = false;
ansMemo[MP(2, MP(14, 12))] = false;
ansMemo[MP(2, MP(14, 13))] = false;
ansMemo[MP(2, MP(14, 14))] = false;
ansMemo[MP(2, MP(15, 2))] = false;
ansMemo[MP(2, MP(15, 4))] = false;
ansMemo[MP(2, MP(15, 6))] = false;
ansMemo[MP(2, MP(15, 8))] = false;
ansMemo[MP(2, MP(15, 10))] = false;
ansMemo[MP(2, MP(15, 12))] = false;
ansMemo[MP(2, MP(15, 14))] = false;
ansMemo[MP(2, MP(16, 1))] = false;
ansMemo[MP(2, MP(16, 2))] = false;
ansMemo[MP(2, MP(16, 3))] = false;
ansMemo[MP(2, MP(16, 4))] = false;
ansMemo[MP(2, MP(16, 5))] = false;
ansMemo[MP(2, MP(16, 6))] = false;
ansMemo[MP(2, MP(16, 7))] = false;
ansMemo[MP(2, MP(16, 8))] = false;
ansMemo[MP(2, MP(16, 9))] = false;
ansMemo[MP(2, MP(16, 10))] = false;
ansMemo[MP(2, MP(16, 11))] = false;
ansMemo[MP(2, MP(16, 12))] = false;
ansMemo[MP(2, MP(16, 13))] = false;
ansMemo[MP(2, MP(16, 14))] = false;
ansMemo[MP(2, MP(16, 15))] = false;
ansMemo[MP(2, MP(16, 16))] = false;
ansMemo[MP(2, MP(17, 2))] = false;
ansMemo[MP(2, MP(17, 4))] = false;
ansMemo[MP(2, MP(17, 6))] = false;
ansMemo[MP(2, MP(17, 8))] = false;
ansMemo[MP(2, MP(17, 10))] = false;
ansMemo[MP(2, MP(17, 12))] = false;
ansMemo[MP(2, MP(17, 14))] = false;
ansMemo[MP(2, MP(17, 16))] = false;
ansMemo[MP(2, MP(18, 1))] = false;
ansMemo[MP(2, MP(18, 2))] = false;
ansMemo[MP(2, MP(18, 3))] = false;
ansMemo[MP(2, MP(18, 4))] = false;
ansMemo[MP(2, MP(18, 5))] = false;
ansMemo[MP(2, MP(18, 6))] = false;
ansMemo[MP(2, MP(18, 7))] = false;
ansMemo[MP(2, MP(18, 8))] = false;
ansMemo[MP(2, MP(18, 9))] = false;
ansMemo[MP(2, MP(18, 10))] = false;
ansMemo[MP(2, MP(18, 11))] = false;
ansMemo[MP(2, MP(18, 12))] = false;
ansMemo[MP(2, MP(18, 13))] = false;
ansMemo[MP(2, MP(18, 14))] = false;
ansMemo[MP(2, MP(18, 15))] = false;
ansMemo[MP(2, MP(18, 16))] = false;
ansMemo[MP(2, MP(18, 17))] = false;
ansMemo[MP(2, MP(18, 18))] = false;
ansMemo[MP(2, MP(19, 2))] = false;
ansMemo[MP(2, MP(19, 4))] = false;
ansMemo[MP(2, MP(19, 6))] = false;
ansMemo[MP(2, MP(19, 8))] = false;
ansMemo[MP(2, MP(19, 10))] = false;
ansMemo[MP(2, MP(19, 12))] = false;
ansMemo[MP(2, MP(19, 14))] = false;
ansMemo[MP(2, MP(19, 16))] = false;
ansMemo[MP(2, MP(19, 18))] = false;
ansMemo[MP(3, MP(3, 1))] = true;
ansMemo[MP(3, MP(3, 2))] = false;
ansMemo[MP(3, MP(3, 3))] = false;
ansMemo[MP(3, MP(4, 3))] = false;
ansMemo[MP(3, MP(5, 3))] = false;
ansMemo[MP(3, MP(6, 1))] = true;
ansMemo[MP(3, MP(6, 2))] = false;
ansMemo[MP(3, MP(6, 3))] = false;
ansMemo[MP(3, MP(6, 4))] = false;
ansMemo[MP(3, MP(6, 5))] = false;
ansMemo[MP(3, MP(6, 6))] = false;
ansMemo[MP(3, MP(7, 3))] = false;
ansMemo[MP(3, MP(7, 6))] = false;
ansMemo[MP(3, MP(8, 3))] = false;
ansMemo[MP(3, MP(8, 6))] = false;
ansMemo[MP(3, MP(9, 1))] = true;
ansMemo[MP(3, MP(9, 2))] = false;
ansMemo[MP(3, MP(9, 3))] = false;
ansMemo[MP(3, MP(9, 4))] = false;
ansMemo[MP(3, MP(9, 5))] = false;
ansMemo[MP(3, MP(9, 6))] = false;
ansMemo[MP(3, MP(9, 7))] = false;
ansMemo[MP(3, MP(9, 8))] = false;
ansMemo[MP(3, MP(9, 9))] = false;
ansMemo[MP(3, MP(10, 3))] = false;
ansMemo[MP(3, MP(10, 6))] = false;
ansMemo[MP(3, MP(10, 9))] = false;
ansMemo[MP(3, MP(11, 3))] = false;
ansMemo[MP(3, MP(11, 6))] = false;
ansMemo[MP(3, MP(11, 9))] = false;
ansMemo[MP(3, MP(12, 1))] = true;
ansMemo[MP(3, MP(12, 2))] = false;
ansMemo[MP(3, MP(12, 3))] = false;
ansMemo[MP(3, MP(12, 4))] = false;
ansMemo[MP(3, MP(12, 5))] = false;
ansMemo[MP(3, MP(12, 6))] = false;
ansMemo[MP(3, MP(12, 7))] = false;
ansMemo[MP(3, MP(12, 8))] = false;
ansMemo[MP(3, MP(12, 9))] = false;
ansMemo[MP(3, MP(12, 10))] = false;
ansMemo[MP(3, MP(12, 11))] = false;
ansMemo[MP(3, MP(12, 12))] = false;
ansMemo[MP(3, MP(13, 3))] = false;
ansMemo[MP(3, MP(13, 6))] = false;
ansMemo[MP(3, MP(13, 9))] = false;
ansMemo[MP(3, MP(13, 12))] = false;
ansMemo[MP(3, MP(14, 3))] = false;
ansMemo[MP(3, MP(14, 6))] = false;
ansMemo[MP(3, MP(14, 9))] = false;
ansMemo[MP(3, MP(14, 12))] = false;
ansMemo[MP(3, MP(15, 1))] = true;
ansMemo[MP(3, MP(15, 2))] = false;
ansMemo[MP(3, MP(15, 3))] = false;
ansMemo[MP(3, MP(15, 4))] = false;
ansMemo[MP(3, MP(15, 5))] = false;
ansMemo[MP(3, MP(15, 6))] = false;
ansMemo[MP(3, MP(15, 7))] = false;
ansMemo[MP(3, MP(15, 8))] = false;
ansMemo[MP(3, MP(15, 9))] = false;
ansMemo[MP(3, MP(15, 10))] = false;
ansMemo[MP(3, MP(15, 11))] = false;
ansMemo[MP(3, MP(15, 12))] = false;
ansMemo[MP(3, MP(15, 13))] = false;
ansMemo[MP(3, MP(15, 14))] = false;
ansMemo[MP(3, MP(15, 15))] = false;
ansMemo[MP(3, MP(16, 3))] = false;
ansMemo[MP(3, MP(16, 6))] = false;
ansMemo[MP(3, MP(16, 9))] = false;
ansMemo[MP(3, MP(16, 12))] = false;
ansMemo[MP(3, MP(16, 15))] = false;
ansMemo[MP(3, MP(17, 3))] = false;
ansMemo[MP(3, MP(17, 6))] = false;
ansMemo[MP(3, MP(17, 9))] = false;
ansMemo[MP(3, MP(17, 12))] = false;
ansMemo[MP(3, MP(17, 15))] = false;
ansMemo[MP(3, MP(18, 1))] = true;
ansMemo[MP(3, MP(18, 2))] = false;
ansMemo[MP(3, MP(18, 3))] = false;
ansMemo[MP(3, MP(18, 4))] = false;
ansMemo[MP(3, MP(18, 5))] = false;
ansMemo[MP(3, MP(18, 6))] = false;
ansMemo[MP(3, MP(18, 7))] = false;
ansMemo[MP(3, MP(18, 8))] = false;
ansMemo[MP(3, MP(18, 9))] = false;
ansMemo[MP(3, MP(18, 10))] = false;
ansMemo[MP(3, MP(18, 11))] = false;
ansMemo[MP(3, MP(18, 12))] = false;
ansMemo[MP(3, MP(18, 13))] = false;
ansMemo[MP(3, MP(18, 14))] = false;
ansMemo[MP(3, MP(18, 15))] = false;
ansMemo[MP(3, MP(18, 16))] = false;
ansMemo[MP(3, MP(18, 17))] = false;
ansMemo[MP(3, MP(18, 18))] = false;
ansMemo[MP(3, MP(19, 3))] = false;
ansMemo[MP(3, MP(19, 6))] = false;
ansMemo[MP(3, MP(19, 9))] = false;
ansMemo[MP(3, MP(19, 12))] = false;
ansMemo[MP(3, MP(19, 15))] = false;
ansMemo[MP(3, MP(19, 18))] = false;
ansMemo[MP(4, MP(2, 2))] = true;
ansMemo[MP(4, MP(4, 1))] = true;
ansMemo[MP(4, MP(4, 2))] = true;
ansMemo[MP(4, MP(4, 3))] = false;
ansMemo[MP(4, MP(4, 4))] = false;
ansMemo[MP(4, MP(5, 4))] = false;
ansMemo[MP(4, MP(6, 2))] = true;
ansMemo[MP(4, MP(6, 4))] = false;
ansMemo[MP(4, MP(6, 6))] = false;
ansMemo[MP(4, MP(7, 4))] = false;
ansMemo[MP(4, MP(8, 1))] = true;
ansMemo[MP(4, MP(8, 2))] = true;
ansMemo[MP(4, MP(8, 3))] = false;
ansMemo[MP(4, MP(8, 4))] = false;
ansMemo[MP(4, MP(8, 5))] = false;
ansMemo[MP(4, MP(8, 6))] = false;
ansMemo[MP(4, MP(8, 7))] = false;
ansMemo[MP(4, MP(8, 8))] = false;
ansMemo[MP(4, MP(9, 4))] = false;
ansMemo[MP(4, MP(9, 8))] = false;
ansMemo[MP(4, MP(10, 2))] = true;
ansMemo[MP(4, MP(10, 4))] = false;
ansMemo[MP(4, MP(10, 6))] = false;
ansMemo[MP(4, MP(10, 8))] = false;
ansMemo[MP(4, MP(10, 10))] = false;
ansMemo[MP(4, MP(11, 4))] = false;
ansMemo[MP(4, MP(11, 8))] = false;
ansMemo[MP(4, MP(12, 1))] = true;
ansMemo[MP(4, MP(12, 2))] = true;
ansMemo[MP(4, MP(12, 3))] = false;
ansMemo[MP(4, MP(12, 4))] = false;
ansMemo[MP(4, MP(12, 5))] = false;
ansMemo[MP(4, MP(12, 6))] = false;
ansMemo[MP(4, MP(12, 7))] = false;
ansMemo[MP(4, MP(12, 8))] = false;
ansMemo[MP(4, MP(12, 9))] = false;
ansMemo[MP(4, MP(12, 10))] = false;
ansMemo[MP(4, MP(12, 11))] = false;
ansMemo[MP(4, MP(12, 12))] = false;
ansMemo[MP(4, MP(13, 4))] = false;
ansMemo[MP(4, MP(13, 8))] = false;
ansMemo[MP(4, MP(13, 12))] = false;
ansMemo[MP(4, MP(14, 2))] = true;
ansMemo[MP(4, MP(14, 4))] = false;
ansMemo[MP(4, MP(14, 6))] = false;
ansMemo[MP(4, MP(14, 8))] = false;
ansMemo[MP(4, MP(14, 10))] = false;
ansMemo[MP(4, MP(14, 12))] = false;
ansMemo[MP(4, MP(14, 14))] = false;
ansMemo[MP(4, MP(15, 4))] = false;
ansMemo[MP(4, MP(15, 8))] = false;
ansMemo[MP(4, MP(15, 12))] = false;
ansMemo[MP(4, MP(16, 1))] = true;
ansMemo[MP(4, MP(16, 2))] = true;
ansMemo[MP(4, MP(16, 3))] = false;
ansMemo[MP(4, MP(16, 4))] = false;
ansMemo[MP(4, MP(16, 5))] = false;
ansMemo[MP(4, MP(16, 6))] = false;
ansMemo[MP(4, MP(16, 7))] = false;
ansMemo[MP(4, MP(16, 8))] = false;
ansMemo[MP(4, MP(16, 9))] = false;
ansMemo[MP(4, MP(16, 10))] = false;
ansMemo[MP(4, MP(16, 11))] = false;
ansMemo[MP(4, MP(16, 12))] = false;
ansMemo[MP(4, MP(16, 13))] = false;
ansMemo[MP(4, MP(16, 14))] = false;
ansMemo[MP(4, MP(16, 15))] = false;
ansMemo[MP(4, MP(16, 16))] = false;
ansMemo[MP(4, MP(17, 4))] = false;
ansMemo[MP(4, MP(17, 8))] = false;
ansMemo[MP(4, MP(17, 12))] = false;
ansMemo[MP(4, MP(17, 16))] = false;
ansMemo[MP(4, MP(18, 2))] = true;
ansMemo[MP(4, MP(18, 4))] = false;
ansMemo[MP(4, MP(18, 6))] = false;
ansMemo[MP(4, MP(18, 8))] = false;
ansMemo[MP(4, MP(18, 10))] = false;
ansMemo[MP(4, MP(18, 12))] = false;
ansMemo[MP(4, MP(18, 14))] = false;
ansMemo[MP(4, MP(18, 16))] = false;
ansMemo[MP(4, MP(18, 18))] = false;
ansMemo[MP(4, MP(19, 4))] = false;
ansMemo[MP(4, MP(19, 8))] = false;
ansMemo[MP(4, MP(19, 12))] = false;
ansMemo[MP(4, MP(19, 16))] = false;
ansMemo[MP(5, MP(5, 1))] = true;
ansMemo[MP(5, MP(5, 2))] = true;
ansMemo[MP(5, MP(5, 3))] = true;
ansMemo[MP(5, MP(5, 4))] = false;
ansMemo[MP(5, MP(5, 5))] = false;
ansMemo[MP(5, MP(6, 5))] = false;
ansMemo[MP(5, MP(7, 5))] = false;
ansMemo[MP(5, MP(8, 5))] = false;
ansMemo[MP(5, MP(9, 5))] = false;
ansMemo[MP(5, MP(10, 1))] = true;
ansMemo[MP(5, MP(10, 2))] = true;
ansMemo[MP(5, MP(10, 3))] = true;
ansMemo[MP(5, MP(10, 4))] = false;
ansMemo[MP(5, MP(10, 5))] = false;
ansMemo[MP(5, MP(10, 6))] = false;
ansMemo[MP(5, MP(10, 7))] = false;
ansMemo[MP(5, MP(10, 8))] = false;
ansMemo[MP(5, MP(10, 9))] = false;
ansMemo[MP(5, MP(10, 10))] = false;
ansMemo[MP(5, MP(11, 5))] = false;
ansMemo[MP(5, MP(11, 10))] = false;
ansMemo[MP(5, MP(12, 5))] = false;
ansMemo[MP(5, MP(12, 10))] = false;
ansMemo[MP(5, MP(13, 5))] = false;
ansMemo[MP(5, MP(13, 10))] = false;
ansMemo[MP(5, MP(14, 5))] = false;
ansMemo[MP(5, MP(14, 10))] = false;
ansMemo[MP(5, MP(15, 1))] = true;
ansMemo[MP(5, MP(15, 2))] = true;
ansMemo[MP(5, MP(15, 3))] = true;
ansMemo[MP(5, MP(15, 4))] = false;
ansMemo[MP(5, MP(15, 5))] = false;
ansMemo[MP(5, MP(15, 6))] = false;
ansMemo[MP(5, MP(15, 7))] = false;
ansMemo[MP(5, MP(15, 8))] = false;
ansMemo[MP(5, MP(15, 9))] = false;
ansMemo[MP(5, MP(15, 10))] = false;
ansMemo[MP(5, MP(15, 11))] = false;
ansMemo[MP(5, MP(15, 12))] = false;
ansMemo[MP(5, MP(15, 13))] = false;
ansMemo[MP(5, MP(15, 14))] = false;
ansMemo[MP(5, MP(15, 15))] = false;
ansMemo[MP(5, MP(16, 5))] = false;
ansMemo[MP(5, MP(16, 10))] = false;
ansMemo[MP(5, MP(16, 15))] = false;
ansMemo[MP(5, MP(17, 5))] = false;
ansMemo[MP(5, MP(17, 10))] = false;
ansMemo[MP(5, MP(17, 15))] = false;
ansMemo[MP(5, MP(18, 5))] = false;
ansMemo[MP(5, MP(18, 10))] = false;
ansMemo[MP(5, MP(18, 15))] = false;
ansMemo[MP(5, MP(19, 5))] = false;
ansMemo[MP(5, MP(19, 10))] = false;
ansMemo[MP(5, MP(19, 15))] = false;
ansMemo[MP(6, MP(3, 2))] = true;
ansMemo[MP(6, MP(4, 3))] = true;
ansMemo[MP(6, MP(6, 1))] = true;
ansMemo[MP(6, MP(6, 2))] = true;
ansMemo[MP(6, MP(6, 3))] = true;
ansMemo[MP(6, MP(6, 4))] = true;
ansMemo[MP(6, MP(6, 5))] = false;
ansMemo[MP(6, MP(6, 6))] = false;
ansMemo[MP(6, MP(7, 6))] = false;
ansMemo[MP(6, MP(8, 3))] = true;
ansMemo[MP(6, MP(8, 6))] = false;
ansMemo[MP(6, MP(9, 2))] = true;
ansMemo[MP(6, MP(9, 4))] = true;
ansMemo[MP(6, MP(9, 6))] = false;
ansMemo[MP(6, MP(9, 8))] = false;
ansMemo[MP(6, MP(10, 3))] = true;
ansMemo[MP(6, MP(10, 6))] = false;
ansMemo[MP(6, MP(10, 9))] = false;
ansMemo[MP(6, MP(11, 6))] = false;
ansMemo[MP(6, MP(12, 1))] = true;
ansMemo[MP(6, MP(12, 2))] = true;
ansMemo[MP(6, MP(12, 3))] = true;
ansMemo[MP(6, MP(12, 4))] = true;
ansMemo[MP(6, MP(12, 5))] = false;
ansMemo[MP(6, MP(12, 6))] = false;
ansMemo[MP(6, MP(12, 7))] = false;
ansMemo[MP(6, MP(12, 8))] = false;
ansMemo[MP(6, MP(12, 9))] = false;
ansMemo[MP(6, MP(12, 10))] = false;
ansMemo[MP(6, MP(12, 11))] = false;
ansMemo[MP(6, MP(12, 12))] = false;
ansMemo[MP(6, MP(13, 6))] = false;
ansMemo[MP(6, MP(13, 12))] = false;
ansMemo[MP(6, MP(14, 3))] = true;
ansMemo[MP(6, MP(14, 6))] = false;
ansMemo[MP(6, MP(14, 9))] = false;
ansMemo[MP(6, MP(14, 12))] = false;
ansMemo[MP(6, MP(15, 2))] = true;
ansMemo[MP(6, MP(15, 4))] = true;
ansMemo[MP(6, MP(16, 3))] = true;
ansMemo[MP(6, MP(18, 3))] = true;
ansMemo[MP(6, MP(18, 4))] = true;
}

ll X,R,C;
VI used;
VI usedToFill;
vector<vector<bool>> m;
int nPuts;
int level;
set<vector<vector<bool>>> memo;
VI memoCount;

void show() {
	REP(y, R){
		REP(x,C) {
			cout<<(m[y][x]?'*':'_');
		}
		cout<<endl;
	}
	cout<<endl;
}

vector<vector<bool>> vis;
int paintConnected(int x, int y) {
	int v=1;
	vis[y][x]=true;
	REP(dir, 4) {
		int nx = x+dx[dir];
		int ny = y+dy[dir];
		if(IN_RANGE(nx, 0, C) && IN_RANGE(ny, 0, R) && !m[ny][nx] && !vis[ny][nx]) {
			v+=paintConnected(nx, ny);
		}
	}
	return v;
}

bool validRest() {
//	return true;
	vis = vector<vector<bool>>(R, vector<bool>(C));
	REP(y, R) REP(x, C) if(!m[y][x] && !vis[y][x]) {
		int n = paintConnected(x, y);
		if(n%X) return false;
	}
	return true;
}

bool canPutAll;

bool dfs() {
//	cout<<"DFS"<<endl;
	if(canPutAll) return true;
	auto& shapes = shapesN[X-1];
	if(nPuts==R*C) {
		REP(i, used.size()) if(used[i]) {
			usedToFill[i] = 1;
			for(auto adj : shapeSameN[X-1][i]) usedToFill[adj] = 1;
		}
		if(*min_element(ALL(usedToFill))==1) canPutAll = true;
		return true;
	}
	int rest = R*C-nPuts;
	bool pruneCheck = X*3<=rest && rest<=X*20;
	if(pruneCheck) {
		if(memo.count(m)) {
//			cout<<"prune OK "<<memo.size()<<endl;
			return false;
		}
	}

	level++;
	if(level<=1) cerr<<"Level "<<level<<endl;
	REP(y, R) REP(x, C) if(!m[y][x]) {
		// put something in x, y
		size_t si=0;
		bool success=false;
		for(auto& sh : shapes) {
			for(auto& p : sh) {
				// check spillover
				Point tr = {x-p.x, y-p.y};
//				cout<<"Try to put "<<si<<" at "<<x<<" "<<y<<" tr "<<tr.x<<" "<<tr.y<<endl;
//				for(auto& pp : sh) {
//					cout<<"  "<<pp.x+tr.x<<" "<<pp.y+tr.y<<endl;
//				}
				bool canput = true;
				for(auto& pp : sh) {
					Point np = pp+tr;
					if(!IN_RANGE(np.x, 0, C)) {canput = false;break;}
					if(!IN_RANGE(np.y, 0, R)) {canput = false;break;}
					if(m[np.y][np.x]) {canput = false;break;}
				}
				if(canput) {
					for(auto& pp : sh) {
						m[pp.y+tr.y][pp.x+tr.x] = true;
					}
//					show();
					nPuts += X;
					used[si]++;

					if(validRest()) {
						bool ret = dfs();
						if(ret) success=true;
					}

					for(auto& pp : sh) {
						m[pp.y+tr.y][pp.x+tr.x] = false;
					}
					nPuts -= X;
					used[si]--;
				}
			}
			si++;
		}
		level--;
		if(!success && pruneCheck) {
			if(memo.size() < 10000) {
				memo.insert(m);
//				show();
				memoCount[rest/X]++;
//				cout<<"Memo Count "<<memoCount<<endl;
			}
		}
		return success;
	}
	return false;
}

map<int, set<PII>> oks;
bool solve() {
	{
		auto key = MP(X, MP(R, C));
		if(ansMemo.count(key)) return ansMemo[key];
	}
	{
		auto key = MP(X, MP(C, R));
		if(ansMemo.count(key)) return ansMemo[key];
	}

	if(X>=7) return true;
	if((R*C)%X) {
		return true;
	}
	if(5<=R && 5<=C) return false;
	if(R==20) return true;
	if(C==20) return true;
//	if(0)
	{
		int CC=C;
		for(auto& p : oks[X]) {
			int r=p.first;
			int c=p.second;
			if(r==R && CC-c>=0) CC=CC%c;
		}
		if(CC==0) {
			cout<<"Prune: RC "<<R<<" "<<C<<" can be made of past info "<<oks[X]<<endl;
			return false;
		}
		int RR=R;
		for(auto& p : oks[X]) {
			int r=p.first;
			int c=p.second;
			if(c==C && RR-r>=0) RR=RR%r;
		}
		if(RR==0) {
			cout<<"Prune: RC "<<R<<" "<<C<<" can be made of past info "<<oks[X]<<endl;
			return false;
		}
		for(auto& p : oks[X]) {
			// can fill repeating success pattern.
			if(R%p.first==0 && C%p.second==0) {
				cout<<"Prune: RC "<<R<<" "<<C<<" can be made of "<<p<<endl;
				return false;
			}
		}
	}

	memoCount = VI(R*C/X);
	memo.clear();
	canPutAll = false;
	nPuts = 0;
	auto& shapes = shapesN[X-1];
	used = VI(shapes.size());
	usedToFill = VI(shapes.size());
	m = vector<vector<bool>>(R, vector<bool>(C, false));
	dfs();
//	cout<<"usedToFill "<<usedToFill<<endl;
	if(*min_element(ALL(usedToFill))==1) {
		oks[X].insert(MP(R, C));
		oks[X].insert(MP(C, R));
//		cout<<"oks "<<oks<<endl;
		return false;
	}
	return true;
}

int main() {
	initAnsMemo();

	int maxX = 6;
	shapesN = vector<vector<vector<Point>>>(maxX);
	shapeSameN = vector<vector<VI>>(maxX);
	init(shapesN.size());
	REP(i, shapesN.size()) {
//		cout<<"ShapesN "<<i+1<<" count "<<shapesN[i].size()<<endl;
//		for(auto& sh : shapesN[i]) printShape(sh);
	}

	int test_cases;
	cin>>test_cases;
	string s;

	if(0)
	{
		RANGE(x, 1, 20) RANGE(r, 1, 20) RANGE(c, 1, 20)
//		if(r>=c)
		{
			X=x; R=r; C=c;
			if((R*C)%X) continue;
//			cout<<"XRC "<<x<<" "<<r<<" "<<c<<": "<<"...."<<endl;
			bool rwin = solve();
//			cout<<"XRC "<<x<<" "<<r<<" "<<c<<": "<<(rwin?"RICHARD":"GABRIEL")<<endl;
			cout<<"ansMemo[MP("<<x<<", MP("<<r<<", "<<c<<"))] = "<<(rwin?"true":"false")<<";"<<endl;
		}
		return 0;
	}

	REP(ttt, test_cases) {
		cin>>X>>R>>C;
		bool rwin = solve();
		cout<<"Case #"<<ttt+1<<": "<<(rwin?"RICHARD":"GABRIEL")<<endl;
//		return 0;
	}
	return 0;
}



