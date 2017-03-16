#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>


int solvation(FILE* f1, FILE* f2, int inum) {
	int ans = 0;
	signed char arr[1001];
	int d, i, j, maxp = 0;
	fscanf_s(f1, "%d", &d);
	for (i = 0; i < 1001; i++) {
		arr[i] = 0;
	}
	for (i = 0; i < d; i++) {
		fscanf_s(f1, "%d", &j);
		arr[j]++;
		if (j > maxp) {
			maxp = j;
		}
	}
	ans = maxp;
	int tek = 0;
	while (maxp > 2) {
		tek++;
		arr[maxp]--;
		arr[maxp / 2]++;
		if (maxp % 2 == 1) {
			arr[maxp / 2 + 1]++;
		}
		else {
			arr[maxp / 2]++;
		}
		if (arr[maxp] <= 0) {
			for (i = maxp - 1; i >= 0; i--) {
				if (arr[i] > 0) {
					break;
				}
			}
			maxp = i;
		}
		if (tek + maxp < ans) {
			ans = tek + maxp;
		}
	}
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


