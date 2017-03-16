#include <cstdio>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
#include <vector>

using namespace std ;



map < int, vector<int> > ans ;
int N ;
int num[20] ; 

void plist ( vector<int>& list ) {
	for ( int i=0;i<list.size();++i ) {
		printf ( "%s%d", (i?" ":""), list[i] ) ;
	} printf ( "\n" ) ;
}

bool solv ( int idx, int sum, vector<int>  list ) 
{
	for ( int i=idx;i<N;++i ) {
		if ( ans.find(sum+num[i]) != ans.end() ) {
			plist ( ans[sum+num[i]] ) ;
			list.push_back(num[i]);
			plist ( list ) ;
			return true;
		} else {
			list.push_back(num[i]);
			ans[sum+num[i]] = list ;
			
			if ( solv ( i+1, sum+num[i], list ) ) return true;
			list.pop_back();
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
		ans.clear();
		vector<int> list;
		
		printf ( "Case #%d:\n", nCase++ ) ;
		if ( !solv(0,0,list) ) printf ( "Impossible\n" ) ;
	}
	return 0 ;
}