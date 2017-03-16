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
#define MIN_UPDATE(target, value) target = min(target, value)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
#define POPCOUNT(v) __builtin_popcountll((ll)(v))
#define IN_RANGE(v, a, b) ((a)<=(v) && (v)<(b))
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define PRINT1(table, D0) REP(d0, D0) cout<<table[d0]<<" "; cout<<"\n";
#define PRINT2(table, D0, D1) REP(d0, D0) { REP(d1, D1) cout<<table[d0][d1]<<" "; cout<<"\n"; }
#define PRINT3(table, D0, D1, D2) REP(d0, D0) { REP(d1, D1) { REP(d2, D2) cout<<table[d0][d1][d2]<<" "; cout<<"\n"; } cout<<"\n"; }
#define DD(v) cout<<#v<<": "<<v<<endl
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }


typedef vector<int> Edge;
typedef vector<Edge> Graph;
bool tsort(Graph& g, int i, vector<int>& status, vector<int>& topo) {
	status[i]=1;
	for(int j=0;j<g[i].size();j++) {
		if(status[g[i][j]]==1) return false;
		if(!status[g[i][j]] && !tsort(g, g[i][j], status, topo)) return false;
	}
	topo.push_back(i);
	status[i]=2;
	return true;
}
bool tsort(Graph& g) {
	int vn = g.size();
	vector<int> status(vn, 0), topo;
	for(int i=0;i<vn;i++) {
		if(!status[i] && !tsort(g, i, status, topo)) return false;
	}
	return true;
}


int ways(vector<string>& w) {
	int B = w.size();
	Graph g(B);
	REP(i, B) REP(j, B) if(w[i][j]=='1') g[i].PB(j);
	vector<int> status(B), topo;
	bool res = tsort(g, 0, status, topo);
	(void)res;
	reverse(ALL(topo));
	if(!res) return 0;
//	DD(res);
//	DD(topo);
//	return 0;

	VI dp(B);
	dp[0]=1;
	REP(i, topo.size()) {
		int idx = topo[i];
//		DD(idx);
		REP(i, B) {
			if(w[idx][i]=='1') {
				dp[i] += dp[idx];
			}
		}
//		DD(dp);
	}
	return dp[B-1];
}

int main() {
	int test_cases;
	cin>>test_cases;
	ll B,M;
//	auto te = vector<string>{
//		"01001",
//		"00110",
//		"00001",
//		"00101",
//		"00000",
//	};
//	DD(ways(te));
//	return 0;
	REP(ttt, test_cases) {
		cin>>B>>M;
		int N = (B-1);
		vector<string> w(B, string(B, '0'));
		int ok=0;
//		{
//			REP(i, B-1) REP(j, B-1) w[i][j+1]='1';
//			REP(i, B) w[i][i]='0';
//		}
		REP(bits, 1<<(N*N)) {
			REP(y, N) REP(x, N) {
//				w[y][x] = '1';
				w[y][x+1] = (bits>>(y+x*N)&1) ? '1':'0';
			}
			int ng=0;
			REP(y, N) REP(x, N) {
				if(w[x][y]=='1' && w[y][x]=='1') ng=1;
			}
			if(ng) continue;

			int cnt=0;
			REP(x, B) cnt+=w[0][x]=='1';
			if(cnt==0) continue;
//			DD(w);
			int Ways = ways(w);
//			DD(Ways);
			if(Ways==M) {
				cout<<"Case #"<<ttt+1<<": POSSIBLE"<<endl;
				REP(i, B) cout<<w[i]<<endl;
				ok=1;
				break;
			}
		}
		if(!ok) {
			cout<<"Case #"<<ttt+1<<": IMPOSSIBLE"<<endl;
		}
//		return 0;
	}
	return 0;
}



