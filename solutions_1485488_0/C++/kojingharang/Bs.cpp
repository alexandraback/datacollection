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
using namespace std;

#define EPS 1e-12
#define ll long long
#define VI vector<int>
#define PII pair<int, int> 
#define VVI vector<vector<int> >
#define REP(i,n) for(int i=0,_n=(n);(i)<(int)_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }

#define INF 100000000

int main() {
	int test_cases;
	cin>>test_cases;
	REP(ttt, test_cases) {
		int L, H, W;
		cin>>L>>H>>W;
		VVI ce(H, VI(W));
		VVI fl(H, VI(W));
		REP(y, H) REP(x, W) cin>>ce[y][x];
		REP(y, H) REP(x, W) cin>>fl[y][x];
		VVI ti(H, VI(W, INF));
		VVI he(H, VI(W));
		VVI st(H, VI(W, 1));
		st[0][0] = 0;
		ti[0][0] = 0;
		he[0][0] = L;
		VVI vis(H, VI(W));
		deque<PII> q;
		q.PB(MP(0,0)); // x, y
		while(q.size()) {
			//cout<<q.size()<<endl;
			PII v = q.front();q.pop_front();
			int x = v.first;
			int y = v.second;
			if(x==W-1 && y==H-1) break;
			if(vis[y][x]) continue;
			vis[y][x]=1;
			int tdx[] = {1, 0, -1, 0};
			int tdy[] = {0, 1, 0, -1};
			REP(dir, 4) {
				if(dir==0 && x>=W-1) continue; // right
				if(dir==1 && y>=H-1) continue; // down
				if(dir==2 && 0>=x) continue; // left
				if(dir==3 && 0>=y) continue; // top
				int nx = x+tdx[dir];
				int ny = y+tdy[dir];
				int lvl = he[y][x];
				if(fl[y][x]+50<=ce[ny][nx] && fl[ny][nx]+50<=ce[ny][nx] && fl[ny][nx]+50<=ce[y][x] ) {
					int wait = max(0, lvl-(ce[ny][nx]-50));
					if(!st[y][x] && wait==0) {
						st[ny][nx] = 0;
						ti[ny][nx] = ti[y][x];
						he[ny][nx] = he[y][x];
						q.PB(MP(nx, ny));
					} else
					if(fl[y][x]+20<=lvl-wait) {
						if(ti[y][x]+wait+10 < ti[ny][nx]) {
							ti[ny][nx] = ti[y][x]+wait+10;
							he[ny][nx] = lvl-(wait+10);
							q.PB(MP(nx, ny));
						}
					} else {
						if(ti[y][x]+wait+100 < ti[ny][nx]) {
							ti[ny][nx] = ti[y][x]+wait+100;
							he[ny][nx] = lvl-(wait+100);
							q.PB(MP(nx, ny));
						}
					}
				}
			}
			//cout<<"loop end"<<endl;
		}
		//cout<<ti<<endl;
		//cout<<he<<endl;
		//cout<<st<<endl;
		cout<<"Case #"<<ttt+1<<": "<<(double)ti[H-1][W-1]/10<<endl;
	}
	return 0;
}
