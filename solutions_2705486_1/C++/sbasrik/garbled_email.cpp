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
#define mxn       	5005
#define wsize		521196
using namespace std;

ifstream in( "dict.in" );

int id,test,len;
int dp[mxn][8];
int vis[mxn][mxn],v;
char str[mxn];
string word[550000];

int find( int ind , int last ){

	if( ind>len )	return 0;

	int &ans = dp[ind][last];

	if( vis[ind][last] == v )	return ans;
	vis[ind][last] = v;

	ans = oo;

	int i,j,k,pre,syc;

	for( i=1 ; i<=wsize ; i++ )
	if( ind+word[i].size()-1<=len ){

		if( last==0 )	pre = -100;
		else			pre = ind-last;

		syc = 0;

		for( j=ind,k=0 ; k<word[i].size() ; j++,k++ )
			if( str[j] != word[i][k] )
				if( j-pre<5 )	break;
				else			pre = j,syc++;

		if( k==word[i].size() )
			ans = min( ans , find( j , MIN(5,j-pre) ) + syc );
	
	}

	return ans;

}

void solve(){

	for( int i=1 ; i<=wsize ; i++ )		in>>word[i];

	scanf( "%d" , &test );

	for( id=1 ; id<=test ; id++ ){

		scanf( "%s" , str+1 );
		len = strlen( str+1 );

		v++;

		printf( "Case #%d: %d\n" , id , find( 1,0 ) );

	}
	return;
}

int main(){
	solve();
	return 0;
}
