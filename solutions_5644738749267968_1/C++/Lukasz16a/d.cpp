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
#include <gmpxx.h>			// -lgmpxx -lgmp
using namespace std ;
using namespace __gnu_cxx ;
typedef mpz_class BIGNUM ;
typedef long long LL ;
typedef pair<int,int> PII ;
typedef vector<int> VI ;
const int INF = 1000*1000*1000 ;
const LL INFLL = (LL)INF * (LL)INF ;
#define REP(i,n) for(i=0;i<(n);++i)
#define ALL(c) c.begin(),c.end()
#define VAR(v,i) __typeof(i) v=(i)
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define CLEAR(t) memset(t,0,sizeof(t))
#define PB push_back
#define MP make_pair
#define FI first
#define SE second

template<class T1, class T2> ostream & operator<<(ostream &s, pair<T1,T2> x) { s << "(" << x.FI << "," << x.SE << ")" ; return s ; }
template<class T> ostream & operator<<(ostream &s, const vector<T> &t) { FOREACH(it, t) s << *it << " " ; return s ; }
template<class T1, class T2> ostream & operator<<(ostream &s, const map<T1, T2> &t) { FOREACH(it, t) s << *it << " " ; return s ; }

const int MAXN = 1100 ;

double A[MAXN], B[MAXN] ;

void _main() {
	int n, i ;
	cin >> n ;
	REP(i,n) cin >> A[i] ;
	REP(i,n) cin >> B[i] ;
	sort(A,A+n) ;
	sort(B,B+n) ;
/*	REP(i,n) cout << A[i] << " " ;
	cout << endl ;
	REP(i,n) cout << B[i] << " " ;
	cout << endl ;*/
	int a=0, b=n-1 ;
	for(i=0 ; i<n ; i++) {
		if(A[i]<B[a]) b-- ;
		else a++ ;
	}
	cout << a << " " ;
	set<double> S(B, B+n) ;
	for(i=0 ; i<n ; i++) {
		set<double>::iterator it = S.upper_bound(A[i]) ;
		if(it != S.end())
			S.erase(it) ;
		else break ;
	}
	cout << n-i << endl ;
}

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

