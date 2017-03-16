
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


int main() {

	int t ; cin >> t;

	forr(caso , 0, t ){
		printf("Case #%d: " , caso+1);

		int n; cin >> n;
		int s; cin >> s;
		int p; cin >> p;

		int point[n];
		forr(i ,0 , n){
			cin >> point[i];
		}

		int mod, div;
		int contar = 0 ;
		int ns = 0;
		forr(i ,0 , n){
			div = point[i]/3;
			mod = point[i]%3;
			if( mod  == 1 ){
				if( div + 1 >= p  )
					contar++;
			}else if(mod == 2){
				if( div+1 >= p  )
					contar++;
				else if( ns < s && div +2 >= p ){
					contar++;
					ns++;
				}
			}else{
				if( div >= p )
					contar++;
				else if(  point[i] && ns < s && div+1 >= p ){
					contar++;
					ns++;
				}
			}
				
		}

		printf("%d\n",  contar ) ;

	}


	
	return 0; 
}
