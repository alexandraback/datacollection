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
//#include <NTL/mat_lzz_p.h> 	// -lntl
using namespace std ;
using namespace __gnu_cxx ;
//using namespace NTL ;
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
template<class T>           ostream& operator<<(ostream &s, const std::set<T> &t) { FOREACH(it, t) s << *it << " " ; return s ; }
template<class T1,class T2> ostream& operator<<(ostream &s, const map<T1, T2> &t) { FOREACH(it, t) s << *it << " " ; return s ; }

//////////////////////////////////////////////////////////////

const int MAXN = 200100 ;

LL calc(LL a, LL b) {
	LL ret=b-a ;
	
	VI t ;
	LL M=b ;
	while(M>0) {
		t.PB(M%10) ;
		M/=10 ;
	}
	reverse(ALL(t)) ;
	for(int i=0 ; i<t.size() ; i++) {
		int j ;
		LL a=0 ;
		if(i==0) continue ;
		for(j=i ; j>=0 ; j--)
			a = a*10 + t[j] ;
		LL b=0 ;
		for(j=i+1 ; j<t.size() ; j++)
			b = b*10 + t[j] ;
		assert(a>0) ;
		if(b>0)
			ret = min(ret, 1+(a-1)+1+(b-1)) ;
		if(b==0 && i+1!=t.size())
			ret = min(ret, 1+(a-2)+1+power((LL)10, t.size()-(i+1))-1) ;
	}
	//cout << a << "-> " << b << " : " << ret << endl ;
	return ret ;
}

void _main() {
	LL N ;
	cin >> N ;
	LL ret=1 ;
	LL a, k ;
	for(a=1, k=0 ; 10*a<=N ; a*=10, k++) {
		ret += calc(a, 10*a-1) +1 ;
	}
	ret += calc(a, N) ;
	cout << ret << endl ;
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

