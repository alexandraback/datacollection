
#include<iostream>
#include<cstdio>

using namespace std ;

char G[5][5] ;

int xno, ono, Tno;

void getcountrow(int r) { 
	xno = ono = Tno = 0 ; 
	for ( int i = 0 ; i < 4 ; i ++ ) { 
		if ( G[r][i] == 'X') { xno ++ ; } 
		else if ( G[r][i] == 'O' ) { ono ++ ; } 
		else if ( G[r][i] == 'T' ) { Tno ++ ; } 		
	}
}

void getcountcol(int c) { 
	xno = ono = Tno = 0 ; 
	for ( int i = 0 ; i < 4 ; i ++ ) { 
		if ( G[i][c] == 'X') { xno ++ ; } 
		else if ( G[i][c] == 'O' ) { ono ++ ; } 
		else if ( G[i][c] == 'T' ) { Tno ++ ; } 		
	}
}

void solve() { 
	for ( int i = 0 ; i < 4 ; i ++ ) { 
		scanf("%s", G[i]);
	}
	for ( int i = 0 ; i < 4 ; i ++ ) { 
		getcountrow(i);
		if ( xno == 4 || (xno == 3 && Tno == 1) ) { 
			printf("X won\n");
			return;
		}
		if ( ono == 4 || (ono == 3 && Tno == 1) ) { 
			printf("O won\n");
			return ;
		}
	}
	for ( int i = 0 ; i < 4 ; i ++ ) { 
		getcountcol(i);
		if ( xno == 4 || (xno == 3 && Tno == 1) ) { 
			printf("X won\n");
			return;
		}
		if ( ono == 4 || (ono == 3 && Tno == 1) ) { 
			printf("O won\n");
			return ;
		}
	}

	xno = ono = Tno = 0 ;
	for ( int i = 0 ; i < 4 ; i ++ ) { 
		if ( G[i][i] == 'X') { xno ++ ; } 
		else if ( G[i][i] == 'O' ) { ono ++ ; } 
		else if ( G[i][i] == 'T' ) { Tno ++ ; } 		
	}
	if ( xno == 4 || (xno == 3 && Tno == 1) ) { 
		printf("X won\n");
		return;
	}
	if ( ono == 4 || (ono == 3 && Tno == 1) ) { 
		printf("O won\n");
		return ;
	}


	xno = ono = Tno = 0 ;
	for ( int i = 0 ; i < 4 ; i ++ ) { 
		if ( G[i][3-i] == 'X') { xno ++ ; } 
		else if ( G[i][3-i] == 'O' ) { ono ++ ; } 
		else if ( G[i][3-i] == 'T' ) { Tno ++ ; } 		
	}
	if ( xno == 4 || (xno == 3 && Tno == 1) ) { 
		printf("X won\n");
		return;
	}
	if ( ono == 4 || (ono == 3 && Tno == 1) ) { 
		printf("O won\n");
		return ;
	}


	bool dotfound = false ;
	for ( int i = 0; i < 4 ; i ++ ) { 
		for ( int j = 0 ; j < 4 ; j ++ ) { 
			if ( G[i][j] == '.' ) { 
				dotfound = true ;
			}
		}
	}
	if ( dotfound ) { 
		printf("Game has not completed\n");
	} else { 
		printf("Draw\n");
	} 
	return ;
}


int main() {
	int t ;
	int tno = 1; 
	for ( scanf("%d", &t); t -- ; ) { 
		printf("Case #%d: ", tno++);
		solve();
	}
	return 0;
}
