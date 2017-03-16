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

#define MAX 21
#define MAX_V 100007

long N;
long Val[MAX+7];	
long Map[MAX*MAX_V+7];		

void Print( long s )
{
	long i;
	bool First = true;
	for( i=0;i<N;i++ ){
		if( s & (1<<i )){
			if( !First ) printf(" ");
			else First = false;
			printf("%ld",Val[i] );
		}
	}
	printf("\n");
}
	
int main( void )
{
    long i,j,Icase,k = 0;
    
    freopen("c.in","r",stdin );
    freopen("c.out","w",stdout );
    
    scanf("%ld",&Icase );
    while( Icase-- ){
		scanf("%ld",&N );
		for( i=0;i<N;i++ ){
			scanf("%ld",&Val[i] );
		}
		MSV( Map,0 );
		bool Find = false;
		printf("Case #%ld:\n",++k );
		for( i=1;i<(1<<N) && !Find;i++ ){
			long s = 0;
			for( j=0;j<N;j++ ){
				if( i & (1<<j )) s += Val[j];
			}
			//if( !i ) printf("here\n");
			if( Map[s] ){
				Find = true;
				long v1 = Map[s];
				long v2 = i;
				long c = v1 ^ v2;
				v1 = v1 & c;
				v2 = v2 & c;
				//printf("here %ld %ld %ld %ld\n",v1,v2,v1 & c,v2 & c );
				Print( v1 & c );
				Print( v2 & c );
			}
			else{
				Map[s] = i;
			}
		}
		if( !Find ) printf("Impossible\n");
	}									
		
	//scanf("%*ld");

    return 0;
}
