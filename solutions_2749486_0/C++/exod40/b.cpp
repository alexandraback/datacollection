#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int C = 101;

int x , y;
int dp[405][405][405];
char s[405][405][405];

void read() {
	scanf ( "%d%d" , &x , &y );
}

int go ( int q , int w , int k ) {
	if ( q < -C || q > C || w < -C || w > C ) return (1 << 30) - 5;
	if ( q == x && w == y ) return 0;
	if ( k >= 202 ) return (1 << 30) - 5;

	
	int &ans = dp[q + 101][w + 101][k];
	if ( ans != -1 ) return ans;
	
	ans = 300;
	
	if ( go ( q - k , w , k + 1 ) + 1 < ans ) {
		ans = go ( q - k , w , k + 1 ) + 1;
		s[q][w][k] = 'W';
	}
	if ( go ( q + k , w , k + 1 ) + 1 < ans ) {
		ans = go ( q + k , w , k + 1 ) + 1;
		s[q][w][k] = 'E';
	}
	
	if ( go ( q , w - k , k + 1 ) + 1 < ans ) {
		ans = go ( q , w - k , k + 1 ) + 1;
		s[q][w][k] = 'S';
	}
	if ( go ( q , w + k , k + 1 ) + 1 < ans ) {
		ans = go ( q , w + k , k + 1 ) + 1;
		s[q][w][k] = 'N';
	}
	
	return ans;
}

void print ( int q , int w , int k ) {
	if ( x == q && w == y ) return ;
	
	printf ( "%c" , s[q][w][k] );
	
	if ( s[q][w][k] == 'W' ) print ( q - k , w , k + 1 );
	if ( s[q][w][k] == 'E' ) print ( q + k , w , k + 1 );
	if ( s[q][w][k] == 'S' ) print ( q , w - k , k + 1 );
	if ( s[q][w][k] == 'N' ) print ( q , w + k , k + 1 );
}

void solve() {
	memset ( dp , -1 , sizeof dp );
	go ( 0 , 0 , 1 );
	print ( 0 , 0 , 1 );
	printf ( "\n" );
}

int main() {
	int i , cases;
	
	scanf ( "%d" , &cases );
	for (i = 1; i <= cases; i++) {
		read();
		printf ( "Case #%d: " , i );
		solve();
	}
	
	return 0;
}
