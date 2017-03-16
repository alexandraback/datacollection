#include <cstdio>


using namespace std;

char field[4][4];
int cX=0;
int cO=0;
int cT=0;

bool final() {
	return cX+cO+cT == 16;
}

int okay(int x, int y, char c) {
	return (field[x][y]==c || field[x][y]=='T') ? 1 : 0;
}


bool won(char c) {
	int diag1C=0;
	int diag2C=0;
	for(int i=0; i<4; i++) {
		int rowC=0;
		int colC=0;
		diag1C += okay(i,i,c);
		diag2C += okay(i,3-i,c);
		for(int j=0; j<4; j++) {
			rowC += okay(i,j,c);
			colC += okay(j,i,c);
		}
		if(rowC==4 || colC==4)
			return true;
	}
	if(diag1C==4 || diag2C==4) 
		return true;
	return false;
}

int main() {
	int T;
	scanf("%d ", &T);
	for(int t=0; t<T; ++t) {
		
		cX=cO=cT=0;
		
		// read
		for(int i=0; i<4; ++i) {
			for(int j=0; j<4; ++j) {
				scanf("%c", &field[i][j]);
				if(field[i][j]=='X')
					cX++;				
				if(field[i][j]=='O')
					cO++;				
				if(field[i][j]=='T')		
					cT++;			
			}
			scanf(" ");
		}	/*
		for(int i=0; i<4; ++i) {
			for(int j=0; j<4; ++j) {
				printf("%c", field[i][j]);
			}
			printf("\n");
		}
		printf("X\n");
		for(int i=0; i<4; ++i) {
			for(int j=0; j<4; ++j) {
				printf("%d", okay(i,j,'X'));
			}
			printf("\n");
		}*/

		//printf("%d %d %d -> %d\n",cX,cO,cT, cX+cO+cT);

		printf("Case #%d: ", t+1);
		
		if(won('X'))
			printf("X won\n");
		else if(won('O'))
			printf("O won\n");
		else if(final()) 
			printf("Draw\n");
		else
			printf("Game has not completed\n");
		
	}
	
	return 0;
}
