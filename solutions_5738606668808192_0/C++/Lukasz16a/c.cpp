#include <bits/stdc++.h>
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
template<class T>           ostream& operator<<(ostream &s, const std::set<T> &t) { FOREACH(it, t) s << *it << " " ; return s ; }
template<class T1,class T2> ostream& operator<<(ostream &s, const map<T1, T2> &t) { FOREACH(it, t) s << *it << " " ; return s ; }

//////////////////////////////////////////////////////////////

//const int N=6, J=3 ;
const int N=16, J=50 ;


void _main() {
	cout << endl ;
	int divs[10] = {2,3,5,7,11,13,17,19,23,27} ;
	for(int rest=1, found=0 ; found<J ; rest+=2) {
		VI ret ;
		bool maybe=true ;
		for(int base=2 ; base<=10 && maybe ; base++) {
			BIGNUM a = 1 ;
			for(int i=N-2 ; i>=0 ; i--) {
				a *= base ;
				if(rest&(1<<i))
					a ++ ;
			}
			maybe=false ;
			for(int i=0 ; i<10 ; i++)
				if(a%divs[i]==0) {
					ret.PB(divs[i]) ;
					maybe=true ;
					break ;
				}
		}
		if(maybe) {
			bitset<N> num(rest) ;
			num[N-1] = true ;
			cout << num << " " << ret << endl ;
			found++ ;
		}
	}		
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

