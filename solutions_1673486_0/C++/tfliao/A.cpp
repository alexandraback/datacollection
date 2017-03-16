#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

typedef long double LD ;
#define MAX 100000

double solv ()
{
	double pp = 1;
	double ans ;
	int A, B ;
	
	cin >> A >> B ;
	ans = min ( B+2, (A+B+1) ) ;
	
	for ( int i=1;i<=A;++i ) {
		double p ;
		cin >> p ;
		pp *= p ;
		// p = (pp*(A-i+B)+(1-pp)*(A-i+B+B+1)) ;
		// p = (pp*(B-A+1+2*(A-i))) + ((1-pp)*(B-A+1+2*(A-i))+B+1);
		p = (pp*(A+B-2*i+1)+(1-pp)*((A+2*B-2*i+2))) ;
		//printf ( "%d: %.6f %.6f\n", i, pp, p ) ;
		ans = min ( ans, p );
	}
	return ans ;
			
}

int main()
{
	int T, nCase = 1 ;
	cin >> T;
	while ( T-- ) {
		printf ( "Case #%d: %.6f\n", nCase++, solv() );
	}
	return 0;
}
