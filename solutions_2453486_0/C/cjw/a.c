#include <stdio.h>
#include <strings.h>

char status[4][4];

int chkrow(int r) {
	char first = status[r][0];
	int i;

	if ( first == 'T' ) first = status[r][1];
	if ( first == '.' ) return 0;
	for ( i = 1 ; i < 4 ; i++ ) {
		if ( status[r][i] != 'T' && first != status[r][i] ) return 0;
	}

	if ( first == 'X' ) return 1;
	else return 2;
}

int chkcol(int c) {
	char first = status[0][c];
	int i;

	if ( first == 'T' ) first = status[1][c];
	if ( first == '.' ) return 0;
	for ( i = 1 ; i < 4 ; i++ ) {
		if ( status[i][c] != 'T' && first != status[i][c] ) return 0;
	}

	if ( first == 'X' ) return 1;
	else return 2;
}

int chkcrs1() {
	char first = status[0][0];
	int i;
	if ( first == 'T' ) first = status[1][1];
	if ( first == '.' ) return 0;
	for ( i = 1 ; i < 4 ; i++ ) {
		if ( status[i][i] != 'T' && first != status[i][i] ) return 0;
	}
	if ( first == 'X' ) return 1;
	else return 2;
}

int chkcrs2() {
	char first = status[0][3];
	int i;
	if ( first == 'T' ) first = status[1][2];
	if ( first == '.' ) return 0;
	for ( i = 1 ; i < 4 ; i++ ) {
		if ( status[i][3-i] != 'T' && first != status[i][3-i] ) return 0;
	}
	if ( first == 'X' ) return 1;
	else return 2;
}

int chkdraw() {
	int i, j;
	for ( i = 0 ; i < 4 ; i++ ) { 
		for ( j = 0 ; j < 4 ; j++ ) {
			if ( status[i][j] == '.' ) return 0;
		}
	}
	return 1;
}

int main() {
	int T, t;
	int win;
	int i, j;
	char nl;

	scanf("%d", &T);
	scanf("%c", &nl);

	for ( t = 1 ; t <= T ; t++ ) {
		win = 0;
		bzero(status, sizeof(status));

		for ( i = 0 ; i < 4 ; i++ ) {
			for ( j = 0 ; j < 4 ; j++ ) 
				scanf("%c", &status[i][j]);
			scanf("%c", &nl);
		}
		scanf("%c", &nl);

		/*
		for ( i = 0 ; i < 4 ; i++ ) {
			for ( j = 0 ; j < 4 ; j++ ) 
				printf("%c", status[i][j]);
			printf("\n");
		}
		*/

		// row & col
		for ( i = 0 ; i < 4 ; i++ ) {
			if ( ( win = chkrow(i) ) != 0 ) break;
			if ( ( win = chkcol(i) ) != 0 ) break;
		}
		if ( win != 0 ) {
			if ( win == 1 ) printf("Case #%d: X won\n", t);
			else if ( win == 2 ) printf("Case #%d: O won\n", t);
			continue;
		}

		// cross
		if ( ( win = chkcrs1() ) != 0 ) {
			if ( win == 1 ) printf("Case #%d: X won\n", t);
			else if ( win == 2 ) printf("Case #%d: O won\n", t);
			continue;
		}
		if ( ( win = chkcrs2() ) != 0 ) {
			if ( win == 1 ) printf("Case #%d: X won\n", t);
			else if ( win == 2 ) printf("Case #%d: O won\n", t);
			continue;
		}

		if ( chkdraw() ) printf("Case #%d: Draw\n", t);
		else printf("Case #%d: Game has not completed\n", t);
		
	}

	return 0;
}


