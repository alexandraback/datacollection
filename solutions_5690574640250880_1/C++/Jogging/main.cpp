#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int T;
FILE *in, *out;
int r, c, m;
char a[54][54];

bool special1() {
	a[0][0] = 'c';
	int diff = r*c - m;
	if (c == 1) for (int i=1; i < diff; i++) a[i][0] = '.';
	else for (int j=1; j < diff; j++) a[0][j] = '.';
	return true;
}

bool special2() {
	int diff = r*c - m;
	if (diff > 1 && diff%2 == 1 || diff == 2) return false;
	if (c == 2) for (int i=0; i < diff/2; i++) a[i][0] = a[i][1] = '.';
	else for (int j=0; j < diff/2; j++) a[0][j] = a[1][j] = '.';
	a[0][0] = 'c';
	return true;
}

bool solve(int cs) {
	if (r == 1 || c == 1) return special1();
	if (r == 2 || c == 2) return special2();
	int diff = r*c - m;
	if (diff < 4 && diff > 1) return false;
	a[0][0] = 'c';
	if (diff == 1) return true;
	if (diff == 5 || diff == 7) return false;
	a[0][1] = a[1][0] = a[1][1] = '.';
	if (diff == 4) return true;
	a[0][2] = a[1][2] = '.';
	if (diff == 6) return true;
	a[2][0] = a[2][1] = '.';
	if (diff == 8) return true;
	int cnt = 8;
	for (int j=3; j < c && cnt+2 <= diff; j++) {
		a[0][j] = a[1][j] = '.';
		cnt += 2;
	}
	if (cnt == diff) return true;
	if (cnt+1 == diff) { a[2][2] = '.'; return true; }
	for (int i=3; i < r && cnt+2 <= diff; i++) {
		a[i][0] = a[i][1] = '.';
		cnt += 2;
	}
	for (int i=2; i < r && cnt < diff; i++) {
		for (int j=2; j < c && cnt < diff; j++) {
			a[i][j] = '.';
			cnt++;
		}
	}
	return true;
}

int main()
{
	in = fopen("in.txt", "r");
	out = fopen("out.txt", "w");
	fscanf(in, "%d", &T);
	for (int cs=1; cs <= T; cs++) {
		fscanf(in, "%d%d%d", &r, &c, &m);
		for (int i=0; i < r; i++) {
			for (int j=0; j < c; j++) a[i][j] = '*';
			a[i][c] = '\0';
		}
		fprintf(out, "Case #%d:\n", cs);
		if (solve(cs)) for (int i=0; i < r; i++) fprintf(out, "%s\n", a[i]);
		else fprintf(out, "Impossible\n");
	}
	return 0;
}
