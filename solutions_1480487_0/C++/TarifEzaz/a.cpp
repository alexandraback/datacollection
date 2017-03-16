#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std ; 

#define tol 1e-7
int x ; 

double myabs( double v ) {
	if ( v < 0 ) v *= -1 ;
	return v ;
}

bool isEqual( double x , double y ) {
	if ( myabs( x - y ) < tol ) return true ;
	
	return false ;
}

int getMin( int ind , vector<int> & js ) {
	int val = 0 ;
	int ret = 0 ;
	
	for ( int i = 0 ; i < js.size() ; i ++ ) {
		if ( i == ind ) continue ;
		
		if ( js[ i ] >= val ) {
			val = js[ i ] ;
			ret = i ;
		}
	}
	
	return ret ;
}

bool p( int ind , double mid , int minInd , vector<int> & js ) {
	
	double rem = 1 - mid ; 
	
	for ( int i = 0 ; i < js.size() ; i ++ ) {
		if ( i == ind ) continue ; 
		
		double lagbe = ( js[ ind ] + ( x * mid ) ) - js[ i ] ;
		
		lagbe /= x ; 
		
		if ( lagbe < 0 ) continue ; 
		
		rem -= lagbe ; 
	}
	
	if ( rem < 0 ) return true ;
	return false ;  	
/*	double scoreMe = js[ ind ] + ( (double ) x * mid ) ;
	double scoreHim = js[ minInd ] + ( ( double ) x * ( 1.0 - mid ) ) ;
	
//	cerr << " y " << scoreMe << " " << scoreHim << endl ; 
	
	if ( isEqual( scoreMe , scoreHim ) ) return true ;
	if ( scoreHim < scoreMe ) return true ;
	
	if ( js.size() == 2 ) {
		if ( scoreHim > scoreMe ) return false ; 
	}
	
	for ( int i = 0 ; i < js.size() ; i ++ ) {
		if ( i == ind ) continue ;
		if ( i == minInd ) continue ;
		
		if ( ( double ) js[ i ] < scoreMe ) {
//			cerr << "f2 " << endl ;
		 	return true ; 
		}
	}
	
	cerr << "fuck" << endl ;
	return false ;
*/
}

double getRes( int ind , vector<int> & js ) {
	
	int minInd = getMin( ind , js ) ;
	
	double lo = 0.0 ;
	double hi = 1.0 ;
	
	char fu ; 
	

	for ( int i = 0 ; i <= 5000 ; i ++ ) {
		
//		if ( lo > hi ) break ; 
				
		double mid = lo + ( hi - lo ) / 2 ;
		
//		cerr << mid << " f " << endl ;
//		cin >> fu ; 
		if ( p( ind , mid , minInd , js ) ) {
			hi = mid ;
//			cerr << "success" << endl ;
		}
		
		else {
			lo = mid  ;
//			cerr << "failure" << endl ; 
		}
		
//		cerr << lo << " " << hi << endl ;
//		cin >> fu ;  
	}
	
	return ( lo * 100.000000 )  ;
}

vector<double> solve( vector<int> &js ) {

//	cerr << x << endl ; 	
	vector<double> res ;
	
	for ( int i = 0 ; i < js.size() ; i ++ ) {
		double f_val = getRes( i , js ) ;
		
		res.push_back( f_val ) ;
	}
	
	return res ;
}

int main() {
	
	int T ; 
	
	cin >> T  ; 
	
	for ( int i = 0 ; i < T ; i ++ ) {
		
		int N ; 
		
		cin >> N ; 
		
		vector<int> js ;
		
		int s ;
		
		for ( int j = 0 ; j < N ; j ++ ) {
			cin >> s ; 
			js.push_back( s ) ;
		}		
		
		x = accumulate( js.begin() , js.end() , 0 ) ; 
				
		vector<double> res = solve( js ) ;
		
		cout << "Case #" << i + 1 << ":" ;
		
		for ( int j = 0 ; j < N ; j ++ ) {
			cout << " " ;
			printf("%.6lf",res[ j ] ) ;
		} 
		
		cout << endl ;
	}
	return 0 ;
}
