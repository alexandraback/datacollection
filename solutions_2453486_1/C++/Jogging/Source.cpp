#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;

FILE *in, *out;
char a[6][6];
char pl[] = "XO";

int solve() {
	int s=-1, t=-1, mrk=0;
	char c;
	for (int i=0; i < 4; i++) {
		for (int j=0; j < 4; j++) {
			if (a[i][j]=='T') {
				s = i;
				t = j;
			} else if (a[i][j]=='.') {
				mrk = 1;
			}
		}
	}
	if (s==-1) s=t=5;
	for (int k=0; k < 2; k++) {
		c = pl[k];
		a[s][t] = c;
		int i;
		for (i=0; i < 4; i++) {
			int j;
			for (j=0; j < 4; j++) {
				if (a[i][j] != c) break;
			}
			if (j==4) return k;
			for (j=0; j < 4; j++) {
				if (a[j][i] != c) break;
			}
			if (j==4) return k;
		}
		for (i=0; i < 4; i++) {
			if (a[i][i] != c) break;
		}
		if (i==4) return k;
		for (i=0; i < 4; i++) {
			if (a[i][3-i] != c) break;
		}
		if (i==4) return k;
	}
	if (mrk) return 2;
	return 3;
}

int main()
{
	in = fopen("jam.in", "r");
	out = fopen("jam.out", "w");
	int T;
	fscanf(in, "%d", &T);
	for (int c=1; c <= T; c++) {
		fprintf(out, "Case #%d: ", c);
		for (int i=0; i < 4; i++) {
			fscanf(in, "%s", a[i]);
		}
		switch (solve()) {
		case 0:
			fprintf(out, "X won\n");
			break;
		case 1:
			fprintf(out, "O won\n");
			break;
		case 2:
			fprintf(out, "Game has not completed\n");
			break;
		case 3:
			fprintf(out, "Draw\n");
			break;
		}
	}
	return 0;
}
