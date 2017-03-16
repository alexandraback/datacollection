#include <iostream>
#include <stdio.h>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <string>
#include <queue>
#include <functional>
#include <stack>
#include <complex>
#include <stdlib.h>
#include <string.h>
using namespace std;

namespace{
	#define		CAST( T, val )		( (T)( val ) )
	#define		CASE( lb )			break; case lb:
	#define		CASE_CONTINUE( lb )	case lb:
	#define		CASE_DEFAULT		break; default:
	#define		For( i, s )			for(int i= 0, forEnd##i= s; i< forEnd##i; i++)
	#define		ForItr( itr, con )	for(auto itr= con.begin(), forEnd##itr= con.end(); itr!= forEnd##itr; itr++)
	#define		ForStr( i, str )	for(int i= 0; str[i]; i++)
	#define		GOTO( lb )			goto lb
	#define		LABEL( lb )			lb:
	#define		ALL( con )			con.begin(), con.end()

	typedef		long long		LLint;
	typedef		unsigned int	Uint;
	typedef		unsigned char	Uchar;
	typedef		unsigned short	Ushort;

	const int Ten5 = 100000;		//	10^5
	const int Ten6 = 1000000;	//	10^6
	const double EPS = 0.00000000023283064365386962890625;	//	2^-32
	
	template <typename T> const T& max(const T& x){ return x; }
	template <typename T, typename... Args> const T& max(const T& x, const Args&... args){ return std::max( x, max<Args...>( args... ) ); }
	template <typename T> const T& min(const T& x){ return x; }
	template <typename T, typename... Args> const T& min(const T& x, const Args&... args){ return std::min( x, min<Args...>( args... ) ); }
}


void init(){}
void solve(){
	char S[1024];
	cin>> S;

	list<char> ls;

	ls.push_back( S[0] );
	char top= S[0];
	ForStr( i, S ) if(i){
		if( S[i] < top ){
			ls.push_back( S[i] );
		}else{
			ls.push_front( top= S[i] );
		}
	}

	cout<< " ";
	ForItr( i, ls ){
		cout<< *i;
	}
}
int main(){
	init();
	int cnt;
	cin>> cnt;
	For( i, cnt ){
		//fprintf( stderr, "#%d\n", i+1 );
		printf( "Case #%d:", i+1 );
		solve();
		puts("");
	}

	return 0;
}
