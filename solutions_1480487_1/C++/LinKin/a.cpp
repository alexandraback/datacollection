#include<stdio.h>
#include<string.h>
#include<iostream>
#include<map>
using namespace std;

#define MAX 207

long N;
long Pt[MAX+7];
long Sum;

bool IsPos( long I,double m )
{
	double p = Pt[I] + Sum*m;
	long i;
	double v = 0;
	for( i=1;i<=N;i++ ){
		if( i==I ) continue;
		if( p < Pt[i] ) continue;
		v += (p-Pt[i])/Sum;
	}
	if( v+m <=1 ) return false;
	else return true;
}

double BS( long I,double l,double r,long c )
{
	if( !c ) return (l+r)/2;
	double m = (l+r)/2;
	if( IsPos( I,m )) return BS( I,l,m,c-1 );
	else return BS( I,m,r,c-1 );
}


int main( void )
{
	long i,Icase,k = 0;
	
	freopen("A.in","r",stdin );
	freopen("A.out","w",stdout );

	scanf("%ld",&Icase );
	while( Icase-- ){
		scanf("%ld",&N );
		Sum = 0;
		for( i=1;i<=N;i++ ){
			scanf("%ld",&Pt[i] );
			Sum += Pt[i];
		}
		printf("Case #%ld:",++k );
		for( i=1;i<=N;i++ ){
			double Ans = BS( i,0,1,200 )*100;
			printf(" %.10lf",Ans );
		}
		printf("\n");
	}
	
	//scanf("%*ld");

	return 0;
}
