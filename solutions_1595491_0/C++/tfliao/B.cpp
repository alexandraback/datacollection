#include <iostream>
#include <string>
using namespace std;

int T, nCase = 1 ;
int S, N, p, v;
int ans = 0 ; 

void judge ( int x, int r ) {
	
	switch ( r ) {
		case 0:
			if ( x >= p ) { ++ans; return ; }
			if ( x+1>=p && S>0 && x>0 ) { --S, ++ans ; return ; }
			return ;
		case 1:
			if ( x+1 >= p ) { ++ans; return ; }
			return ;
		case 2:
			if ( x+1 >= p ) { ++ans; return ; }
			if ( x+2>=p && S>0 ) { --S, ++ans ; return ; }
			return ;
	}

}


int main()
{
	cin >> T;
	while ( T-- > 0 ) {
		cin >> N >> S >> p ;
		ans = 0 ;
		for ( int i=0;i<N;++i ) {
			cin >> v ;
			judge ( v/3, v%3 );
		}
		
		cout << "Case #" << nCase++ << ": " << ans << endl;
	}
	return 0; 
}