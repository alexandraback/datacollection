#include <cstdio>

char grd[5][5];

bool chk(char c) {
	for(int i = 0; i < 4; ++i) {
		int tCnt = 0;
		bool flg = true;
		for(int j = 0; j < 4; ++j) 
			if(grd[i][j] == 'T') ++tCnt;
			else if(grd[i][j] != c) flg = false;
		if(flg && tCnt <= 1) return true;
	}
	for(int i = 0; i < 4; ++i) {
		int tCnt = 0;
		bool flg = true;
		for(int j = 0; j < 4; ++j) 
			if(grd[j][i] == 'T') ++tCnt;
			else if(grd[j][i] != c) flg = false;
		if(flg && tCnt <= 1) return true;
	}
	int tCnt = 0;
	bool flg = true;
	for(int i = 0; i < 4; ++i) 
		if(grd[i][i] == 'T') ++tCnt;
		else if(grd[i][i] != c) flg = false;
	if(flg && tCnt <= 1) return true;
	
	tCnt = 0;
	flg = true;
	for(int i = 0; i < 4; ++i) 
		if(grd[i][3 - i] == 'T') ++tCnt;
		else if(grd[i][3 - i] != c) flg = false;
	if(flg && tCnt <= 1) return true;
	
	return false;
}

bool chkDraw() {
	for(int i = 0; i < 4; ++i)
		for(int j = 0; j < 4; ++j)
			if(grd[i][j] == '.') return false;
	return true;
}

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t) {
		for(int i = 0; i < 4; ++i)
			scanf("%s", grd[i]);
		printf("Case #%d: ", t);
		if(chk('X')) puts("X won");
		else if(chk('O')) puts("O won");
		else if(chkDraw()) puts("Draw");
		else puts("Game has not completed");
	}
}
