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
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << "\n"; } return os; }
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

vector<set<set<Point>>> shapesN;

void printShape(set<Point> sh) {
	int L = 7;
	vector<string> s(2*L, string(2*L, ' '));
	for(auto& p : sh) {
//		cout<<":: "<<p.x<<" "<<p.y<<endl;
		s[p.y+L][p.x+L] = '*';
	}
	cout<<s<<endl;
}


bool sameTranslate(const set<Point>& a, const set<Point>& b) {
	vector<Point> va(ALL(a));
	vector<Point> vb(ALL(b));
	Point tr;
	REP(i, va.size()) {
		Point ltr = vb[i]-va[i];
		if(i==0) {
			tr = ltr;
		} else {
			if(!(tr==ltr)) return false;
		}
	}
	return true;
}

bool same(const set<Point>& a, const set<Point>& b) {
	REP(r, 2) {
		vector<Point> neu(ALL(b));
		if(r) for(auto& p : neu) p.x*=-1;
		REP(i, 4) {
			for(auto& p : neu) {
				swap(p.x, p.y);
				p.y*=-1;
			}
			if(sameTranslate(a, set<Point>(ALL(neu)))) return true;
		}
	}
	return false;
}


bool dup(set<Point>& shape, set<set<Point>>& shapes) {
	for(auto& orig : shapes) {
		if(sameTranslate(shape, orig)) return true;
	}
	return false;
}

void init(int N) {
	if(N==1) {
		set<Point> shape;
		shape.insert({0, 0});
		shapesN[0].insert(shape);
		return;
	}
	init(N-1);
	set<set<Point>> ns;
	for(auto& orig : shapesN[N-2]) {
//		cout<<"For orig "<<orig<<endl;
		for(auto& p : orig) {
			REP(dir, 4) {
				int nx = dx[dir]+p.x;
				int ny = dy[dir]+p.y;
				set<Point> neu(orig);
				if(neu.insert({nx, ny}).second) {
					if(!dup(neu, ns)) ns.insert(neu);
				}
//				cout<<"Add "<<neu<<endl;
			}
		}
	}
	shapesN[N-1] = ns;
}

ll X,R,C;
VI used;
VI usedToFill;
vector<vector<bool>> m;
int nPuts;
int level;

void show() {
	REP(y, R){
		REP(x,C) {
			cout<<(m[y][x]?'*':'_');
		}
		cout<<endl;
	}
	cout<<endl;
}

void dfs() {
//	cout<<"DFS"<<endl;
	auto& shapes = shapesN[X-1];
	if(nPuts==R*C) {
		REP(i, used.size()) if(used[i]) usedToFill[i] = 1;
		return;
	}
	level++;
	if(level<3) cerr<<"Level "<<level<<endl;
	REP(y, R) REP(x, C) if(!m[y][x]) {
		// put something in x, y
		size_t si=0;
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

					dfs();

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
		return;
	}
}

int main() {
	shapesN = vector<set<set<Point>>>(6);
	init(shapesN.size());
//	REP(i, shapesN.size()) {
//		cout<<"ShapesN "<<i+1<<" count "<<shapesN[i].size()<<endl;
////		cout<<shapesN[i]<<endl;
//		for(auto& sh : shapesN[i]) {
//			printShape(sh);
//		}
//	}

	int test_cases;
	cin>>test_cases;
	string s;
	REP(ttt, test_cases) {
		cin>>X>>R>>C;
		bool rwin = true;
		if(X<7) {
			nPuts = 0;
			auto& shapes = shapesN[X-1];
			used = VI(shapes.size());
			usedToFill = VI(shapes.size());
			m = vector<vector<bool>>(R, vector<bool>(C, false));
			dfs();
//			cout<<"usedToFill "<<usedToFill<<endl;
			vector<set<Point>> vshapes(ALL(shapes));
			REP(i, usedToFill.size()) {
				if(usedToFill[i]==0) {
					REP(j, usedToFill.size()) {
						if(usedToFill[j]==1 && same(vshapes[i], vshapes[j])) {
							usedToFill[i] = 1;
						}
					}
				}
			}
//			cout<<"New usedToFill "<<usedToFill<<endl;
			if(*min_element(ALL(usedToFill))==1) rwin = false;
		}
		cout<<"Case #"<<ttt+1<<": "<<(rwin?"RICHARD":"GABRIEL")<<endl;
//		return 0;
	}
	return 0;
}



