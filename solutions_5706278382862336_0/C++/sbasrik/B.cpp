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


lint p,q;

void read(){

char c;

	cin>>p;
	scanf( "%c" , &c );
	cin>>q;
	
	return;

}

void solve(){
	
	lint g,i,ans;
	
	g = __gcd( p,q );
	p /= g;
	q /= g;
	
	lint mask = 1LL;
	for( i=0 ; i<50 ; i++,mask<<=1 )
	if( mask==q )	break;
	
	if( i==50 ){
		
		puts( "impossible" );
		return;
		
	}
	
	double t=1.0;
	double d = p;
	d /= q;
	
	for( ans = 0 ; ; ans++ )
	if( t<=d )	break;
	else 		t /= 2.0;
	
	cout<<ans<<endl;
	return;
	
}

int main(){
	
		freopen( "input.in" , "r" , stdin );
		freopen( "output.out" , "w" , stdout );
	
	lint test,id;
	cin>>test;
	for( id=1 ; id<=test ; id++ ){
		read();
		cout<<"Case #"<<id<<": ";
		solve();
	}
	return 0;
}
