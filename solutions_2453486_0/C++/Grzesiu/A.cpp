#include <cstdio>

const char* test() {
	char M[5][5];
	scanf("%s %s %s %s", M[0], M[1], M[2], M[3]);
	int rows[4], cols[4], a, b, c=0;
	a = 0; b = 0;
	for( int j = 0; j < 4; j++ ) rows[j] = cols[j] = 0;
	for( int x = 0; x < 4; x++ )
		for( int y = 0; y < 4; y++ ) {
			if( M[x][y] == 'X' or M[x][y] == 'T' )
				if( ++rows[x] == 4 or ++cols[y] == 4 or (x == y and ++a == 4) or (x == 3-y and ++b == 4) )
					return "X won";
			if( M[x][y] == '.' )
				c++;
		}
 
	a = 0; b = 0;
	for( int j = 0; j < 4; j++ ) rows[j] = cols[j] = 0;
	for( int x = 0; x < 4; x++ )
		for( int y = 0; y < 4; y++ )
			if( M[x][y] == 'O' or M[x][y] == 'T' )
				if( ++rows[x] == 4 or ++cols[y] == 4 or (x == y and ++a == 4) or (x == 3-y and ++b == 4) )
					return "O won";

	if( c == 0 )
		return "Draw";
	return "Game has not completed";
}

int main() {
	int T;
	scanf("%d", &T );
	for( int i = 1; i <= T; i++ ) {
		printf("Case #%d: %s\n", i, test());
	}
}
