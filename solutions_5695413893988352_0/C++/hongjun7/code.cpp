#include <stdio.h>
#include <math.h>
#include <vector>
#include <set>
#include <map>
#include <string.h>
#include <algorithm>
using namespace std;
int n;
long long res;
char A[22], B[22], C[22], D[22];
/*
void f(int x, int y, long long z) {
	if (x == n + 1) {
		if (z < 0) z = -z;
		if (res == -1 || res > z) {
			res = z;
			strcpy(C + 1, A + 1);
			strcpy(D + 1, B + 1);
		}
		return;
	}
	char a = A[x], b = B[x];
	if (y == 0) {
		for (int i = x; i <= n; i++) {
			if (A[i] != '?' && B[i] != '?') {
				if (A[i] != B[i]) {
					if (A[i] > B[i]) y = -1;
					else y = 1;
					break;
				}
			}
		}
	}
	long long Z;
	if (a != '?' && b != '?') {
		Z = z;
		z = z * 10 + (A[x] - B[x]);
		f(x + 1, z > 0 ? -1 : (z < 0 ? 1 : 0), z);
		z = Z;
	}
	else if (y == 0) {
		if (a == '?' && b == '?') A[x] = B[x] = '0';
		else {
			if (a == '?') A[x] = B[x];
			else B[x] = A[x];
		}
		Z = z;
		z = z * 10 + (A[x] - B[x]);
		f(x + 1, z > 0 ? -1 : (z < 0 ? 1 : 0), z); A[x] = a; B[x] = b;
		z = Z;
	}
	else {
		if (y == -1) {
			if (a == '?' && b == '?') {
				A[x] = B[x] = '0';
				Z = z; z = z * 10 + (A[x] - B[x]);
				f(x + 1, z > 0 ? -1 : (z < 0 ? 1 : 0), z); A[x] = a; B[x] = b;
				z = Z;
				A[x] = '0', B[x] = '9';
				Z = z; z = z * 10 + (A[x] - B[x]);
				f(x + 1, z > 0 ? -1 : (z < 0 ? 1 : 0), z); A[x] = a; B[x] = b;
				z = Z;
				A[x] = '0', B[x] = '1';
				Z = z; z = z * 10 + (A[x] - B[x]);
				f(x + 1, z > 0 ? -1 : (z < 0 ? 1 : 0), z); A[x] = a; B[x] = b;
				z = Z;
			}
			else {
				if (a == '?') A[x] = B[x];
				else B[x] = A[x];
				Z = z; z = z * 10 + (A[x] - B[x]);
				f(x + 1, z > 0 ? -1 : (z < 0 ? 1 : 0), z * 10);
				z = Z;
				if (b == '?') {
					B[x] = '9';
					Z = z; z = z * 10 + (A[x] - B[x]);
					f(x + 1, z > 0 ? -1 : (z < 0 ? 1 : 0), z);
					z = Z;
					A[x] = a; B[x] = b;
				}
				else {
					A[x] = '0'; Z = z; z = z * 10 + (A[x] - B[x]);
					f(x + 1, z > 0 ? -1 : (z < 0 ? 1 : 0), z);
					z = Z;
					A[x] = a; B[x] = b;
				}
			}
		}
		else {
			if (a == '?' && b == '?') {
				A[x] = B[x] = '0';
				Z = z; z = z * 10 + (A[x] - B[x]);
				f(x + 1, z > 0 ? -1 : (z < 0 ? 1 : 0), z * 10); A[x] = a; B[x] = b;
				z = Z;
				A[x] = '9', B[x] = '0';
				Z = z; z = z * 10 + (A[x] - B[x]);
				f(x + 1, z > 0 ? -1 : (z < 0 ? 1 : 0), z); A[x] = a; B[x] = b;
				z = Z;
				A[x] = '1', B[x] = '0';
				Z = z; z = z * 10 + (A[x] - B[x]);
				f(x + 1, z > 0 ? -1 : (z < 0 ? 1 : 0), z); A[x] = a; B[x] = b;
				z = Z;
			}
			else {
				if (a == '?') A[x] = B[x];
				else B[x] = A[x];
				Z = z; z = z * 10 + (A[x] - B[x]);
				f(x + 1, z > 0 ? -1 : (z < 0 ? 1 : 0), z * 10);
				z = Z;
				if (a == '?') {
					A[x] = '9';
					Z = z; z = z * 10 + (A[x] - B[x]);
					f(x + 1, z > 0 ? -1 : (z < 0 ? 1 : 0), z);
					z = Z;
					A[x] = a; B[x] = b;
				}
				else {
					B[x] = '0';
					Z = z; z = z * 10 + (A[x] - B[x]);
					f(x + 1, z > 0 ? -1 : (z < 0 ? 1 : 0), z);
					z = Z;
					A[x] = a; B[x] = b;
				}
			}
		}
	}
}
*/
void f(int x, long long z) {
	if (x == n + 1) {
		if (z < 0) z = -z;
		if (res == -1 || res > z) {
			res = z;
			strcpy(C + 1, A + 1);
			strcpy(D + 1, B + 1);
		}
		return;
	}
	char a = A[x], b = B[x];
	if (A[x] != '?' && B[x] != '?') {
		f(x + 1, z * 10 + (A[x] - B[x]));
		return;
	}
	else if (A[x] == '?' && B[x] == '?') {
		for (char i = '0'; i <= '9'; i++) {
			for (char j = '0'; j <= '9'; j++) {
				A[x] = i; B[x] = j;
				f(x + 1, z * 10 + (A[x] - B[x]));
			}
		}
	}
	else if (A[x] == '?') {
		for (char i = '0'; i <= '9'; i++) {
			A[x] = i;
			f(x + 1, z * 10 + (A[x] - B[x]));
		}
	}
	else {
		for (char i = '0'; i <= '9'; i++) {
			B[x] = i;
			f(x + 1, z * 10 + (A[x] - B[x]));
		}
	}
	A[x] = a; B[x] = b;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T, runs = 0; for (scanf("%d", &T); T--; ) {
		++runs;
		if (runs == 2)
			runs = runs;
		memset(A, 0, sizeof(A));
		memset(B, 0, sizeof(B));
		memset(C, 0, sizeof(C));
		memset(D, 0, sizeof(D));
		printf("Case #%d: ", runs);
		scanf("%s%s", A + 1, B + 1);
		n = strlen(A + 1);
		res = -1;
		//f(1, 0, 0);
		f(1, 0);
		printf("%s %s\n", C + 1, D + 1);
	}
	fcloseall();
	return 0;
}