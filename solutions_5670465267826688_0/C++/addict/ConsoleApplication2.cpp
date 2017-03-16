#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

signed char mult(signed char a, signed char b) {
	int sign = 1;
	if ((a < 0 && b > 0) || (a > 0 && b < 0)) {
		sign = -1;
	}
	switch (abs(a)) {
		case 1:
			return sign * b;
		case 2:
			switch (abs(b)) {
				case 1:
					return sign * 2;
				case 2:
					return -sign;
				case 3:
					return sign * 4;
				case 4:
					return -sign * 3;
			}
		case 3:
			switch (abs(b)) {
				case 1:
					return sign * 3;
				case 2:
					return -sign * 4;
				case 3:
					return -sign;
				case 4:
					return sign * 2;
			}
		case 4:
			switch (abs(b)) {
				case 1:
					return sign * 4;
				case 2:
					return sign * 3;
				case 3:
					return -sign * 2;
				case 4:
					return -sign;
			}
	}
}

int solvation(FILE* f1, FILE* f2, int inum) {
	int ans = 0;
	signed char mul = 1;
	signed char mul_i, mul_j;
	signed char arr[10001];
	int l, x, i, j;
	char c;
	fscanf_s(f1, "%d%d%c", &l, &x, &c);
	int len = 200 * l;
	for (i = 0; i < l; i++) {
		fscanf_s(f1, "%c", &c);
		switch (c) {
			case 'i':	
				arr[i] = 2;
				break;
			case 'j':
				arr[i] = 3;
				break;
			case 'k':
				arr[i] = 4;
				break;
		}
		mul = mult(mul, arr[i]);
	}
	fscanf_s(f1, "%c", &c);
	if (mul == 1) {
		return 0;
	}
	if (mul == -1) {
		if (x % 2 != 1) {
			return 0;
		}
		i = 0; mul_i = 1;
		for (i = 0; i < len; i++) {
			mul_j = 1;
			mul_i = mult(mul_i, arr[i]);
			if (mul_i == 2) {
				for (j = 0; j < len; j++) {
					if (i + j + 2 >= l*x) {
						break;
					}
					mul_j = mult(mul_j, arr[(i + j + 1) % l]);
					if (mul_j == 3) {
						return 1;
					}
				}
			}
		}
	}
	else {
		if (x % 4 != 2) {
			return 0;
		}
		i = 0; mul_i = 1;
		for (i = 0; i < len; i++) {
			mul_j = 1;
			mul_i = mult(mul_i, arr[i % l]);
			if (mul_i == 2) {
				for (j = 0; j < len; j++) {
					if (i + j + 2 >= l*x) {
						break;
					}
					mul_j = mult(mul_j, arr[(i + j + 1) % l]);
					if (mul_j == 3) {
						return 1;
					}
				}
			}
		}
	}
	return 0;
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
			fprintf_s(f2, "Case #%d: YES\n", inum + 1);
		}
		else {
			fprintf_s(f2, "Case #%d: NO\n", inum + 1);
		}

	}
	fclose(f1);
	fclose(f2);
	return 0;
}

