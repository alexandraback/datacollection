#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <cassert>
#include <cstring>
#include <ext/numeric>
using namespace std ;
using namespace __gnu_cxx ;
typedef long long LL ;
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

long double probability(int k, int l, int limit) { // co najmniej k z l
//	cout << "licze " << k << " z " << l << endl ;
	int i, j ;
	typedef map<pair<int,int>, long double> MAPA ;
	MAPA m ;
	m[MP(0,0)] = 1 ;
	for(i=1 ; i<=l ; i++) {
		MAPA m2 ;
		FOREACH(q, m) {
			int x = q->FI.FI ;
			int y = q->FI.SE ;
			long double val = q->SE/2 ;
			if(x<limit) m2[MP(x+1,y)] += val ;
			else        m2[MP(x,y+1)] += val ;
			if(y<limit) m2[MP(x,y+1)] += val ;
			else        m2[MP(x+1,y)] += val ;
		}
		m = m2 ;		
	}
	long double ans = 0;
	FOREACH(q, m)
		if(q->FI.FI >= k) ans += q->SE ;
	return ans ;
}

int main()
{
	ios_base::sync_with_stdio(0) ;
	cout.setf(ios::fixed) ;
	cout.precision(10) ;
	int C ;
	cin >> C ;
	for(int tests=1 ; tests<=C ; tests++) {
		cout << "Case #" << tests << ": " ;
		int n, x, y ;
		cin >> n >> x >> y ;
		int d = abs(x) + abs(y) ;
		int next_d = 0, next_n = 1 ;
		while(next_n <= n) { // wyczerpujemy pelne warstwy
			if(d == next_d) {
				cout << 1.0 << endl ;
				goto next ;
			}
			n -= next_n ;
			next_d += 2 ;
			next_n += 4 ;
//			cout << n << " " << next_n << " " << next_d << endl ;
		}
		if(d > next_d || n==0 || x==0) {	// poza warstwa
			cout << 0.0 << endl ;
		}
		else {
			int k = y + 1 ;  // chcemy ta wysokosc
			int l = n ; 	 // tyle mamy ruchow
			int limit = next_d ;
			cout << probability(k, l, limit) << endl ;
		}
		next : ;
	}
}

