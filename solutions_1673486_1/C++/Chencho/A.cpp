#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 100005

int N, W ;
double prob[lim] ;

double procA() {
	double a=1.0, b=1.0 ;
	
	for( int i=0; i<N; i++ ) 
		a *= prob[i] ;
	b = 1.0-a ;
	a *= W-N+1.0 ;
	b *= W-N+2.0 + W ;
	return a+b ;
}

double procC() {
	return (W+2)*1.0 ;
}

double procB() {
	double res = 1.0*(1<<30), carga=1.0, tmp ;
	
	for( int i=0; i<N; i++ ) {		
		tmp = 1.0-carga ;
		res = min( res, carga*(   N-i+W-i+1   ) + tmp*(   N-i+W-i+1    +    W+1   )   ) ;
		//printf("->%lf %lf --->>> %lf\n", carga*(   N-i+W-i+1   ),  tmp*(   N-i+W-i+1    +    W+1   ),   carga*(   N-i+W-i+1   ) + tmp*(   N-i+W-i+1    +    W+1   )  ) ;
		
		carga *= prob[i] ;
	}
	
	return res ;
}

double caso() {
	scanf("%d%d", &N, &W ) ;
	for( int i=0; i<N; i++ )
		scanf("%lf", &prob[i] ) ;
	//printf("%lf %lf %lf\n", procA(), procB(), procC() ) ;
	return min(  min(procA(), procB()), procC() ) ;
}

int main() {
	int T ;
	
	scanf("%d", &T ) ;
	for( int i=1; i<=T; i++ ) 
		printf("Case #%d: %.6lf\n", i, caso() ) ;
	
	return 0 ;
}
