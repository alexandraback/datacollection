#include <cstdio>
using namespace std;

int a[6][6];
int dx[] = {1, 0, 1, -1};
int dy[] = {0, 1, 1, 1};

bool check(int b){
	for(int i = 1; i <= 4; ++i)
	for(int j = 1; j <= 4; ++j)
	for(int k = 0; k < 4; ++k){
		int c = 0;
		for(int y = i, x = j; a[y][x] & b; y += dy[k], x += dx[k]){
			++c;
		}
		if(c == 4){ return true; }
	}
	return false;
}

const char *solve(){
	bool end = true;
	char s[10] = {};
	for(int i = 1; i <= 4; ++i){
		scanf(" %s", s);
		for(int j = 0; j < 4; ++j){
			int u = 0;
			if(s[j] == 'X'){
				u = 1;
			}
			else if(s[j] == 'O'){
				u = 2;
			}
			else if(s[j] == 'T'){
				u = 3;
			}
			else{
				end = false;
			}
			a[i][j + 1] = u;
		}
	}

	if(check(1)){
		return "X won";
	}
	if(check(2)){
		return "O won";
	}
	if(end){
		return "Draw";
	}
	return "Game has not completed";
}

int main(){
	int T;
	scanf("%d", &T);
	for(int i = 1; i <= T; ++i){
		printf("Case #%d: %s\n", i, solve());
	}
}
