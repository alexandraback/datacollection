#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int R, C, M;
int L;
char res[50][51];

bool solve() {
	for (int i = 0; i < R; ++i)
	{
		memset(res[i], '*', C);
		res[i][C] = '\0';
	}
	L = R*C - M;
	if (L == 0) {
		return true;
	}
	res[0][0] = 'c';
	if (L == 1) {	
		return true;
	}
	if (R == 1) {
		for (int i = 1; i < L; ++i)
		{
			res[0][i] = '.';
		}
		return true;
	}
	if (C == 1) {
		for (int i = 1; i < L; ++i)
		{
			res[i][0] = '.';
		}
		return true;
	}
	int bar = 2*(R+C-2);
	if (L >= bar) {
		for (int i = 0; i < C; ++i) {
			res[0][i] = '.';
			res[1][i] = '.';
		}
		for (int i = 2; i < R; ++i) {
			res[i][0] = '.';
			res[i][1] = '.';
		}
		if (C > 2) {
			int lines = (L-bar)/(C-2);
			for (int i = 2; i <2+lines; ++i) {
				memset(&res[i][2], '.', C-2);
			}
			int remain = (L-bar)%(C-2);
			memset(&res[2+lines][2], '.', remain);
		}
		res[0][0] = 'c';
		return true;
	} else if (L >= 4 && L%2 == 0) {
		int slices = L/2;
		if (slices >= C) {
			memset(res[0], '.', C);
			memset(res[1], '.', C);
			for (int i = 0; i < slices-C; ++i) {
				res[i+2][0] = '.';
				res[i+2][1] = '.';
			}
		} else {
			memset(res[0], '.', slices);
			memset(res[1], '.', slices);
		}
		res[0][0] = 'c';
		return true;
	} else if (L >= 9 && L%2 == 1) {
		if (min(R,C) <= 2) {
			return false;
		} else {
			for (int i = 0; i < 3; ++i) {
				for (int j = 0; j < 3; ++j) {
					res[i][j] = '.';
				}
			}
			int slices = (L-9)/2;
			if (slices > C-3) {
				memset(&res[0][3], '.', C-3);
				memset(&res[1][3], '.', C-3);
				for (int i = 0; i <slices-C+3; ++i) {
					res[i+3][0] ='.';
					res[i+3][1] = '.';
				}
			} else {
				memset(&res[0][3], '.', slices);
				memset(&res[1][3], '.', slices);
			}
			res[0][0] = 'c';
			return true;
		}
	}

	return false;		
}


int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &R);
		scanf("%d", &C);
		scanf("%d", &M);
		bool r = solve();
		printf("Case #%d:\n", i+1);
		if (r)
		{
			for (int j = 0; j < R; ++j)
			{
				printf("%s\n", res[j]);
			}
		} else {
			printf("Impossible\n");
		}
	}
	return 0;
}