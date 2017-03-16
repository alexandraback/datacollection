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
#define REP(i,n) for(i=0;i<(n);++i)
#define ALL(c) c.begin(),c.end()
#define VAR(v,i) __typeof(i) v=(i)
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define PB push_back
#define MP make_pair
#define FI first
#define SE second

main()
{
	ios_base::sync_with_stdio(0) ;
	int tests ;
	int t[100] ;
	cin >> tests ;
	for(int test=1 ; test<=tests ; test++) {
		cout << "Case #" << test << ":" << endl ;
		int n, i ;
		cin >> n ;
		map<int, vector<int> > mapa ;
		for(i=0 ; i<n ; i++) cin >> t[i] ;
		for(int mask=0 ; mask<(1<<n) ; mask++) {
			int s = 0 ;
			for(int j=0 ; j<n ; j++) {
				if(mask & (1<<j)) s += t[j] ;
			}
			mapa[s].PB(mask) ;
		}
		FOREACH(q, mapa) {
			if(q->SE.size()>1) {
				int a = q->SE[0] ;
				int b = q->SE[1] ;
				int c = a^b ;
				a = a^c ;
				b = b^c ;
				
				for(int j=0; j<n ; j++)
					if(a & (1<<j)) cout << t[j] << " " ;
				cout << endl ;
				for(int j=0; j<n ; j++)
					if(b & (1<<j)) cout << t[j] << " " ;
				cout << endl ;
				
				goto dalej ;
			}
		}
		
		assert(false) ;
		dalej : ;
	}
}

