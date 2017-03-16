#include <cstdio>

using namespace std;

int T;
char F[4][4];
int x,y,i,j;
char testc() {
	int count = 0;
	for(int i=0;i<4;i++) {
		for(int j=0;j<4;j++) {
			scanf("%c",&F[i][j]);
			if(F[i][j]!='.') count++;
		}
		scanf("\n");
	}
	scanf("\n");
	
	// does X win?
	// horizontal
	bool check;
	for(int i=0;i<4;i++) {
		check=true;
		for(int j=0;j<4;j++) {
			if(F[i][j]!='X' && F[i][j] != 'T') check=false;
		}
		if(check) return 'X';
	}
	// vertical
	for(int j=0;j<4;j++) {
		check=true;
		for(int i=0;i<4;i++) {
			if(F[i][j]!='X' && F[i][j] != 'T') check=false;
		}
		if(check) return 'X';
	}
	// diagonal
	check=true;
	for(int i=0;i<4;i++) {
		if(F[i][i]!='X' && F[i][i] != 'T') check=false;
	}
	if(check) return 'X';
	check=true;
	for(int i=0;i<4;i++) {
		if(F[3-i][i]!='X' && F[3-i][i] != 'T') check=false;
	}
	if(check) return 'X';

	// does O win?
	// horizontal
	for(int i=0;i<4;i++) {
		check=true;
		for(int j=0;j<4;j++) {
			if(F[i][j]!='O' && F[i][j] != 'T') check=false;
		}
		if(check) return 'O';
	}
	// vertical
	for(int j=0;j<4;j++) {
		check=true;
		for(int i=0;i<4;i++) {
			if(F[i][j]!='O' && F[i][j] != 'T') check=false;
		}
		if(check) return 'O';
	}
	// diagonal
	check=true;
	for(int i=0;i<4;i++) {
		if(F[i][i]!='O' && F[i][i] != 'T') check=false;
	}
	if(check) return 'O';

	check=true;
	for(int i=0;i<4;i++) {
		if(F[3-i][i]!='O' && F[3-i][i] != 'T') check=false;
	}
	if(check) return 'O';

	if(count==16) return 'D';
	return 'N';
}

int main() {
	scanf("%d\n",&T);
	for(int t=0;t<T;t++) {
		char w = testc();
		printf("Case #%d: ",t+1);
		if(w=='X') printf("X won\n");
		if(w=='O') printf("O won\n");
		if(w=='D') printf("Draw\n");
		if(w=='N') printf("Game has not completed\n");
	}

}