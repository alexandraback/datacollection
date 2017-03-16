#include <stdio.h>
#include <string.h>

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>

using namespace std ;
#define lint long long
#define FOREACH(it,v) for( typeof((v).begin()) it = (v).begin() ; it != (v).end() ; it++ )
#define ALL(v) (v).begin(),(v).end()

const int infinity = 0x3fffffff ;
const lint linfinity = 0x3fffffffffffffffLL ;

const int maxn = 1010 ;
int n ;

string solveASingleCase(){
	cin >> n ;

	vector<pair<int,int> > vLevels ;
	for(int i = 0 ;i < n ; i++ ){
		int a , b ;
		cin >> a >> b ;

		vLevels.push_back( make_pair(a,b) ) ;

	}
	

	int res = 0 , atts = 0 ;
	vector<int> play( n , 0 ) ;
	
	for( ; res < 2*n ; ){
		
		int idx = -1 ;
		for( int i = 0 ;i < n ; i++ )
			if( play[i]  == 0 and vLevels[i].second <= res ){
				idx = i ;
				break ;
			}

		if( idx >= 0 ){
			play[idx] = 2 ;
			atts ++ ;

			res += 2 ;
			continue ;
		}

		for( int i = 0 ; i < n ; ++i ){
			if( play[i] == 1 and vLevels[i].second <= res ){
				idx = i ;
				break ;
			}
		}
		if(idx >= 0 ){
			play[idx]++ ;
			atts ++ ;
			res ++ ;
			continue ;
		}

		
		for( int i = 0 ;i < n ; i++ )
			if( play[i] == 0 and vLevels[i].first <= res ){
				if( idx < 0 || vLevels[idx].second < vLevels[i].second ){
					idx = i ; 
					//break ;
				}
			}

		if( idx < 0 ) return "Too Bad" ;
		play[idx]++ ;
		atts ++ ;
		res ++ ;
	}

	

	char bf[32] ;
	sprintf( bf , "%d" , atts ) ;
	return string( bf ) ;
}

int main(){
	int cases ;
	cin >> cases ;

	for( int cs = 1 ; cs <= cases ; cs++ ){
		cout << "Case #" << cs << ": " << solveASingleCase() << endl ;
	}

	return 0 ;
}
