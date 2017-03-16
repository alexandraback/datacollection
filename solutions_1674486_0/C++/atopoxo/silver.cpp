
//C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
//C++
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
#include <stack>
#include <string>
#include <list>
#include <queue>
#include <map>
#include <vector>
#include <deque>
#include <set>
using namespace std;

//*************************JUDGE**************************
#define LOCAL_HOST
#define ONLINE_JUDGE
#define TIME_OUT_PUT

//**************************CONSTANT***********************
#define INF 0x7F7F7F7F
#define eps 1e-8
#define PI acos( -1. )
#define PI2 asin ( 1. );
typedef long long LL;
//typedef __int64 LL;   //codeforces
#define MP make_pair
typedef vector<int> VI;
typedef vector<int> VS;
typedef pair<int , int> PII;
#define pb push_back
#define mp make_pair

//***************************SENTENCE************************
#define FOR(a,b,i) for ( i = a ; i < b ; i++ )
#define FORE(a,b,i) for ( i = a ; i <= b ; i++ )
#define REP(i,n) FOR(0,n,i)
#define CL(a,b) memset ( a , b , sizeof ( a ) )
#define sqr(a,b) sqrt ( (double)(a)*(a) + (b)*(b) )

//****************************FUNCTION************************
template < typename T > double DIS ( T va , T vb ) { return sqr ( va.x - vb.x , va.y - vb.y ); }
template <class T> inline T INT_LEN( T v ) { int len = 1 ; while ( v /= 10 ) ++len; return len; }

//end

#define cy 1005

int g[cy];
bool vis[cy];

typedef struct {
	int v , nxt;
}re;
re e[cy * cy];

int N , k;
bool flag;

void init (){
	flag = false;
	k = 0;
	CL ( g , -1 );
	CL ( vis , 0 );
}

void addedge ( int u , int v ){
	e[k].v = v;
	e[k].nxt = g[u] ; g[u] = k++;
}

void input (){
	int i , num , v;
	scanf ( "%d" , &N );
	REP ( i , N ){
		scanf ( "%d" , &num );
		while ( num-- ){
			scanf ( "%d" , &v );
			v--;
			addedge ( i , v );
		}
	}
}

void dfs ( int u ){
	int i , v;
	if ( flag ) return ;
	if ( vis[u] ) {
		flag = true;
		return ;
	}else vis[u] = true;
	for ( i = g[u] ; ~i && !flag ; i = e[i].nxt ){
		v = e[i].v;
		dfs ( v );
	}
}

void solve ( int n ){
	int i;
	for ( i = 0 ; i <  n; i++ ){
		CL ( vis , false );
		dfs ( i );
		if ( flag ) break;
	}
	if ( flag ) puts ( "Yes" );
	else puts ( "No" );
}

int main (void){
	freopen ( "A-small-attempt0.in" , "r" , stdin );
//	freopen ( "A-small-attempt0.out" , "w" , stdout );
	int cas , i;
	scanf ( "%d" , &cas );
	for ( i = 1 ; i <= cas ; i++ ){
		init ();
		input ( );
		printf ( "Case #%d: " , i );
		solve ( N );
	}
	return 0;
}