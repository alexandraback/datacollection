#pragma comment(linker, "/STACK:16777216")

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<string>
#include<utility>
#include<algorithm>
#include<list>
using namespace std;

#define pb push_back
#define MS( a ) memset( a,0,sizeof(a))
#define MSV( a,v ) memset( a,v,sizeof(a))

#define MAX 107

struct DATA{
	long r,c;
	double d;
	DATA( long r = 0,long c = 0,double d )
	{
		this->r = r;
		this->c = c;
		this->d = d;
	}
};


bool operator<( const DATA &a,const DATA &b )
{
	return a.d > b.d;
}


long H;
long Row,Col;
long Cl[MAX+7][MAX+7];
long Fl[MAX+7][MAX+7];
bool St[MAX+7][MAX+7];
bool Visit[MAX+7][MAX+7];
double Dist[MAX+7][MAX+7];

long IR[] = { 0,-1,0,1 };
long IC[] = { 1,0,-1,0 };

double Ans;


bool IsPos( long r1,long c1,long r2,long c2,double t )
{
	if( Cl[r2][c2] - Fl[r2][c2] < 50 ) return false;
	double Cl1 = Cl[r1][c1];
	double Fl1 = max( (double)Fl[r1][c1],H-t*10 );
	double Cl2 = Cl[r2][c2];
	double Fl2 = max( (double)Fl[r2][c2],H-t*10 );
	if( Cl1-Fl2 < 50 ) return false;
	if( Cl2-Fl1 < 50 ) return false;
	return true;
}

inline double WLevel( long r,long c ,double t )
{
	return max( 0.0,H-10*t - Fl[r][c] );
}

 
bool Dijk( double t,bool b = false )
{
	priority_queue<DATA> pq;
	MS( Visit );
	long i,j;
	for( i=1;i<=Row;i++ ){
		for( j=1;j<=Col;j++ ){
			if( St[i][j] ){
				pq.push( DATA( i,j,t ));
			}
		}
	}
	while( !pq.empty()){
		DATA Nw = pq.top();
		pq.pop();
		if( Visit[Nw.r][Nw.c] ) continue;
		Visit[Nw.r][Nw.c] = true;
		if( Nw.r==Row && Nw.c==Col ){
			Ans = min( Ans,Nw.d );
			return true;
		}
		for( i=0;i<4;i++ ){
			long nr = Nw.r+IR[i];
			long nc = Nw.c+IC[i];
			if( nr<1 || nr>Row || nc<1 || nc>Col ) continue;
			if( Visit[nr][nc] ) continue;
			if( !IsPos( Nw.r,Nw.c,nr,nc,Nw.d )) continue;//if( b ) printf("here\n");
			if( WLevel( Nw.r,Nw.c,Nw.d ) >= 20 ) pq.push( DATA( nr,nc,Nw.d+1 ));
			else pq.push( DATA( nr,nc,Nw.d+10 ));
		}
	}
	return false;
}


	
void Dfs( long r,long c )
{
	St[r][c] = true;
	long i;
	for( i=0;i<4;i++ ){
		long nr = r+IR[i];
		long nc = c+IC[i];
		if( nr<1 || nr>Row || nc<1 || nc>Col ) continue;
		if( St[nr][nc] ) continue;
		if( !IsPos( r,c,nr,nc,0 )) continue;
		Dfs( nr,nc );
	}
}

double BS( double l,double r,long c )
{
	if( !c ) return l;
	double m = (l+r)/2;
	if( Dijk( m )) return BS( l,m,c-1 );
	else return BS( m,r,c-1 );
}
	
int main( void )
{
    long i,j,Icase,k = 0;
    
    freopen("b.in","r",stdin );
    freopen("b.out","w",stdout );
    
    scanf("%ld",&Icase );
    while( Icase-- ){
		scanf("%ld%ld%ld",&H,&Row,&Col );
		for( i=1;i<=Row;i++ ){
			for( j=1;j<=Col;j++ ){
				scanf("%ld",&Cl[i][j] );
			}
		}
		for( i=1;i<=Row;i++ ){
			for( j=1;j<=Col;j++ ){
				scanf("%ld",&Fl[i][j] );
			}
		}
		
		MS( Visit );
		MS( St );
		Dfs( 1,1 );
		if( St[Row][Col] ){
			printf("Case #%ld: 0.0\n",++k );
			continue;
		}
		
		Ans = 1000000000000.0;
		double Init = BS( 0,100000000000.0,400 );//printf("%lf\n",Init );
		//Dijk( Init,true );
		//double Ans = Init+Dist[Row][Col];
		printf("Case #%ld: %.10lf\n",++k,Ans );
		
	}									
		
	//scanf("%*ld");

    return 0;
}
