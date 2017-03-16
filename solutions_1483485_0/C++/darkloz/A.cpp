
//=======:=====================================================================
// Author      :  Carlos Eduardo Guillen Davila
//============================================================================

#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
#include <set>
#include <bitset>
#include <map>
#include <stack>
#include <queue>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <cstring>
#include <limits>

#define all(c) c.begin(),c.end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define forr(a,i,f) for( int a = i ; a < f ; ++a )
#define iter(c) typeof( c.begin() )

#define feq(a,b) fabs( a-b ) < eps
#define sqr(x) ((x)*(x))
#define eps 1e-7

#define pass puts("PASO");

#define V(x) vector<x>
#define VV(x) vector< V(x) >
#define P(a,b) pair<a,b>
#define pii P(int,int)
#define vi V(int)
#define vvi VV(int)

using namespace std;


int main() {

	string src = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jvyeqz";
	string tar = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give upaozq";	
	char trans[256];

	for( int i = 0; i< src.size() ; ++i )
		trans[ src[i] ] = tar[i];

	int n; cin >> n;
	int caso = 0;
	string line; getline(cin , line );
	forr( i ,0 , n){
		printf("Case #%d: " , ++caso  );
		getline( cin , line );
		forr( j , 0  , line.size() )
			cout<< trans[ line[j] ];
		puts("");
	}



	return 0; 
}
