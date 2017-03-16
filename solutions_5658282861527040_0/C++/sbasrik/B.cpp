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
#define mxn       	1005
using namespace std;

int id,test;
int a,b,k;

void read(){

	scanf( "%d %d %d" , &a , &b , &k );
	return;

}

void solve(){
	
	int i,j;
	
	int ans = 0;
	
	for( i=0 ; i<a ; i++ )
	for( j=0 ; j<b ; j++ )
	if( (i&j)<k )	ans++;
	
	printf( "%d\n" , ans );
	
	return;
	
}

int main(){
	
		freopen( "input.txt" , "r" , stdin );
		freopen( "output.txt" , "w" , stdout );
	
	scanf( "%d" , &test );
	for( id=1 ; id<=test ; id++ ){
		read();
		printf( "Case #%d: " , id );
		solve();
	}
	return 0;
}
