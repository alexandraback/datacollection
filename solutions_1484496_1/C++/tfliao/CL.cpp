#include <cstdio>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
#include <vector>
#include <sstream>
using namespace std ;

typedef long long LL ;

#define MOD 20007

struct HashEntry {
	LL sum;
	// vector<LL> vals ;
	string vals;
};

HashEntry hash[MOD];

void AppendString ( string& str, LL val ) {
	ostringstream oss ;
	oss << val ;
	if ( str.length()==0 ) str = oss.str();
	else str += " " + oss.str();
}

// map < LL, vector<LL> > ans ;
int N ;
LL num[500] ;

void plist ( vector<LL>& list ) {
	for ( int i=0;i<list.size();++i ) {
		printf ( "%s%d", (i?" ":""), list[i] ) ;
	} printf ( "\n" ) ;
}

void plist ( string& str ) {
	printf ( "%s\n", str.c_str() ) ;
}

bool solv () {
	for ( int i=0;i<MOD;++i ) hash[i].sum = -1, hash[i].vals.clear();
	
	for ( int i=0;i<N;++i ) {
		LL key = num[i]%MOD;
		if ( hash[key].sum == num[i] ) {
			plist ( hash[key].vals);
			printf("%d\n", num[i] ) ;
			return true;
		} else {
			
			for ( int j=MOD-1;j>=0;--j ) {
				if ( hash[j].sum != -1 ) {
					LL s = num[i]+hash[j].sum;
					LL k = s%MOD;
					if ( hash[k].sum == s ) {
						plist ( hash[k].vals ) ;
						// hash[j].vals.push_back(num[i]);
						AppendString ( hash[j].vals, num[i] ) ;
						plist(hash[j].vals);
						return true;
					} else {
						hash[k].sum = s;
						hash[k].vals = hash[j].vals;
						// hash[k].vals.push_back(num[i]) ;
						AppendString ( hash[k].vals, num[i] ) ;
					}
				}
			}
			
			if ( hash[key].sum != num[i] ) {
				hash[key].sum = num[i];
				// hash[key].vals.push_back(num[i]);
				AppendString ( hash[key].vals, num[i] ) ;
			}
		}
	}
	return false;
}


int main()
{
    int T, nCase = 1 ; 
    cin >> T ; 
    while ( T-- ) { 
		cin >> N ;
		for ( int i=0;i<N;++i ) cin>>num[i];
		
		printf ( "Case #%d:\n", nCase++ ) ;
		if ( !solv() ) printf ( "Impossible\n" ) ;
	}
	return 0 ;
}
