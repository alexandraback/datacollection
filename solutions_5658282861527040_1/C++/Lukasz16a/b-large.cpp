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

const int MAXN = 210 ;

bool ok(int a, char x) {
	if(x=='*') return true ;
	else return a+'0'== x ;
}

int pos(char a, char b, char c) {
	int ret=0 ;
	for(int aa=0 ; aa<2 ; aa++)
		for(int bb=0 ; bb<2 ; bb++)
			for(int cc=0 ; cc<2 ; cc++)
				if(ok(aa,a) && ok(bb,b) && ok(cc,c) && ((aa&bb)==cc)) ret++ ;
	return ret ;
}

LL counter(string a, string b, string c) {
	assert((a.size() == b.size()) && (b.size()==c.size())) ;
	LL ret=1 ;
	int i ;
	REP(i, a.size()) ret *= pos(a[i], b[i], c[i]) ;
	return ret ;
}

vector<string> getDesc(int A) {
	vector<string> ret ;
	int i ;
	string s ;
	for(i=30 ; i>=0 ; i--) {
		while(i>=0 && (A&(1ll<<i))==0) {
			s += '0' ;
			i-- ;
		}
		if(i>=0) {
			ret.PB(s + '0' + string(i, '*')) ;
			s += '1' ;
		}
	}
	return ret ;
}

void _main() {
	int A, B, K ;
	cin >> A >> B >> K ;
	vector<string> AA = getDesc(A) ;
	vector<string> BB = getDesc(B) ;
	vector<string> KK = getDesc(K) ;
//	cout << AA << endl << BB << endl << KK << endl ;
	LL ret=0 ;
	FOREACH(a, AA)
		FOREACH(b, BB)
			FOREACH(k, KK)
				ret += counter(*a,*b,*k) ;
	cout << ret << endl ;
}

int main()
{
	ios_base::sync_with_stdio(0) ;
	int C ;
	cin >> C ;
	for(int tests=1 ; tests<=C ; tests++) {
		cerr << "Case #" << tests << endl ;
		cout << "Case #" << tests << ": " ;
		_main() ;
	}
}

