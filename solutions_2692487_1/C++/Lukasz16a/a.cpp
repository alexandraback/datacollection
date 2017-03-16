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

const int MAXN = 210 ;
LL t[MAXN][MAXN] ;
int A[MAXN] ;

int main()
{
	ios_base::sync_with_stdio(0) ;
	int C ;
	cin >> C ;
	for(int tests=1 ; tests<=C ; tests++) {
		cout << "Case #" << tests << ": " ;
		CLEAR(t) ;
		int n, i, j ;
		cin >> t[0][0] >> n ;
		REP(i,n) cin >> A[i] ;
		sort(A, A+n) ;
		
		    REP(i,n) {
		        int next = A[i] ;
		        REP(j,n+1) {
		            if(t[i][j] == 0) continue ; // nie mozemy sie stad ruszyc
		            
		            if(t[i][j] > next)
		                t[i+1][j] = max(t[i+1][j], t[i][j]+next) ; // pochlaniamy
		            else {
		                t[i+1][j+1] = max(t[i+1][j+1], t[i][j]) ; // usuwamy
		                if(t[i][j] > 1)
		                    t[i][j+1] = max(t[i][j+1], t[i][j] + (t[i][j]-1)) ;
		            }
		        }
		   }

		REP(j,n+1) {
			if(t[n][j]) {	
				cout << j << endl ;
				break ;
			}
		}
		assert(j<=n) ;
	}
}

