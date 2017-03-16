#include <iostream>
#include <stdio.h>

using namespace std;

int T;
char arr[4][4];
char temp;

int main() {
	scanf("%d", &T);
	for( int t = 0; t < T; t++) {
		bool done = false;
		for( int r = 0; r < 4; r++) {
			scanf("%s",arr[r]);
		}
		scanf("%c", &temp);
		
		// check rows
		for( int r = 0; r < 4; r++) {
			int countX = 0; 
			int countO = 0;
			for( int c = 0; c < 4; c++) {
				if( arr[r][c] == 'T' ) {
					countX++;
					countO++;
				} else if( arr[r][c] == 'X' ) {
					countX++;
				} else if( arr[r][c] == 'O' ) {
					countO++;
				}
			}
			if( countX == 4 ) {
				cout<<"Case #"<<t+1<<": X won\n";
				done = true;
				break;
			}
			if( countO == 4 ) {
				cout<<"Case #"<<t+1<<": O won\n";
				done = true;
				break;
			}
		}
		if( !done ) {
				// check COLS
			for( int c = 0; c < 4; c++) {
				int countX = 0; 
				int countO = 0;
				for( int r = 0; r < 4; r++) {
					if( arr[r][c] == 'T' ) {
						countX++;
						countO++;
					} else if( arr[r][c] == 'X' ) {
						countX++;
					} else if( arr[r][c] == 'O' ) {
						countO++;
					}
				}
				if( countX == 4 ) {
					cout<<"Case #"<<t+1<<": X won\n";
					done = true;
					break;
				}
				if( countO == 4 ) {
					cout<<"Case #"<<t+1<<": O won\n";
					done = true;
					break;
				}
			}
			if( !done ) {
				// check diagonals
				int countO = 0; 
				int countX = 0;
				for( int i = 0; i < 4; i++) {
					if( arr[i][i] == 'T' ) {
						countX++;
						countO++;
					} else if( arr[i][i] == 'X' ) {
						countX++;
					} else if( arr[i][i] == 'O' ) {
						countO++;
					}
				}
				if( countX == 4 ) {
					cout<<"Case #"<<t+1<<": X won\n";
					done = true;
				}
				if( countO == 4 ) {
					cout<<"Case #"<<t+1<<": O won\n";
					done = true;
				}
				countX = 0; 
				countO = 0;
				if( !done ) {
					int countO = 0; 
					int countX = 0;
					for( int i = 0; i < 4; i++) {
						if( arr[3-i][i] == 'T' ) {
							countX++;
							countO++;
						} else if( arr[3-i][i] == 'X' ) {
							countX++;
						} else if( arr[3-i][i] == 'O' ) {
							countO++;
						}
					}
					if( countX == 4 ) {
						cout<<"Case #"<<t+1<<": X won\n";
						done = true;
					}
					if( countO == 4 ) {
						cout<<"Case #"<<t+1<<": O won\n";
						done = true;
					}
				}
				if( !done ) {
					// check if draw or not
					done = true;
					for( int r = 0; r < 4; r++) {
						for( int c = 0; c < 4; c++) {
							if( arr[r][c] == '.' ) {
								done = false;
							}
						}
					}
					if( done ) {
						cout<<"Case #"<<t+1<<": Draw\n";
					}else {
						cout<<"Case #"<<t+1<<": Game has not completed\n";
					}
				}	
			}
		}
	}
	return 0;
}
