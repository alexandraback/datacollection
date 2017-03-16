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

const int MAXN = 55 ;
bool t[MAXN][MAXN] ;

void _main() {
	int R,C,M, i, j ;
	cin >> R >> C >> M ;
	int left = R*C-M ;
	bool swapped=false ;
	if(R<C) {
		swap(R,C) ;
		swapped = true ;
	}
//	cout << "left = " << left << endl ;
	CLEAR(t) ;
	if(C==1)
		REP(j,left) t[j][0] = true ;
	else if(C==2) {
		if(left==1) t[0][0] = true ;
		else if(left%2==0 && left>=4)
			REP(j, left/2) t[j][0] = t[j][1] = true ;
	}
	else {
		if(left==1) t[0][0] = true ;
		else if(left==2 || left==3 || left==5 || left==7) ; // jest zle
		else if(left<=2*C+1) {
			if(left%2==0)
				REP(j, left/2) t[0][j] = t[1][j] = true ;
			else {
				REP(i,3) REP(j,3) t[i][j] = true ;
				REP(j, (left-9)/2) t[0][3+j] = t[1][3+j] = true ;
			}
		}
		else {
			REP(i,R)
				REP(j,C) t[i][j] = (i*C+j < left) ;
			if(left%C==1)
				swap(t[(left+1-1)/C][(left+1-1)%C], t[(left-1-1)/C][(left-1-1)%C]) ;
		}
	}
	
	if(swapped) {
		swap(R,C) ;
		REP(i, MAXN)
			for(j=i+1 ; j<MAXN ; j++) swap(t[i][j], t[j][i]) ;
	}
	cout << endl ;
	if(t[0][0]) {
		REP(i,R) {
			REP(j,C) {
				if(i==0 && j==0) cout << 'c' ;
				else if(t[i][j]) cout << '.' ;
				else cout << '*' ;
			}
			cout << endl ;
		}
	}
	else cout << "Impossible" << endl ;
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

