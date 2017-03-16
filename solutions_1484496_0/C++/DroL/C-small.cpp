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
#define MAXN 1000
using namespace std;

typedef long long int64;
typedef long double ldouble;
typedef pair< int , int > pii;

int e[ MAXN ];
map< int , int > hash;
int N;

void print( int mask ){
	int p = 1;
	rep( i , N ) if(mask &( 1<< i ) ){
		if( p ) p = 0;
		else	printf(" ");
		printf("%d" , e[ i ] );
	}
	printf("\n");
}

void solve(){
	cin >> N;
	hash.clear();
	rep( i , N ) cin >> e[ i ];
	rep( i , ( 1 << N ) ){
		int sum = 0;
		rep( j , N ) if( i & ( 1 << j ) ) sum += e[ j ];
		if( hash.count( sum ) ){
			print( i );
			print( hash[ sum ] );
			return;
		}
		hash[ sum ] = i;
	} 
	printf("Impossible\n");
}

int main(){
	int test;
	cin >> test;
	repn( i , 1 , test + 1 ){
		printf("Case #%d:\n" , i );
		solve();
	}
	return 0;
}

