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

int TestCase , N ;
int d[1111] , p[1111] ;
vector<int> A[1111] ;
bool inQueue[1111] ;

bool bfs( int x ) {
	queue<int> Queue ;
	memset( inQueue, 0 , sizeof( inQueue ) ) ;
	while( !Queue.empty() ) {
		Queue.pop() ;
	}
	Queue.push( x ) ;
	while( !Queue.empty() ) {
		int now = Queue.front() ;
		Queue.pop() ;
		inQueue[now] = 0 ;
		for( int i = 0 ; i < A[now].size() ; i++ ) {
			int x = A[now][i] ;
			p[x] += p[now] ;
			if( p[x] > 1 ) {
				return 1 ;
			}
			if( !inQueue[x] ) {
				inQueue[x] = 1 ;
				Queue.push( x ) ;
			}
		}
	}
	return 0 ;
}
		


int main( int argc , char *argv[] )
{
	freopen( "A-large.in" , "r" , stdin ) ;
	freopen( "A-large.out" , "w" , stdout ) ;
	scanf( "%d" , &TestCase ) ;
	for( int TE = 1 ; TE <= TestCase ; TE++ ) {
		scanf( "%d" , &N ) ;
		memset( d , 0 , sizeof( d ) ) ;
		memset( p , 0 , sizeof( p ) ) ;
		for( int i = 0 ; i < N ; i++ ) {
			int x ;
			scanf( "%d" , &x ) ;
			A[i].clear() ;
			for( int j = 0 ; j < x ; j++ ) {
				int y ;
				scanf( "%d" , &y ) ;
				y-- ;
				d[y]++ ;
				A[i].push_back( y ) ;
			}
		}
		bool flag = 0 ;
		printf( "Case #%d: " , TE ) ;
		for( int i = 0 ; i < N ; i++ )
		if( !d[i] ) {
			memset( p , 0 , sizeof( p ) ) ;
			p[i] = 1 ;
			if( bfs( i ) ) {
				printf( "Yes\n" ) ;
				flag = 1 ;
				break ;
			}
		}
		if( !flag ) {
			printf( "No\n" ) ;
		}
	}
			
	return 0;
}
