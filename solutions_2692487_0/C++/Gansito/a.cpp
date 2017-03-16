#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<memory.h>
#include<limits.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<utility>
#include<sstream>
#include<vector>
#include<bitset>
#include<queue>
#include<stack>
#include<set>
#include<map>

#define forit(i,v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define fori(i,a,b) for( int i = (int)(a); i < (int)(b); i++ )
#define forn(i,n) fori(i,0,n)
#define zeros(a) memset(a,0,sizeof(a))
#define null(a) memset(a,-1,sizeof(a))
#define all(a) (a).begin() , (a).end()
#define sqr(a) ((a)*(a))
#define sz(a) (a).size()
#define R(a) scanf("%d",&(a))
#define W(a) printf("%d\n",(a))
#define E(a) cout << (a) << endl
#define L(a) cin >> (a)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii 2*acos(0.0)
#define N 102

using namespace std;

typedef long long int i64;
typedef pair<int,int> ii;
typedef vector <int> vi;

int a[ N ], ans, cnt , n , T;

int solve( int m , int p ){
	if( p == n ) return 0;
	if( a[ p ] < m ) return solve(  m + a[p] , p + 1 );
	if( m == 1 ) return 1 + solve( m , p + 1 );
	int op1 , op2, st = 0;
	op1 = 1 + solve( m , p + 1 );
	do{
		st++;
		m += m - 1;
	}while( m <= a[ p ] );
	op2 = st + solve( m + a[ p ] , p + 1 );
	return min( op1 , op2 );
}

int main(){
	R( T );
	fori( k , 1 , T + 1 ){
		ans = 0;
		R( cnt ); R(n);
		forn( i , n ) R( a[ i ] );
		sort( a , a + n );
		printf("Case #%d: %d\n" , k , solve( cnt , 0 ) );
	}
	return 0;
}
