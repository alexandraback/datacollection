#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int g[10][10];

void init() {
	for (int i = 0; i < 4; i ++)
		for (int j = 0; j < 4; j ++) {
			char ch;
			cin >> ch;
			if (ch == '.') g[i][j] = 0; else
			if (ch == 'O') g[i][j] = 1; else
			if (ch == 'X') g[i][j] = 2; else
			if (ch == 'T') g[i][j] = 3;
		}
}

void FillNumber(int num, int &o, int &x, int &t, int &e) {
	if (num == 0) e ++; else
	if (num == 1) o ++; else
	if (num == 2) x ++; else
	if (num == 3) t ++;
}

int winSet(int o, int x, int t, int e) {
	if (x == 4) return 2;
	if (o == 4) return 1;
	if (x == 3 && t == 1) return 2;
	if (o == 3 && t == 1) return 1;
	return 0;
}

int checkWin() {
	int ret = 0;
	for (int i = 0; i < 4; i ++) {
		int o = 0, x = 0, t = 0, e = 0;
		for (int j = 0; j < 4; j ++)
			FillNumber(g[i][j], o, x, t, e);
		if (ret=winSet(o, x, t, e)) return ret;
	}
	for (int j = 0; j < 4; j ++) {
		int o = 0, x = 0, t = 0, e = 0;
		for (int i = 0; i < 4; i ++)
			FillNumber(g[i][j], o, x, t, e);
		if (ret=winSet(o, x, t, e)) return ret;
	}
	int o = 0, x = 0, t = 0, e = 0;
	for (int i = 0; i < 4; i ++) {
		int j = i;
		FillNumber(g[i][j], o, x, t, e);
	}
	if (ret=winSet(o, x, t, e)) return ret;
	o = 0, x = 0, t = 0, e = 0;
	for (int i = 0; i < 4; i ++) {
		int j = 3 - i;
		FillNumber(g[i][j], o, x, t, e);	
	}
	if (ret=winSet(o, x, t, e)) return ret;
	
	return 0;
}

int checkDraw() {
	for (int i = 0; i < 4; i ++)
		for (int j = 0; j < 4; j ++)
			if (g[i][j] == 0) return 0;
	return 1;	
}

int main() {
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int T;
	scanf("%d", &T);
	for (int ti = 1; ti <= T; ti ++) {
		init();
		printf("Case #%d: ", ti);
		int win = checkWin();
		if (win > 0) {
			if (win == 1) printf("O won"); else printf("X won");
		} else {
			if (checkDraw()) printf("Draw"); else printf("Game has not completed");	
		}
		printf("\n");
	}
	return 0;	
}

