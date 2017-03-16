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
#define ek 			10000
using namespace std;

int id,test,n,x,y;
int yon[5][2] = { {0,0},{0,1},{1,0},{-1,0},{0,-1} };
int merkez[20005][10005];
int mat[20005][10005];
double ans,p;

void mark( int xx,int yy,int r ){

	if( r==1 )	merkez[xx][yy] = 1;
	else		merkez[xx][yy] = 0;
	for( int k=0 ; k<5 ; k++ )	mat[ xx+yon[k][0] ][ yy+yon[k][1] ] += r;
	return;

}

void rec( int ind,int xx,int yy,double p){
/*
	cout<<mat[1+ek][0]<<endl;
	cout<<ind<<" "<<xx<<" "<<yy<<"   ";
	printf( "%.10lf\n" , p );
	wait;
*/
	if( ind==n+1 ){
		if( merkez[x+ek][y] )	ans += p;
		return;
	}

	if( yy==0 ){
		mark( xx+ek,yy,1 );
		rec( ind+1,0,n+2,p );
		mark( xx+ek,yy,-1 );
		return;
	}

	int l,r,d;

	l = mat[xx-1+ek][yy-1];
	r = mat[xx+1+ek][yy-1];
	d = mat[xx+ek][yy-1];

	if( !d ){
		rec( ind,xx,yy-1,p );
		return;
	}

	if( l && r ){
		mark( xx+ek,yy,1 );
		rec( ind+1,0,n+2,p );
		mark( xx+ek,yy,-1 );
	}

	if( !l && !r ){
		rec( ind,xx-1,yy-1,p/2.0 );
		rec( ind,xx+1,yy-1,p/2.0);
	}

	if( !l && r )	rec( ind,xx-1,yy-1,p );
	if( l && !r )	rec( ind,xx+1,yy-1,p );

	return;

}

void solve(){

	scanf( "%d" , &test );

	for( id=1 ; id<=test ; id++ ){

		scanf( "%d %d %d" , &n , &x , &y );

		ans = 0;
		rec( 1,0,n+2,1.0 );

		printf( "Case #%d: %.10lf\n" , id , ans );

	}

	return;
}

int main(){
	solve();
	return 0;
}
