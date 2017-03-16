#include <stdio.h>
#include <string.h>

char S[5][5];
int T, test, X, Y, i, j;
bool Finished;

inline bool Check(char Ch)
{
	int i, j;
	bool Ok;
	
	//check lines
	for (i = 1; i <= 4; ++i){
		Ok = true;
		for (j = 1; j <= 4; ++j)
			if (S[i][j] != Ch)
				Ok = false;
		if (Ok)
			return true;
	}
	
	//check colums
	for (j = 1; j <= 4; ++j){
		Ok = true;
		for (i = 1; i <= 4; ++i)
			if (S[i][j] != Ch)
				Ok = false;
		if (Ok)
			return true;
	}
	
	//check first diagonal
	Ok = true;
	for (i = 1; i <= 4; ++i)
		if (S[i][i] != Ch)
			Ok = false;
	if (Ok)
		return true;
	
	//check second diagonal
	Ok = true;
	for (i = 1; i <= 4; ++i)
		if (S[i][5 - i] != Ch)
			Ok = false;
	if (Ok)
		return true;
	return false;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	scanf("%d\n", &T);
	for (test = 1; test <= T; ++test){
		printf("Case #%d: ", test);
		for (i = 1; i <= 4; ++i)
			gets(S[i]+1);
		gets(S[0]);
		Finished = true;
		X = Y = 0;
		for (i = 1; i <= 4; ++i)
			for (j = 1; j <= 4; ++j){
				if (S[i][j] == 'T'){
					X = i;
					Y = j;
				}
				if (S[i][j] == '.')
					Finished = false;
			}
		S[X][Y] = 'X';
		if (Check('X')){
			printf("X won\n");
			continue;
		}
		S[X][Y] = 'O';
		if (Check('O')){
			printf("O won\n");
			continue;
		}
		if (Finished)
			printf("Draw\n");
		else
			printf("Game has not completed\n");
	}
	
	return 0;
}