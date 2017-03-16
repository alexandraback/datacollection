#include <cstdlib>
#include <cstdio>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)

using namespace std;

char P[4][6];

bool checkRow(int i, char c){
	FWD(j,0,4)
		if(P[i][j] != c && P[i][j] != 'T')
			return 0;
	printf("%c won\n", c);
	return 1;
}

bool checkCol(int j, char c){
	FWD(i,0,4)
		if(P[i][j] != c && P[i][j] != 'T')
			return 0;
	printf("%c won\n", c);
	return 1;
}

bool checkDiagA(char c){
	FWD(i,0,4)		
		if(P[i][i] != c && P[i][i] != 'T')
			return 0;
	printf("%c won\n", c);
	return 1;
}

bool checkDiagB(char c){
	FWD(i,0,4)		
		if(P[i][3-i] != c && P[i][3-i] != 'T')
			return 0;
	printf("%c won\n", c);
	return 1;
}

bool end(){
	FWD(i,0,4)
		FWD(j,0,4)
			if(P[i][j] == '.')
				return 0;
	return 1;
}

void solve(){
	FWD(i,0,4){
		if(checkRow(i, 'X')) return;
		if(checkCol(i, 'X')) return;
		if(checkRow(i, 'O')) return;
		if(checkCol(i, 'O')) return;
	}
	if(checkDiagA('X')) return;
	if(checkDiagA('O')) return;
	if(checkDiagB('X')) return;
	if(checkDiagB('O')) return;
	if(end()){
		printf("Draw\n");
	}else{
		printf("Game has not completed\n");
	}
}

int main(){
	int Z;
	scanf("%d", &Z);
	FWD(z,1,Z+1){
		printf("Case #%d: ", z);
		FWD(i,0,4) scanf("%s", P[i]);
		solve();
	}
}

