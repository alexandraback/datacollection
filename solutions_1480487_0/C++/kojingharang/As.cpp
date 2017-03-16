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

int f(int i, double mid, VI& w, int N, int sum) {
	double A = w[i]+sum*mid;
	double rest = sum*(1-mid);
	int ok=1;
	REP(j, N) {
		if(i==j) continue;
		if(A>w[j]) {
			rest -= A-w[j];
			if(rest<0) {
				ok=0;
				break;
			}
		}
	}
	return ok;
}

int main() {
	int test_cases;
	cin>>test_cases;
	REP(ttt, test_cases) {
		int N;
		cin>>N;
		VI w(N);
		REP(i, N) cin>>w[i];
		int sum = accumulate(ALL(w), 0);
		
		cout<<"Case #"<<ttt+1<<": ";
		REP(i, N) {
			if(i!=0) cout<<" ";
			double lo = 0, hi = 1;
			REP(loop, 100) {
				double mid = (lo+hi)/2;
				//cout<<mid<<" "<<A<<" "<<ok<<endl;
				int ok = f(i, mid, w, N, sum);
				if(ok) lo=mid;
				else   hi=mid;
			}
			cout<<setprecision(8)<<hi*100;
		}
		cout<<endl;
	}
	return 0;
}
