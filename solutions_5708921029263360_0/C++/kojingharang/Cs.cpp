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


struct Outfit {
	int j, p, s;
};

bool operator==(const Outfit& a, const Outfit& b) {
	return b.j==a.j && b.p==a.p && b.s==a.s;
}

bool check(vector<Outfit>& Os, int J, int P, int S, int K) {
//	DD("check");
//	REP(i, Os.size()) {
//		auto o = Os[i];
//		cout<<o.j+1<<" "<<o.p+1<<" "<<o.s+1<<endl;
//	}

	REP(i, Os.size()-1) {
		if(Os[i]==Os[i+1]) {
//			DD("dup");
			return false;
		}
	}
	REP(j, J) REP(p, P) {
		int cnt=0;
		REP(i, Os.size()) {
			if(Os[i].j==j && Os[i].p==p) cnt++;
		}
		if(cnt>K) {
//			DD("JP");
			return false;
		}
	}
	REP(p, P) REP(s, S) {
		int cnt=0;
		REP(i, Os.size()) {
			if(Os[i].s==s && Os[i].p==p) cnt++;
		}
		if(cnt>K) {
//			DD("PS");
			return false;
		}
	}
	return true;
}

int main() {
	int test_cases;
	cin>>test_cases;
	ll J,P,S,K;
	assert((Outfit{0,0,0}==Outfit{0,0,0}));
	REP(ttt, test_cases) {
		cin>>J>>P>>S>>K;
		vector<Outfit> Os;
		REP(k, 1000000) {
			int ok1 = 0;
//			DD(Os.size());
			REP(j, J) REP(p, P) REP(s, S) {
				auto o = Outfit{j, p, s};
//				DD("push");DD(j);DD(p);DD(s);
				Os.PB(o);
				if(!check(Os, J, P, S, K)) {
//					DD("NG");
					Os.pop_back();
				} else {
					ok1=1;
					goto Next;
				}
			}
			Next:
			if(!ok1) goto END;
		}
		END:
		cout<<"Case #"<<ttt+1<<": "<<Os.size()<<endl;
		REP(i, Os.size()) {
			auto o = Os[i];
			cout<<o.j+1<<" "<<o.p+1<<" "<<o.s+1<<endl;
		}
//		return 0;
	}
	return 0;
}



