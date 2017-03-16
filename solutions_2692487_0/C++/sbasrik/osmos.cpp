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

int id,test,n,a;
int dp[105][mxn];
int vis[105][mxn],v;
int ar[mxn];

void read(){
//	freopen( ".in" , "r" , stdin );
//	freopen( ".out" , "w" , stdout );
	scanf( "%d %d" , &a , &n );
	for( int i=1 ; i<=n ; i++ )		scanf( "%d" , ar+i );
	return;
}

int find( int ind,int s ){

	if( s>ar[n] || ind>n )	return 0;

	int &ans = dp[ind][s];

	if( vis[ind][s]==v )	return ans;
	vis[ind][s] = v;

	if( s>ar[ind] )	return ans = find( ind+1,MIN( 1e6+1 , s+ar[ind] ) );
	else
		if( s==1 )	return ans = n-ind+1;
		else		return ans = min( find( ind, MIN( s+s-1 , 1e6+1 ) )+1 , n-ind+1 );

}

void solve(){

	scanf( "%d" , &test );

	for( id=1 ; id<=test ; id++ ){

		read();
		sort( ar+1,ar+n+1 );

		v++;

		printf( "Case #%d: %d\n" , id , find( 1,a ) );

	}

	return;
}

int main(){
	solve();
	return 0;
}
