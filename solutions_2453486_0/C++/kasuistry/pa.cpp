
#include <cstdio>

int win(char s[5][5], char x){
	for(int i=0; i<4; ++i){
		int k = 0;
		int l = 0;
		for(int j=0; j<4; ++j){
			if(s[i][j] == x || s[i][j] == 'T'){
				++ k;
			}
			if(s[j][i] == x || s[j][i] == 'T'){
				++ l;
			}
		}
		if(k == 4 || l == 4){
			return 1;
		}
	}
	int k = 0;
	int l = 0;
	for(int i=0; i<4; ++i){
		if(s[i][i] == x || s[i][i] == 'T'){
			++ k;
		}
		if(s[i][3-i] == x || s[i][3-i] == 'T'){
			++ l;
		}
	}
	if(k == 4 || l == 4){
		return 1;
	}
	return 0;
}
int main(){
	
	int t; scanf("%d", &t);
	char s[5][5];

	for(int testcase=1; testcase <= t; ++testcase){
		for(int i=0; i<4; ++i){
			scanf("%s", s[i]);
		}
		printf("Case #%d: ", testcase);
		if(win(s, 'O')){
			printf("O won\n");
		}else if(win(s, 'X')){
			printf("X won\n");
		}else{
			int k = 0;
			for(int i=0; i<4; ++i){
				for(int j=0; j<4; ++j){
					k += s[i][j] == '.';
				}
			}
			if(k == 0){
				printf("Draw\n");
			}else{
				printf("Game has not completed\n");
			}
		}
	}
	return 0;
}
