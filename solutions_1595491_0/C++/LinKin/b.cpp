#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 107

long N,S,p;
long Pt[MAX+7];
long Surp[MAX+7];
long Norm[MAX+7];
bool Visit[MAX+7][MAX+7];
long Val[MAX+7][MAX+7];

long Find( long n,long s )
{
	if( Visit[n][s] ) return Val[n][s];
	Visit[n][s] = true;
	Val[n][s] = 0;
	if( s ){
		if( Surp[Pt[n]] >= p ) Val[n][s] = max( Val[n][s],1+Find( n-1,s-1 ));
		else Val[n][s] = max( Val[n][s],Find( n-1,s-1 ));
	}
	if( n>s ){
		if( Norm[Pt[n]] >= p ) Val[n][s] = max( Val[n][s],1+Find( n-1,s ));
		else Val[n][s] = max( Val[n][s],Find( n-1,s ));
	}
	return Val[n][s];
}

int main( void )
{
	long i,j,a,b,c,Icase,k = 0;
	
	freopen("Bin.txt","r",stdin );
	freopen("Bout.txt","w",stdout );
	
	for( a=0;a<=10;a++ ){
		for( b=a;b<=10;b++ ){
			if( b-a > 2 ) break;
			for( c=b;c<=10;c++ ){
				if( c-b > 2 || c-a > 2 ) break;
				if( b-a==2 || c-a==2 || c-b==2 ) Surp[a+b+c] = max( Surp[a+b+c],c );
				else Norm[a+b+c] = max( Norm[a+b+c],c );
			}
		}
	}
	
	scanf("%ld",&Icase );
	while( Icase-- ){
		scanf("%ld%ld%ld",&N,&S,&p );
		for( i=1;i<=N;i++ ){
			scanf("%ld",&Pt[i] );
		}
		memset( Visit,0,sizeof(Visit));
		long Ans = Find( N,S );
		printf("Case #%ld: %ld\n",++k,Ans );
	}
	
	//scanf("%*ld");
	
	return 0;
}
	
