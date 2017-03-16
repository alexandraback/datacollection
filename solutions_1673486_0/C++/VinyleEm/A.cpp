#include <stdio.h>
#include <string.h>

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>

using namespace std ;
#define lint long long
#define FOREACH(it,v) for( typeof((v).begin()) it = (v).begin() ; it != (v).end() ; it++ )
#define ALL(v) (v).begin(),(v).end()

const int infinity = 0x3fffffff ;
const lint linfinity = 0x3fffffffffffffffLL ;

const int maxn = 100010 ;
double pA[ maxn] , pc[ maxn] ;

string solveASingleCase(){
	int A , B ;
	cin >> A >> B ;

	pc[0] = 1 ;
	for( int a = 0 ;a < A ; a++ ){
		cin >> pA[a] ;
		pc[a+1] = pc[a] * pA[a] ;
	}

	double ret = 1e60 ;

	for( int b = 0 ;b <= A ; b++ ){
		double ret2 = b + B-A+b + 1 + (1.0 - pc[A-b] ) * (B+1) ;
		ret = min( ret , ret2 ) ;
	}

	ret = min( ret , 2.0 + B ) ;

	char bf[32] ;
	sprintf( bf , "%.6lf" , ret ) ;
	return string( bf ) ;

}

int main(){
	int cases ;
	cin >> cases ;

	for( int cs = 1 ; cs <= cases ; cs++ ){
		cout << "Case #" << cs << ": " << solveASingleCase() << endl ;
	}

	return 0 ;
}
