#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <numeric>

#define repn( i , a , b ) for( int i = ( int ) a ; i < ( int ) b ; i ++ )
#define rep( i , n ) repn( i , 0 , n ) 
#define all( x )  x.begin() , x.end()
#define rall( x ) x.rbegin() , x.rend()
#define mp make_pair
#define fst first
#define snd second
using namespace std;

typedef long long int64;
typedef long double ldouble;
typedef pair< int , int > pii;
ldouble eps = 1e-12;

ldouble J[ 1000 ];
ldouble X ,gchica , Grande ;
int N;

bool puede( ldouble target  , int id ){
	ldouble queda = 1 - target;
	ldouble Pi = X * target + J[ id ];
	rep( i , N ) if( i != id ) {
		ldouble mini = ( Pi - J[ i ] ) / X;
		queda -= mini;
		if( queda < 0.0 ) return false;
	}
	if( queda == 0 ) return false;
	return true;
}

ldouble solve( int i ){
	ldouble ans = J[i] > Grande ? 0 : ( gchica - J[i] ) / X;	
	return ans;
}

void solve_gen(){
	cin >> N;
	rep( i , N ) cin >> J[ i ];
	X = 0;
	rep( i , N ) X += J[ i ];
	Grande = ( 2.0 * X ) / (ldouble)( N );
	ldouble nsum = X;
	int k = N;
	rep( i , N ) if ( J[ i ] > Grande ){ k-- ; nsum -= J[ i ]; }
	gchica = ( nsum + X ) / k;
	rep( i , N ) printf( " %.6Lf" , solve( i ) * 100.0 );
	printf("\n");
}

int main(){
	int test;
	cin >> test;
	repn( i , 1 , test + 1 ){
		cout << "Case #" << i << ":";
		solve_gen();
	}
	return 0;
}

