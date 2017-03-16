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
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
#define POPCOUNT __builtin_popcount
#define POPCOUNTLL __builtin_popcountll
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define PRINT2(table, W, H) REP(y, H) { REP(x, W) cout<<table[y][x]<<" "; cout<<"\n"; }
#define PRINT3(table, W, H, D) REP(d, D) { REP(y, H) { REP(x, W) cout<<table[d][y][x]<<" "; cout<<"\n"; } cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

ll N,M,K;
void bfs(VVI& w, int x, int y) {
	w[y][x] = 2;
	REP(i, 4) {
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(0<=nx && nx<M && 0<=ny && ny<N && w[ny][nx]==0) bfs(w, nx, ny);
	}
}
bool check(ll v) {
	int W=M, H=N;
	VVI w(N, VI(M));
	REP(x, W) REP(y, H) {
		if((v>>(y*W+x))&1) {
			w[y][x] = 1;
		}
	}
	REP(x, W) {
		if(w[0][x]==0) bfs(w, x, 0);
		if(w[H-1][x]==0) bfs(w, x, H-1);
	}
	REP(y, H) {
		if(w[y][0]==0) bfs(w, 0, y);
		if(w[y][W-1]==0) bfs(w, W-1, y);
	}
//	cout<<w<<endl;
	int k=0;
	REP(x, W) REP(y, H) {
		if(w[y][x]<=1)k++;
	}
	return k>=K;
}

int main() {
	int test_cases;
	cin>>test_cases;
	REP(ttt, test_cases) {
		cin>>N>>M>>K;
		int ans = 1<<30;
		REP(b, 1<<(N*M)) {
			if(check(b)) {
				int n = POPCOUNT(b);
				ans=min(ans, n);
			}
		}
		cout<<"Case #"<<ttt+1<<": "<<ans<<endl;
//		return 0;
	}
	return 0;
}



