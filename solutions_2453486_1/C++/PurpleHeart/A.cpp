#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int cases;
char gao[5][5];

int find(int x, int y, int dx, int dy, char p){
	int nowx = x, nowy = y, ret = 0;
	while(nowx >= 0 && nowx < 4 && nowy >= 0 && nowy < 4 && gao[nowx][nowy] == p){
		ret++;
		nowx += dx;
		nowy += dy;
	}
	return ret;
}

bool check(char p){
	for(int i = 0; i < 4; ++i)
		for(int j = 0; j < 4; ++j)
			if(gao[i][j] == p){
				int cnt = max(max(max(
						find(i, j, 0, -1, p) + find(i, j, 0, 1, p) - 1,
						find(i, j, -1, 0, p) + find(i, j, 1, 0, p) - 1),
						find(i, j, -1, -1, p) + find(i, j, 1, 1, p) - 1), 
						find(i, j, 1, -1, p) + find(i, j, -1, 1, p) - 1);
				if(cnt == 4) return true;
			}
	return false;
}

int main(){
	scanf("%d", &cases);
	char ch;
	scanf("%c", &ch);
	for(int xx = 1; xx <= cases; ++xx){
		for(int i = 0; i < 4; ++i)
			scanf("%s", gao[i]);
		printf("Case #%d: ", xx);
		int cntx = 0, cnto = 0, cntempty = 0, tx = -1, ty = -1;
		for(int i = 0; i < 4; ++i)
			for(int j = 0; j < 4; ++j){
				if(gao[i][j] == 'X') cntx++;
				else if(gao[i][j] == 'O') cnto++;
				else if(gao[i][j] == 'T'){
					tx = i;
					ty = j;
				}else if(gao[i][j] == '.'){
					cntempty++;
				}
			}
		if(cntx > cnto){
			if(tx != -1){
				gao[tx][ty] = 'X';
			}
			bool ok = check('X');
			if(ok){
				puts("X won");
			}else if(!cntempty){
				puts("Draw");
			}else puts("Game has not completed");
		}else{
			if(tx != -1){
				gao[tx][ty] = 'O';
			}
			bool ok = check('O');
			if(ok){
				puts("O won");
			}else if(!cntempty){
				puts("Draw");
			}else puts("Game has not completed");
		}
	}
}
