#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <sstream>

using namespace std ; 

#define imax 1023456789
#define vi vector<int>
#define vvi vector< vi >
#define vb vector<bool>
#define pi pair<int,int>
#define tol 1e-6

vvi edges ; 
int cap[ 202 ][ 202 ] ;
int flow[ 202 ][ 202 ] ;

void printResult( int cas , string & res ) {
	cout << "Case #" << cas << ": " << res << endl ;
}


int path( int source , int sink ) {

//	cerr << "mama" << cap[ 3 ][ 6 ] << endl ;
//	cerr << source << " H " << sink << endl ;
	int N = edges.size() - 1 ;
	
	vector<bool> visited( ( 2 * N ) + 2 , false ) ;
	vector<int> priv( ( 2 * N ) + 2 , -1 ) ;
	int mx = ( 2 * N ) + 2 ;
	
	visited[ source ] = true ;
	
	
	queue<int> q ; 
	q.push( source ) ;
	
	bool done = false ;
	
	while ( !q.empty() && !done ) {
		int cur = q.front() ; q.pop() ; 
		
//		cerr << cur << " fuck " << endl ;
		
		for ( int i = 0 ; i < mx ; i ++ ) {
			if ( visited[ i ] == false && cap[ cur ][ i ] > 0 ) {
				visited[ i ] = true ;
				priv[ i ] = cur ;
				q.push( i ) ;
				
				if ( i == sink ) {
					done = true ;
					break ;
				}
			}
		}
	}
	
//	cerr << "why " << done << endl ;
//	cerr << "here" << endl ;
	if ( done == false ) return 0 ;
	
	int mins = imax ;
	
	int nxt = sink ; 
	
	while( true ) {
		int pr = priv[ nxt ] ;
//		cerr << pr << endl ;
		
		if ( pr == -1 ) break ;
		
		mins = min( mins , cap[ pr ][ nxt ] ) ;
		
		nxt = pr ;
	}
	
	nxt = sink ; 
	
	while ( true ) {
		int pr = priv[ nxt ] ;
		
		if ( pr == -1 ) break ;
		
		cap[ pr ][ nxt ] -= mins ;
		cap[ nxt ][ pr ] += mins ;
		flow[ pr ][ nxt ] += mins ;
		flow[ nxt ][ pr ] -= mins ;
		
		nxt = pr ; 
	}
	
	if ( done ) return true ; 
	 
}


bool flowEm( int source , int sink ) {
	memset( cap , 0 , sizeof( cap ) ) ;
	memset( flow , 0 , sizeof( flow ) ) ;
	
	int N = edges.size() - 1 ;
	
	int superSink = ( 2 * N ) + 1 ;
	 
	
	cap[ 0 ][ source ] = 2 ;
	cap[ sink ][ sink + N ] = imax ;
	cap[ sink + N ][ superSink ] = 2 ;
	
	for ( int i = 1 ; i <= N ; i ++ ) {
		int mycap = edges[ i ].size() ; 
		
		if ( i == sink ) continue ;
		
		cap[ i ][ i + N ] = mycap ;
	}
	
	for ( int i = 1 ; i <= N ; i ++ ) {
		for ( int j = 0 ; j < edges[ i ].size() ; j ++ ) {
			int from = i ;
			int to = edges[ i ][ j ] ;
			
			cap[ i + N ][ to ] += 1 ;
		}
	}
	
	int tot = 0 ;
	
	
	while ( true ) {
		if ( path( 0 , superSink ) ) tot ++ ;
		else break ;
		
		if ( tot >= 2 ) return true ;
	}
	
/*	if ( source == 1 && sink == 3 ) {
		cerr << superSink << endl ;
		cerr << tot << "fu" << endl ;
	}
*/
	return false ;
}


string solve() {
	
	int N = edges.size() - 1; 
	
//	flowEm( 1 , 3 ) ;
	for ( int i = 1 ; i <= N ; i ++ ) {
		for ( int j = 1 ; j <= N ; j ++ ) {
			if ( i == j ) continue ; 
			
			bool res = flowEm( i , j ) ; 
			
			if ( res ) return "Yes" ;
		}
	}
	
	return "No" ; 
}

int main() {
	
	int T ; 
	
	cin >> T ; 
	
	int N ;
	
	for ( int i = 0 ; i < T ; i ++ ) {
		cin >> N ; 
		
		edges = vvi ( N + 1 ) ; 
		
		for ( int j = 0 ; j < N ; j ++ ) {
			int M ; 
			
			cin >> M ; 
			
			int m ;
			
			for ( int k = 0 ; k < M ; k ++ ) {
				cin >> m ; 
							
				edges[ j + 1 ].push_back( m ) ;
			}
		}
		
		string res = solve( ) ;
		printResult( i + 1 , res ) ;
	}
	return 0 ;
}
