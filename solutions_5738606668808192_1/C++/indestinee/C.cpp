/*
 *	Author:
 *		Indestinee
 *	Date:
 *		2016/04/09
 */
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int M = 1e6;
int cas, n, m, tot, prime[M+1], vis[M+1];
const long long inf = 1e18;
const int maxn = 10, base = 10000;
class bignum{
public:
	int d[maxn];
	bignum(int x=0){
		memset( d , 0 , sizeof d );
		do{
			d[++d[0]] = x % base;
			x /= base;
		}while( x );
	}
	friend bool operator < ( const bignum &a , const bignum &b ){
		if( a.d[0] != b.d[0] )
			return a.d[0] < b.d[0];
		for( int i = a.d[0] ; i ; i -- )
			if( a.d[i] != b.d[i] )
				return a.d[i] < b.d[i];
		return false;
	}
	friend bignum operator + ( const bignum &a , const bignum &b ){
		bignum c;
		c.d[0] = max( a.d[0] , b.d[0] );
		int x = 0;
		for( int i = 1 ; i <= c.d[0] ; i ++ ){
			x += a.d[i] + b.d[i];
			c.d[i] = x % base;
			x /= base;
		}
		while( x ){
			c.d[++c.d[0]] = x % base;
			x /= base;
		}
		return c;
	}
	friend bignum operator * ( const bignum &a , const int &k ){
		bignum c;
		c.d[0] = a.d[0];
		int x = 0;
		for( int i = 1 ; i <= a.d[0] ; i ++ ){
			x += a.d[i] * k;
			c.d[i] = x % base;
			x /= base;
		}
		while( x ){
			c.d[++c.d[0]] = x % base;
			x /= base;
		}
		return c;
	}
	friend int operator % ( const bignum &a , const int &k ){
		long long res = 0;
		for( int i = a.d[0] ; i ; i -- )
			res = ( res * base + a.d[i] ) % k;
		return (int)res;
	}
	void out(){
		printf( "%d" , d[d[0]] );
		for( int i = d[0] - 1 ; i ; i -- )
			printf( "%04d" , d[i] );
		putchar( '\n' );
	}
}zero, bprime[M];
void get_prime(){
	for( int i = 2 ; i <= M ; i ++ ){
		if( !vis[i] )
			prime[++tot] = i, bprime[tot] = bignum( i );
		for( int j = 1 ; j <= tot && prime[j] * i <= M ; j ++ ){
			vis[prime[j]*i] = 1;
			if( i % prime[j] == 0 )
				break;
		}
	}
}
char s[555][55];
int a[555][11];
int doit( long long a , const int &b ){
	bignum base = bignum(1), num;
	while( a ){
		num = num + ( ( a & 1LL ) ? base : zero );
		a >>= 1;
		base = base * b;
	}
	for( int i = 1 ; i <= tot && bprime[i] < num ; i ++ )
		if( num % prime[i] == 0 )
			return prime[i];
	return 0;
}
bool get( const int &n , const int &m ){
	long long st = 1LL << ( n - 1 ) | 1;
	long long ed = ( 1LL << n );
	int cnt = 0, x;
	for( long long i = st ; i < ed ; i += 2LL ){
		bool ok = true;
		for( int j = 2 ; j <= 10 ; j ++ ){
			if( ( x = doit( i , j ) ) )
				a[cnt][j] = x;
			else{
				ok = false;
				break;
			}
		}
		if( ok ){
			for( int k = 0 ; k < n ; k ++ )
				s[cnt][k] = ( ( i >> ( n - 1 - k ) ) & 1 ) + '0';
			s[cnt][n] = '\0';
			if( ( ++ cnt ) == m )
				return true;
		}
	}
	return false;
}
int main(){
	freopen( "C-large.in"  , "r" , stdin  );
	freopen( "C-large.out" , "w" , stdout );
	get_prime();
	scanf( "%d" , &cas );
	for( int T = 1 ; T <= cas ; T ++ ){
		scanf( "%d%d" , &n , &m );
		
		printf( "Case #%d:\n" , T );
		if( get( n , m ) ){
			for( int i = 0 ; i < m ; i ++ ){
				printf( "%s " , s[i] );
				for( int j = 2 ; j <= 10 ; j ++ )
					printf( "%d%c" , a[i][j] , j == 10 ? '\n' : ' ' );
			}
		}else
			puts( "-1" );
	}
	return 0;
}
