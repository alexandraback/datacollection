#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <vector> 

using namespace std;

int n;
int m;

const int N = 101 ;
int h[ N ] [ N ];


bool is_valid( int  di ,int   dj , int  v ){ 
	
	
	int sum=0;
	for( int j = 0 ; j < m; ++j ) { 

		if( h[di][j] > v) {
			break ;
		}
		else {
			sum += 1 ;
		}
	}
	if( sum== m){
		return true;
	}
	

	for( int i=0  ; i < n; ++i) {

		if( h[i][dj] > v ) {
			return false ;
		}
	}
	return true ;
 }

void solve( ) { 
    
	vector<int> vi[ 101 ];
	vector<int> vj[ 101 ];

	for( int i =0; i<n;++i){
			for(int j=0; j<m;++j) {

				int v = h[i][j] ;

				vi[ v ].push_back( i ) ;
				vj[ v ] .push_back ( j ) ; 
			}
	}

	for( int v =0 ; v <= 100 ; ++v ) { 

		if( vi[ v ].size() > 0 ) { 

			for( int t =0 ; t < vi[v] .size() ; ++t ) { 
				
				int di = vi[v][t];
				int dj = vj[v][ t ] ;
				//cout <<"di:" << di <<  " " <<dj << "  " << v <<endl;

				if( ! is_valid( di , dj , v ) ) { 
					
					cout << "NO"<< endl; 
					return ;
				}
			}

		}
	}
	cout <<"YES" << endl;

    
}


int main(void ) {
    
    int T ;
    cin >> T ; 
    
    
    for( int t =1 ; t <=T ;++t ) { 
        
        cin >> n >> m ;
        for( int i =0; i<n;++i){
			for(int j=0; j<m;++j) {

				cin >> h[i][j] ;
			}
		}

        printf( "Case #%d: " ,  t ) ;
        solve( ) ;
    }
    return 0 ;
}

        
        
        
        
        
 
