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
#define check(c)	( c!='a' && c!='e' && c!='i' && c!='o' && c!='u' )
using namespace std;

lint ans;
int id,test,len,n;
char str[mxn];

void solve(){

	int bas,son,uz;

	scanf( "%d" , &test );

	for( id=1 ; id<=test ; id++ ){

		scanf( "%s %d" , str+1 , &n );

		len = strlen( str+1 );
		ans = 0;

		son = 0;
		uz = 0;
		for( bas=1 ; bas<=len ; bas++ ){

			while( son<=len && uz<n ){
				son++;
				if( check( str[son] ) )		uz++;
				else						uz=0;
			}

			ans += (len-son+1);

			if( son-bas+1==uz )	uz--;

		}

		printf( "Case #%d: %lld\n" , id , ans );

	}
	return;
}

int main(){
	solve();
	return 0;
}
