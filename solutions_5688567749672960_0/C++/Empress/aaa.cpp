#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

queue< pair<int,int> > q;
int vis[1000010];

int solve( int x ) {
    int y = 0;
    while ( x ) {
        int z = x % 10;
        y = y * 10 + z;
        x /= 10;
    }
    return y;
}

void init( ) {
	memset( vis , 0x3f3f3f3f , sizeof(vis) );
	vis[0] = 0;
	for ( int i = 1 ; i<=1000000 ; ++i ) {
		int temp = solve(i);
		vis[i] = min( vis[i] , vis[i-1]+1 );
		if ( temp>i+1 ) {
			vis[temp] = min( vis[temp] , vis[i]+1 );
		} 
	}	
}

int main( ) {
	freopen("A-small-attempt2.in","r",stdin);
	freopen("aaa.out","w",stdout);
    int t , n , res;
    cin >> t;
    init( );
    for ( int k = 1 ; k<=t ; ++k ) {
		cin >> n;
		cout << "Case #" << k << ": " << vis[n] << endl;
    }
    return 0;
}

