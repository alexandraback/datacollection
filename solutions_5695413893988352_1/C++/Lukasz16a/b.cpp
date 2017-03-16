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
#include <sstream>
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
#define DFLAG 0

////////////////////////////////////////////////////////////////////////////////

bool eq(int a, char b) {
	if(b=='?') return true ;
	else return a+'0'==b ;
}
int down(char b) {
	if(b=='?') return 0 ;
	else return b-'0' ;
}
int up(char b) {
	if(b=='?') return 9 ;
	else return b-'0' ;
}

BIGNUM retA, retB ;

void __test(BIGNUM A, BIGNUM B) {
	DEBUG << "testuje " << A << " " << B << endl ;
	if(retA==-1 || abs(A-B)<abs(retA-retB) || (abs(A-B)==abs(retA-retB) && MP(A,B)<MP(retA,retB))) {
		retA = A ;
		retB = B ;
	}
}		

void show(BIGNUM A, int n) {
	string s ;
	stringstream aaa ;
	aaa << A ;
	aaa >> s ;
	cout << string(n-s.size(), '0') << s ;
}	

void _main() {
	retA = retB = -1 ;
	
	string a, b ;
	cin >> a >> b ;
	int n=a.size() ;
	REP(i, n) {
		BIGNUM A,B, begin=0 ;
		REP(j, i) {
			bool ok=false ;
			REP(d, 10)
				if(eq(d, a[j]) && eq(d, b[j])) {
					ok=true ;
					begin = begin*10+d ;
					break ;
				}
			if(!ok) goto omit ;
		}
		A=B=begin ;
		DEBUG << "i= " << i << " A = " << A << " B = " << B << endl ;
		DEBUG << a[i] << " " << b[i] << endl ;
		REP(da, 10)
			REP(db, 10)
				if(eq(da, a[i]) && eq(db, b[i])) {
					DEBUG << "da = " << da << " db = " << db << endl ;
					BIGNUM A2 = A*10+da ;
					BIGNUM B2 = B*10+db ;
					
					BIGNUM AA=A2, BB=B2 ;
					for(int j=i+1 ; j<n ; j++) {
						AA = AA*10+up(a[j]) ;
						BB = BB*10+down(b[j]) ;
					}
					__test(AA, BB) ;
					
					AA=A2, BB=B2 ;
					for(int j=i+1 ; j<n ; j++) {
						AA = AA*10+down(a[j]) ;
						BB = BB*10+up(b[j]) ;
					}
					__test(AA, BB) ;
				}	
	omit: ;
	}
	show(retA, n) ;
	cout << " " ;
	show(retB, n) ;
	cout << endl ;
}

