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
	#define		For( i, s )			for(int i= 0; i< (int)s; i++)
	#define		ForA( i, a, s )		for(int i= (int)a; i< (int)s; i++)
	#define		ForSize( i, s )		for(int i= 0, size= (int)s; i< size; i++)
	#define		ForSizeA( i, a, s )	for(int i= (int)a, size= (int)s; i< size; i++)
	#define		ForItr( itr, con )	for(auto itr= con.begin(); itr!= con.end(); itr++)
	#define		ForStr( i, str )	for(int i= 0; str[i]; i++)
	#define		GOTO( lb )			goto lb
	#define		LABEL( lb )			lb:
	#define		ALL( con )			con.begin(), con.end()

	typedef		long long		LLint;
	typedef		unsigned int	Uint;
	typedef		unsigned char	Uchar;
	typedef		unsigned short	Ushort;
	
	const int Ten5= 100000;		//	10^5
	const int Ten6= 1000000;	//	10^6
	const double EPS= 0.00000000023283064365386962890625;	//	2^-32
	template <typename T> class priority_queue_less : public priority_queue<T,vector<T>,greater<T> >{};
}

int Cnt[Ten6];

LLint getRev(LLint x){
	LLint ret= 0;

	while(x){
		ret= ret*10 + ( x % 10 );
		x/= 10;
	}

	return ret;
}
void init(){
	int* cnt= Cnt -1;
	for(int x= 1; x<= Ten6; x++){
		cnt[x]= INT_MAX;
	}

	cnt[1]= 1;
	for(int x= 1; x<= Ten6; x++){
		cnt[x+1]= min( cnt[x+1], cnt[x]+1 );
		
		LLint t= getRev( x );
		cnt[t]= min( cnt[t], cnt[x]+1 );
	}
}
void solve(){
	LLint N;
	cin>> N;

	cout<< Cnt[N-1];
}
int main(){
	int L;
	cin>> L;

	init();

	For( l, L ){
		cout<< "Case #"<< l+1<< ": ";
		solve();
		cout<< endl;
	}

	return 0;
}
