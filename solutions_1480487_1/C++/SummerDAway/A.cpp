//------------------------------------------------------------------------------
//  Problem : 
//  User    : 
//  Date    : 
//------------------------------------------------------------------------------


#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

struct Node {
	int x , y ;
} A[300] ;

int N , X ;
double Ans[300] ;
int TestCase ;


bool cmp( const Node &a , const Node &b ) {
	return a.x < b.x ;
}

void work( int x ) {
	double q = 0 ;
	for( int i = 0 ; i < x ; i++ ) {
		q = q + ( A[x].x - A[i].x ) * 1.0 / X ;
	}
	if( q > 1 ) {
		return ;
	}
	double p = 0 ;
	for( int i = x + 1 ; i < N ; i++ ) {
		while( A[i].x == A[i-1].x ) {
			i++ ;
		}
		if( i == N ) {
			break ;
		}
		q = q + ( A[i].x - A[i-1].x ) * 1.0 / X * ( i ) ;
		
		p = p + ( A[i].x - A[i-1].x ) * 1.0 / X ;
		if( q > 1 ) {
			q = q - ( A[i].x - A[i-1].x ) * 1.0 / X * i ;
			Ans[A[x].y] = ( 1 - q ) / i ;
			if( i > x ) {
				Ans[A[x].y] = Ans[A[x].y] + ( A[i-1].x - A[x].x ) * 1.0 / X ;
			}
			return ;
		}
	}
	Ans[A[x].y] = ( 1 - q ) / N + ( A[N-1].x - A[x].x ) * 1.0/X ;
	return ;
}
	
		
		

int main( int argc , char *argv[] )
{
	freopen( "A-large.in" , "r" , stdin ) ;
	freopen( "A-large.out" , "w" , stdout ) ;
	
	scanf( "%d" , &TestCase ) ;
	for( int TE = 0 ; TE < TestCase ; TE++ ) {
		scanf( "%d" , &N ) ;
		X = 0 ;
		for( int i = 0 ; i < N ; i++ ) {
			scanf( "%d" , &A[i].x ) ;
			Ans[i] = 0 ;
			X = X + A[i].x ;
			A[i].y = i ;
		}
		sort( A , A + N , cmp ) ;
		for( int i = 0 ; i < N ; i++ ) {
			work( i ) ;
		}
		printf( "Case #%d: " , TE + 1 ) ;
		for( int i = 0 ; i < N ; i++ ) {
			printf( "%.6lf" , Ans[i] *100 ) ;
			printf( i == N - 1 ? "\n" : " " ) ;
		}
	}
	
	return 0;
}
