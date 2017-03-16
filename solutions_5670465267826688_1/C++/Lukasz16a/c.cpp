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
#include <gmpxx.h>			// -lgmpxx -lgmp
#include <NTL/mat_lzz_p.h> 	// -lntl
using namespace std ;
using namespace __gnu_cxx ;
using namespace NTL ;
typedef mpz_class BIGNUM ;
typedef long long LL ;
typedef pair<int,int> PII ;
typedef vector<int> VI ;
const int INF = 1e9 ;
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

template<class T1,class T2> ostream& operator<<(ostream &s, const pair<T1,T2> &x) { s<< "(" << x.FI << "," << x.SE << ")"; return s;}
template<class T>           ostream& operator<<(ostream &s, const vector<T>   &t) { FOREACH(it, t) s << *it << " " ; return s ; }
template<class T>           ostream& operator<<(ostream &s, const std::set<T>      &t) { FOREACH(it, t) s << *it << " " ; return s ; }
template<class T1,class T2> ostream& operator<<(ostream &s, const map<T1, T2> &t) { FOREACH(it, t) s << *it << " " ; return s ; }

//////////////////////////////////////////////////////////////

mat_zz_p ID, I, J, K ;

void init() {
	zz_p::init(3) ;
	
	ID.SetDims(2,2) ;
	ID[0][0] = ID[1][1] = 1 ;
	
	I.SetDims(2,2) ; 
	I[0][0] = I[0][1] = I[1][0] = 1 ;
	I[1][1] = -1 ;
	
	J.SetDims(2,2) ;
	J[0][0] = -1 ;
	J[0][1] = J[1][0] = J[1][1] = 1 ;
	
	K=I*J ;
}
	

void _main() {
	int L, i ;
	char c ;
	LL X ;
	cin >> L >> X ;
	vector<mat_zz_p> t ;
	mat_zz_p all=ID ;
	REP(i, L) {
		cin >> c ;
		if(c=='i') t.PB(I) ;
		else if(c=='j') t.PB(J) ;
		else if(c=='k') t.PB(K) ;
		else assert(false) ;
		all *= t.back() ;
	}
	if(NTL::power(all, X) == -ID) {
		mat_zz_p a=ID ;
		for(int i=0 ; i<4*L && i<X*L ; i++) {
			a *= t[i%L] ;
			if(a==I) {
				mat_zz_p b = ID ;
				for(int j=0 ; j<4*L && (i+1)+j<X*L ; j++) {
					b *= t[((i+1)+j)%L] ;
					if(b==J) {
						cout << "YES" << endl ;
						return ;
					}
				}
			}
		}
	}
	cout << "NO" << endl ;
}

int main()
{
	ios_base::sync_with_stdio(0) ;
	init() ;
	int C ;
	cin >> C ;
	for(int tests=1 ; tests<=C ; tests++) {
		cerr << "Case #" << tests << endl ;
		cout << "Case #" << tests << ": " ;
		_main() ;
	}
}

