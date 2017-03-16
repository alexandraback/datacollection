#include <stdio.h>
#include <math.h>

#define maxsize 50
void printBoard(char board[maxsize][maxsize], int r, int c) {
//not the sexiest way to write this, but it works and I don't have to think about it
	int i,j;
	for(i=0; i<r; i++) {
		for(j=0; j<c-1; j++) {
			printf("%c", board[i][j]);
		}
		printf("%c\n", board[i][j]);
	}
}

void minedBoard(char board[maxsize][maxsize], int r, int c) {
//set everything to mines
	int i,j;
	for(i=0; i<r; i++) {
		for(j=0; j<c; j++) {
			board[i][j] = '*';
		}
	}
}

int countMines(char board[maxsize][maxsize], int r, int c) {
	int i,j,n;
	n = 0;
	for(i=0; i<r; i++) {
		for(j=0; j<c; j++) {
			n += (board[i][j] == '*');
		}
	}
	return n;
}

int main() {
	int t;
	int r, c, m, n;
	scanf("%u\n", &t);
	char board[maxsize][maxsize];

	int i,j,x,y;
	int possible;
	
	for(i=1; i<=t; i++) {
		scanf("%u %u %u\n", &r, &c, &m);
		minedBoard(board, r, c);
		
		n = r*c-m;
		//Algorithm is based on number of _unmined_ cells.
		//some notes: 1 free cell we can always do.
		// 2 or 3 free cells we can only do if r==1 or c==1
		// 4 free cells we should always be able to do, since as long as r,c >= 2, we can do a 2x2 in a corner, and if r or c == 1 then we can do a row of 4
		if(n == 1) {
			possible = 1;
		} else if (r==1) {
			possible = 1;
			for(j=0; j<n; j++) {
				board[0][j] = '.';
			}
		} else if (c==1) {
			possible = 1;
			for(j=0; j<n; j++) {
				board[j][0] = '.';
			}
		} else if (n==2 || n==3) {
			possible = 0;  //this might be handled under the next case, but...
		} else {
			// Imagine a configuration like this:
			//
			// ....***
			// ....***
			// ..*****
			// ..*****
			// *******
			//
			// It should be clear that we can add any number of additional mines inside the l until it's filled up...
			// so in other words for 2<=y<=r, 2<=x<=c, we can have any number of free spaces between (2*(x+y)-4) and x*y
			possible = 0;
			for(y=2; y<=r; y++) {
				for(x=2; x<=c; x++) {//probably double check some configurations this way, but we should be fast enough anyway not to matter
					if(n >= 2*(x+y)-4 && n <= x*y) {
						possible = 1;
						//now we just need to draw the board
						for(j=0; j<y; j++) {
							board[j][0] = '.'; board[j][1] = '.';
						}
						for(j=2; j<x; j++) {
							board[0][j] = '.'; board[1][j] = '.';
						}
						//fprintf(stderr, "allocating %i free spaces, ",n);
						n -= 2*(x+y)-4;
						//fprintf(stderr, "%i left after making the L\n",n);
						for(j=0; j<n; j++) {
							//fprintf(stderr, "%i, %i\n", 2+j%(y-2), 2+j/(y-2));
							board[2+j%(y-2)][2+j/(y-2)] = '.';
						}

						y = r+1; x = c+1; break; //exit the loop
					}
				}
			}
		}

		// should be trivial to write a function to _check_ a given grid, but I don't know if I care that much...

		printf("Case #%u:\n",i);
		if(possible) {
			board[0][0] = 'c';
			if(countMines(board, r, c) != m) {
				fprintf(stderr, "case %u has wrong number of mines (have %i, supposed to have %i)\n", i, countMines(board,r,c), m);
			}
			printBoard(board, r, c);
		} else {
			printf("Impossible\n");
		}
	}
	return 0;
}
