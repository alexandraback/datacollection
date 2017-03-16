#include<iostream>
#include<fstream>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<list>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<climits>
#include<ctime>
#include<sstream>
#define mp       	make_pair
#define pb       	push_back
#define st       	first
#define nd       	second
#define wait     	getchar();getchar();
#define lint     	long long
#define KARE(a)	 	( (a)*(a) )
#define MAX(a,b) 	( (a)>(b) ? (a) : (b) )
#define MIN(a,b) 	( (a)<(b) ? (a) : (b) )
#define MAX3(a,b,c)	( MAX( a,MAX(b,c) ) )
#define MIN3(a,b,c)	( MIN( a,MIN(b,c) ) )
#define FILL(ar,a)	memset( ar,a,sizeof ar )
#define oo	 		1e9
#define pii       	pair<int,int>
#define pll			pair<lint,lint>
#define pdd			pair<double,double>
#define y1			yy1
#define eps      	(1e-9)
#define esit(a,b)  	( abs( (a)-(b) ) < eps )
#define sol(a)		( (a)<<1 )
#define sag(a)		( sol(a)|1 )
#define orta(a,b)	( ( (a)+(b) )>>1 )
#define mxn       	1000005
using namespace std;

lint n;
lint dp[mxn];

lint reverse( lint s ){

	lint ret = 0;
	
	while( s ){
	
		ret = 10*ret + s%10;
		s = s/10;
	}
	
	return ret;
}

int main(){
		freopen( "input.in" , "r" , stdin );
		freopen( "out.txt" , "w" , stdout );
	
	int test;
	memset( dp,61,sizeof dp );
	
	dp[1] = 1;
	for( int i=1 ; i<1000000 ; i++ ){
	
		dp[i+1] = min( dp[i+1] , dp[i]+1 );
		
		lint t = reverse( i );
		if( t<=1000000 )
			dp[t] = min( dp[t] , dp[i]+1 ); 
	}
	
	scanf( "%d" , &test );
	
	for( int i=1 ; i<=test ; i++ ){
	
		scanf( "%d" , &n );
		printf( "Case #%d: %lli\n" , i , dp[n] );
	}
	return 0;
}
