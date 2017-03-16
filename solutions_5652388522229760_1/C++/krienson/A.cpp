#include<iostream>
#include<vector>

using namespace std;

bool allseen( vector< bool > &v ){
	for( int i = 0; i < int( v.size() ); i++ )
		if( !v[ i ] )
			return false;
	return true;
}

void update( vector< bool > &v, int n ){
	while( n ){
		v[ n%10 ] = true;
		n/=10;	
	}	
}

int main(){
	int kases; cin >> kases;
	for( int kase = 1; kase <= kases; kase++ ){
		int N; cin >> N;
		if( N == 0 ){
			cout << "Case #" << kase << ": INSOMNIA" << endl;
			continue;
		}
		vector< bool > v( 10, false );
		update( v, N );
		int rep = 1;
		while( !allseen( v ) ){
			rep++;
			update( v , N*rep );
		}
		cout << "Case #" << kase << ": " << N * rep << endl;
	}
}
