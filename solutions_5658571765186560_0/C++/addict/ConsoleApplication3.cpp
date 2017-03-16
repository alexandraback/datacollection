#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

int check(int x, int r, int c) {
	if (x > r && x > c) {
		return 0;
	}
	if ((r*c) % x) {
		return 0;
	}
	return 1;
}

int solvation(FILE* f1, FILE* f2, int inum) {
	int x, r, c;
	fscanf_s(f1, "%d %d %d", &x, &r, &c);
	if (x >= 7) {
		return 0;
	}
	if (!check(x, r, c)) {
		return 0;
	}
	switch (x) {
		case 3:
			if (r == 1 || c == 1) {
				return 0;
			}
			break;
		case 4:
			if (r < 3 || c < 3) {
				return 0;
			}
			break;
		case 5:
			if (r < 3 || c < 3) {
				return 0;
			}
			if ((r == 3 && c == 5) || (r == 5 && c == 3)) {
				return 0;
			}
			break;
		case 6:
			if (r < 4 || c < 4) {
				return 0;
			}
			break;
	}
	return 1;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int tnum;
	int ans = 0;
	FILE* f1;
	FILE* f2;
	fopen_s(&f1, "in.txt", "r");
	fopen_s(&f2, "out.txt", "w");
	fscanf_s(f1, "%d", &tnum);
	for (int inum = 0; inum < tnum; inum++) {
		ans = solvation(f1, f2, inum);
		if (ans) {
			fprintf_s(f2, "Case #%d: GABRIEL\n", inum + 1);
		}
		else {
			fprintf_s(f2, "Case #%d: RICHARD\n", inum + 1);
		}
	}
	fclose(f1);
	fclose(f2);
	return 0;
}

