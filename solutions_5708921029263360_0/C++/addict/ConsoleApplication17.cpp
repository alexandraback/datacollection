#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int solvation(FILE* f1, FILE* f2, int inum, int iter, int &j, int &p, int &s, int &k) {
	int ans = 0;
	int a, b, c;
	int la = 0, lb = 0, lc = 0;
	int ap[10][10], as[10];
	for (a = 0; a < 10; a++){
		for (b = 0; b < 10; b++){
			ap[a][b] = 0;
		}
	}
	if (!iter) {
		fscanf_s(f1, "%d %d %d %d", &j, &p, &s, &k);
	}
	int acheck = 0;
	for (a = 0; a < j; a++) {
		int bcheck = 0;
		lc = 0;
		for (int i = 0; i < 10; i++){
			as[i] = 0;
		}
		for (b = 0; b < p; b++) {
			for (c = 0; c < s; c++) {
				if (c >= k) {
					break;
				}
				ap[lb][lc]++;
				if (ap[lb][lc] > k) {
					continue;
				}
				as[lc]++;
				if (as[lc] > k) {
					bcheck = 1;
					break;
				}
				if (iter) {
					fprintf_s(f2, "%d %d %d\n", la+1, lb+1, lc+1);
				}
				else {
					ans++;
				}
				lc++;
				if (lc >= s) {
					lc = 0;
				}
			}
			lb++;
			if (lb >= p) {
				lb = 0;
			}
			if (bcheck) {
				break;
			}
		}
		if (acheck) {
			break;
		}
		la++;
		if (la >= j) {
			la = 0;
		}
	}
	return ans;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int tnum;
	int ans = 0;
	int j = 0, p = 0, s = 0, k = 0;
	FILE* f1;
	FILE* f2;
	fopen_s(&f1, "in.txt", "r");
	fopen_s(&f2, "out.txt", "w");
	fscanf_s(f1, "%d", &tnum);
	for (int inum = 0; inum < tnum; inum++) {
		ans = solvation(f1, f2, inum, 0, j, p, s, k);
		fprintf_s(f2, "Case #%d: %d\n", inum + 1, ans);
		ans = solvation(f1, f2, inum, 1, j, p, s, k);
	}
	fclose(f1);
	fclose(f2);
	return 0;
}