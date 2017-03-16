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
#define MAXN 100010
using namespace std;

typedef long long int64;
typedef long double ldouble;
typedef pair< int , int > pii;

int A , B;
double win[ MAXN ];
double acum[ MAXN ];

double caso_1(){
	double win_keys = B - A + 1;
	double fail_keys = B - A + 1 + B + 1;
	double ans = win_keys * acum[ A ] + fail_keys * ( 1.0 - acum[ A ] ); 
//	cout << 1 << " " << ans << endl;
	return ans;
}

double caso_3(){
	double ans =  1.0 + 1.0*B + 1.0;
//	cout << 3 << " " << ans << endl;
	return ans;
}

double solve_case( int borrados ){
	int quedan = A - borrados;
	double win_keys = borrados + B - quedan + 1;
	double fail_keys = borrados + B - quedan + 1 + 1 + B;
	double ans = win_keys * acum[ quedan ] + fail_keys * ( 1.0 - acum[ quedan ] ); 
//	cout << 2 << " " << borrados << " " << ans << endl;
	return ans;
} 

double caso_2(){
	double ans = -1.0;
	repn( i , 1 ,  A + 1 ){
		double tmp = solve_case( i );
		if( ans < 0 or ans > tmp ) ans = tmp;
	}
	return ans;
}

double solve(){
	cin >> A >> B;	
	double ans = 0;
	rep( i , A ) cin >> win[ i ];
	acum[ 0 ] = 1.0;
	rep( i , A ) acum[ i + 1 ] = acum[ i ] * win[ i ];
	ans = min( caso_1() , caso_3() );
	ans = min( ans , caso_2() );
	return ans;
}

int main(){
	int test;
	cin >> test;
	repn( tcase , 1 , test + 1 ){
		double ans = solve();
		printf("Case #%d: %.10lf\n", tcase , ans );
	}
	return 0;
}

