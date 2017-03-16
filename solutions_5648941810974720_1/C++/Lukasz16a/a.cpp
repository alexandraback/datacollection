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

const int MAXN = 200100 ;

string s[10] = { "ZERO","TWO", "FOUR", "SIX", "FIVE", "SEVEN", "ONE", "NINE", "THREE", "EIGHT"} ;
int d[10] = {0, 2, 4, 6, 5, 7, 1, 9, 3, 8} ;

map<char,int> conv(const string &s) {
	map<char, int> M ;
	FOREACH(it, s) M[*it]++ ;
	return M ;
}

void _main() {
	string pattern ;
	cin >> pattern ;
	map<char, int> p = conv(pattern) ;
	string ret ;
	for(int i=0 ; i<=9 ; ) {
		bool ok=true ;
		FOREACH(it, s[i]) {
			p[*it]-- ;
			ok = ok && (p[*it]>=0) ;
		}
		if(ok) ret += d[i]+'0' ;
		else {
			FOREACH(it, s[i]) p[*it]++ ;
			i++ ;
		}
	}
	FOREACH(it, p) assert(it->SE==0) ;
	
	sort(ALL(ret)) ;
	cout << ret << endl ;
}

