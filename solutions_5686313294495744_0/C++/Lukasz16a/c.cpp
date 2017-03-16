#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <cassert>
#include <cstring>
#include <ext/numeric>
#include <gmpxx.h>				// -lgmpxx -lgmp
//#include <NTL/mat_lzz_p.h> 	// -lntl
using namespace std ;
using namespace __gnu_cxx ;
//using namespace NTL ;
typedef mpz_class BIGNUM ;
typedef long long LL ;
typedef pair<int,int> PII ;
typedef vector<int> VI ;
const int INF = 1e9+100 ;
const LL INFLL = (LL)INF * (LL)INF ;
#define REP(i,n) for(int i=0;i<(n);++i)
#define ALL(c) c.begin(),c.end()
#define VAR(v,i) __typeof(i) v=(i)
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define CLEAR(t) memset(t,0,sizeof(t))
#define PB push_back
#define MP make_pair
#define FI first
#define SE second

template<class T1,class T2> ostream& operator<<(ostream &s, const pair<T1,T2> &x) { s<< "(" << x.FI << "," << x.SE << ")"; return s;}
template<class T>           ostream& operator<<(ostream &s, const vector<T>   &t) { FOREACH(it, t) s << *it << " " ; return s ; }
template<class T>           ostream& operator<<(ostream &s, const set<T>      &t) { FOREACH(it, t) s << *it << " " ; return s ; }
template<class T1,class T2> ostream& operator<<(ostream &s, const map<T1, T2> &t) { FOREACH(it, t) s << *it << " " ; return s ; }

////////////////////////////////////////////////////////////////////////////////

void _main() ;

int main()
{
	ios_base::sync_with_stdio(0) ;
	int C ;
	cin >> C ;
	for(int tests=1 ; tests<=C ; tests++) {
//		cerr << "Case #" << tests << endl ;
		cout << "Case #" << tests << ": " ;
		_main() ;
	}
}

#define DEBUG if(DFLAG) cerr
#define DFLAG 1

////////////////////////////////////////////////////////////////////////////////

const int MAXN = 2100 ;
pair<pair<string, string>, bool> t[MAXN] ;

void _main() {
	int n ;
	string a, b ;
	cin >> n ;
	REP(i, n) {
		cin >> a >> b ;
		t[i] = MP(MP(a,b), false) ;
	}
	sort(t, t+n) ;
	
	LL ret=0 ;
	REP(i,n) {
		if(t[i].SE) continue ;
		REP(j, n) {
			if(t[j].SE) continue ;
			
			pair<string, string> x = MP(t[i].FI.FI, t[j].FI.SE) ;
			if(x==t[i].FI || x==t[j].FI) continue ;
			auto y = MP(x,false) ;
			auto it = lower_bound(t,t+n, y) ;
			if(it!=t+n && *it==y) {
				ret ++ ;
				it->SE = true ;
			}
		}
	}
	cout << ret << endl ;
}

