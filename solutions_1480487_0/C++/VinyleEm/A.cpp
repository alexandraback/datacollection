#include <iostream>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std ;

const int maxn = 205 ;
const double eps = 1e-10 ;

int n , P[maxn] ;

double solve2( vector<int>& vp , double yl , int X ){
	int m = vp.size() ;
	if( m == 0 or X == 0 ) return 0 ;

	double lo = 0 , hi = 1e80 ;

	for( ; hi - lo > eps ; ){
		double v = ( lo + hi ) * 0.5 ;

		double ys = 0 ;
		for( int i = 0 ;i < m ; ++i )
			if( vp[i] + eps < v ){
				ys += ( v - vp[i] ) / X ;
			}

		if( ys < eps + yl ) lo = v ;
		else hi = v ;
	}

	return ( lo + hi ) * 0.5 ;

}

double solve( int a , int X ){

	double lo = 0 , hi = 1.0 ;

	vector<int> v ;
	for( int u = 0 ; u < n ; ++u )
		if(u != a )
			v.push_back( P[u] ) ;

	for( ; hi-lo > eps ; ){
		double y = ( lo + hi ) * 0.5  ;
		double Pa = P[a] + y * X ;

		if( Pa + eps >= solve2( v , 1.0 - y , X ) ){
			hi = y ;
		}
		else{
			lo = y ;
		}

	}

	return 50 * ( lo + hi ) ;

}

string format( double v ){
	char bf[64] ;
	sprintf( bf , "%.6lf" , v ) ;

	return string(bf) ;
}

int main(){
	int nCases ;
	cin >> nCases ;

	for( int cs = 1 ; cs <= nCases ; cs++ ){
		cin >> n ;

		int X = 0 ;
		for( int i = 0 ; i < n ; ++i ){
			cin >> P[i] ;
			X += P[i] ;
		}

		cout << "Case #" << cs << ":" ;

		for( int i = 0 ;i < n ; ++i ){
			cout << " " << format( solve( i , X ) ) ;
		}

		cout << endl ;
	}

	return 0 ;
}
