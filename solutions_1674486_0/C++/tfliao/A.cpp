#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
#include <algorithm> 
#include <vector> 
#include <cmath> 
#include <map>
#include <queue>
#include <cstring>
#include <string>
using namespace std; 

vector< vector<int> > edge ;
vector<int> ind ;
int N ;

vector<int> flag;

bool solv ( int x ) {
	if ( flag[x] != 0 ) return true;
	else {
		flag[x] = 1 ;
		for ( int i=0;i<edge[x].size();++i ) {
			if ( solv ( edge[x][i] ) ) return true;
		}
	}
	return false;
}


bool solv () {
	
	for ( int i=0;i<N;++i ) if ( ind[i] == 0 ) { 
		flag = vector<int>(N,0); 
		if ( solv(i) ) return true;
	} 
	
	return false ;
}


int main() 
{
    int T, nCase = 1 ; 
    cin >> T ; 
    while ( T-- ) { 
        cin >> N ;
		edge = vector < vector<int> > ( N );
		ind = vector<int> ( N, 0 ) ;
		for ( int i=0;i<N;++i ) {
			int x, t ;
			cin >> x ;
			while ( x-- ) {
				cin >> t ;
				edge[i].push_back(t-1);
				ind[t-1] ++ ;
			}
		}
        printf ( "Case #%d: %s\n", nCase++, (solv()?"Yes":"No") ) ; 
    } 

    return 0; 
}
