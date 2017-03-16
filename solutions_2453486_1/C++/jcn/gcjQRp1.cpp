#include<stdio.h>

int ntest;
char s[10][10];

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("AL.out", "w", stdout);

	scanf("%d", &ntest);
	for(int test = 1; test <= ntest; test++) {
		for(int i=1; i<=4; i++) {
			scanf("%s", s[i]+1);
		}

		bool X = false;
		bool O = false;
		bool full = true;
		for(int i=1; i<=4; i++) {
			int xx = 0, oo = 0;
			for(int j=1; j<=4; j++) {
				if(s[i][j]=='X') xx++;
				else if(s[i][j]=='O') oo++;
				else if(s[i][j]=='T') { xx++; oo++; }
				else full = false;
			}
			if(xx==4) X = true;
			else if(oo==4) O = true;
		}
		for(int i=1; i<=4; i++) {
			int xx = 0, oo = 0;
			for(int j=1; j<=4; j++) {
				if(s[j][i]=='X') xx++;
				else if(s[j][i]=='O') oo++;
				else if(s[j][i]=='T') { xx++; oo++; }
			}
			if(xx==4) X = true;
			else if(oo==4) O = true;
		}
		for(int i=1; i<=4; i++) {
			int xx = 0, oo = 0;
			for(int j=1; j<=4; j++) {
				if(s[j][j]=='X') xx++;
				else if(s[j][j]=='O') oo++;
				else if(s[j][j]=='T') { xx++; oo++; }
			}
			if(xx==4) X = true;
			else if(oo==4) O = true;
		}
		for(int i=1; i<=4; i++) {
			int xx = 0, oo = 0;
			for(int j=1; j<=4; j++) {
				if(s[j][5-j]=='X') xx++;
				else if(s[j][5-j]=='O') oo++;
				else if(s[j][5-j]=='T') { xx++; oo++; }
			}
			if(xx==4) X = true;
			else if(oo==4) O = true;
		}

		printf("Case #%d: ", test);
		if(X) printf("X won\n");
		else if(O) printf("O won\n");
		else if(full) printf("Draw\n");
		else printf("Game has not completed\n");
	}
	return 0;
}