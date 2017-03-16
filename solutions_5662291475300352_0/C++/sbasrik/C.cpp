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

lint id,test,n,sz;
pll h[mxn];

void read(){
	
	lint d,s,m;
	cin>>n;
	for( lint i=1 ; i<=n ; i++ ){
	
		cin>>d>>s>>m;
		for( lint j=0 ; j<s ; j++ )	h[++sz] = mp( d,m+j );
	
	}
	
	return;
	
}

lint check(){
	
	if( h[1].nd > h[2].nd )	swap( h[1] , h[2] );
	
	double t1 = (360-h[1].st)*h[1].nd/360.0;
	double t2 = (360-h[2].st)*h[2].nd/360.0;
	
	if( fabs( h[1].st - h[2].st ) > 1e-9 && h[1].st < h[2].st ){
	
		if( t2 < t1 )	return 0;
		
		if( fabs( h[1].st - (t2-t1) ) <= 1e-9 || h[1].nd <= t2-t1 )	return 1;
		else return 0;		
		
	}
	else{
		
		if( fabs( h[1].st - (t2-t1) ) <= 1e-9 || h[1].nd <= t2-t1 )	return 1;
		else return 0;	
		
	}
	
	return 0;
		
}

int main(){
	
		freopen( "input.in" , "r" , stdin );
		freopen( "out.txt" , "w" , stdout );
	
	lint ans;
	cin>>test;
	
	for( id=1 ; id<=test ; id++ ){	
	
		sz = 0;
		read();
		
		if( sz<=1 )		ans = 0;
		else			ans = check();
		
		printf( "Case #%lld: %lld\n" , id , ans );
		
	}
	
	return 0;
}
