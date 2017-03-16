
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


double p[99999];
int main() {


	int t; scanf("%d",&t);
	int caso = 1;
	while( t-- ){
		int a , b;
		scanf("%d %d",&a, &b);

		forr(i ,0 , a){
			scanf( "%lf",p+i);
			if( i > 0) p[i] *= p[i-1];
		}

		// enter
		double ans = b+2; 
		// keep w
		ans = min( ans ,  (b-a+1)*p[a-1] + (b-a+1+b+1)*(1-p[a-1])  );
		forr(back, 1,a){
			int _a = a-back;
			ans = min( ans , (back+b-_a+1)*p[_a-1] +(back + b-_a+1+b+1)*(1-p[_a-1]) );
		}	
		printf("Case #%d: %.6lf\n" , caso++ , ans );

	}
	
	return 0; 
}
