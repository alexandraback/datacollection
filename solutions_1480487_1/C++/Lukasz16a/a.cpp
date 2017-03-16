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
	int s[200] ;
	cin >> tests ;
	for(int test=1 ; test<=tests ; test++) {
		cout << "Case #" << test << ": " ;
		int n, i, all=0 ;
		cin >> n ;
		for(i=0 ; i<n ; i++) {
			cin >> s[i] ;
			all += s[i] ;
		}
		for(i=0 ; i<n ; i++) {
			double l=0, r=100 ;
			while(r-l > 1e-8) {
				double sr = (l+r)/2 ;
				double need = sr*all ;
				double y = s[i] + need ;
				for(int j=0 ; j<n ; j++) {
					if(i==j) continue ;
					need += max(0.0, y-s[j]) ;
				}
				
				if(need>=all) r=sr ;
				else l=sr ;
			}
			cout.setf(ios::fixed) ;
			cout.precision(6) ;
			cout << l*100 << " " ;
		}
		cout << endl ;
	}
}

