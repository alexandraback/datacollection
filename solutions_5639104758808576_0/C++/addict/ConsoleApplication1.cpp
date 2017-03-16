#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

int solvation(FILE* f1, FILE* f2, int inum) {
	int ans = 0;
	int sum = 0;
	int smax;
	char c;
	fscanf_s(f1, "%d%c", &smax, &c);
	for (int i = 0; i <= smax; i++) {
		fscanf_s(f1, "%c", &c);
		if (ans + sum < i) {
			ans += i - sum - ans;
		}
		sum += c - 48;
	}
	fscanf_s(f1, "%c", &c);
	return ans;
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
		fprintf_s(f2, "Case #%d: %d\n", inum + 1, ans);
	}
	fclose(f1);
	fclose(f2);
	return 0;
}

