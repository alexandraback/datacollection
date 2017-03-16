#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std ;

double C , F , X ;
int TestCase ;

int main( int agrv, char* argc[] ) {
	freopen( "B.in" , "r" , stdin ) ;
	freopen( "B.out" , "w" , stdout ) ;
	scanf( "%d" , &TestCase ) ;
	for( int TC = 1 ; TC <= TestCase ; TC++ ) {
		scanf( "%lf%lf%lf" , &C , &F , &X ) ;
		double speed = 2.0 ;
		double ans = 0 , ans1 ;
		while( (ans1 = X/speed) > (C/speed) + (X/(speed+F) ) ) {
			ans += C/speed ;
			speed += F ;
		}
		ans += X/speed ;
		printf( "Case #%d: %.7lf\n" , TC , ans ) ;
	}
	return 0 ;
}



