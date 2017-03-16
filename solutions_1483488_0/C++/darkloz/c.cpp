//=======:=====================================================================
// Author      :  Carlos Eduardo Guillen Davila
//============================================================================

#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
#include <set>
#include <bitset>
#include <map>
#include <stack>
#include <queue>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <cstring>
#include <limits>

#define all(c) c.begin(),c.end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define forr(a,i,f) for( int a = i ; a < f ; ++a )
#define iter(c) typeof( c.begin() )

#define feq(a,b) fabs( a-b ) < eps
#define sqr(x) ((x)*(x))
#define eps 1e-7

#define pass puts("PASO");

#define V(x) vector<x>
#define VV(x) vector< V(x) >
#define P(a,b) pair<a,b>
#define pii P(int,int)
#define vi V(int)
#define vvi VV(int)

using namespace std;

const int maxn = 2000000 + 1;
int ans[maxn];


bool nfz;
int base;
int nextTr( int n ){
	int mod = n%10;
	n/=10;
	if( mod ){
		nfz = 1;
		n += mod*base;
	}else
		nfz = 0;
	return n;
	
}

int main() {



	int  t; cin >> t;
	forr( caso , 0 , t){
		int a , b; cin >> a >> b;
		
		memset( ans, 0 , sizeof(ans[0])*(b+1) );

		base = 10;
		for( int nd = 2  ; nd < 8;  ++nd, base*=10 ){
			int nxt = base*10;
			forr( q , base , nxt ){
			if(q == b+1) goto fin;

				int tmp = nextTr(q);
				nfz = true ;
				while( tmp != q ){
					if( tmp < q && nfz ){
						if( a <= tmp  && q <= b )
							++ans[q];
					}
					tmp = nextTr(tmp);
				}
			}
		}

		fin:
		forr(i, a , b+1){
			ans[i] += ans[i-1];
		}

		if( a ) a = 1;
		printf("Case #%d: %d\n" , caso +1,  ans[b] -ans[a-1] );
	}
	
	return 0; 
}
