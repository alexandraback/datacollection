//By momo
#include <cstdio>
#include <algorithm>
using namespace std;

char tbl[5][5];
bool check(char c){
	for(int i = 0; i < 4; i++){
		int fl = 1;
		for(int j = 0; j < 4; j++)
			if(tbl[i][j] != c && tbl[i][j] != 'T') fl = 0;
		if(fl) return 1;
	}
	for(int j = 0; j < 4; j++){
		int fl = 1;
		for(int i = 0; i < 4; i++)
			if(tbl[i][j] != c && tbl[i][j] != 'T') fl = 0;
		if(fl) return 1;
	}
	int fl = 1;
	for(int i = 0; i < 4; i++)
		if(tbl[i][i] != c && tbl[i][i] != 'T') fl = 0;
	if(fl) return 1;
	fl = 1;
	for(int i = 0; i < 4; i++)
		if(tbl[i][4-i-1] != c && tbl[i][4-i-1] != 'T') fl = 0;
	if(fl) return 1;
	return 0;
}

bool full(){
	for(int i = 0; i < 4; i++) for(int j = 0; j < 4; j++)
		if(tbl[i][j] == '.') return 0;
	return 1;
}

int main (){
	freopen("out.txt", "w", stdout);
	int t; scanf("%d", &t);
	for(int x = 0; x < t; x++){
		printf("Case #%d: ", x+1);
		for(int i = 0; i < 4; i++)
			scanf("%s", tbl[i]);
		if(check('X')){ puts("X won"); continue; }
		if(check('O')){ puts("O won"); continue; }
		if(full()){ puts("Draw"); continue; }
		puts("Game has not completed");
	}
}
