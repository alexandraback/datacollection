#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 10010;
int l, x, a[N];
char s[N];
int mul[10][10];

void fill() {
	mul[1][1] = 1, mul[1][2] = 2, mul[1][3] = 3, mul[1][4] = 4;
	mul[2][1] = 2, mul[2][2] = 9-1, mul[2][3] = 4, mul[2][4] = 9-3;
	mul[3][1] = 3, mul[3][2] = 9-4, mul[3][3] = 9-1, mul[3][4] = 2;
	mul[4][1] = 4, mul[4][2] = 3, mul[4][3] = 9-2, mul[4][4] = 9-1;
	for (int i = 5; i <= 8; ++i)
		for (int j = 1; j <= 4; ++j)
			mul[i][j] = 9 - mul[9-i][j];
	for (int i = 1; i <= 4; ++i)
		for (int j = 5; j <= 8; ++j)
			mul[i][j] = 9 - mul[i][9-j];
	for (int i = 5; i <= 8; ++i)
		for (int j = 5; j <= 8; ++j)
			mul[i][j] = mul[9-i][9-j];
}

int main() {
	int T;
	scanf("%d", &T);
	fill();
	for (int ttt = 1; ttt <= T; ++ttt) {
		scanf("%d%d%s", &l, &x, s);
		bool fi = false, fj = false, fk = false;
		for (int i = 0; i < l; ++i) {
			if (s[i] == '1') a[i] = 1;
			else a[i] = s[i] - 'i' + 2;
		}
		int now = 1;
		for (int i = 0; i < l; ++i) {
			now = mul[now][a[i]];
		}
		
		if (now == 1) {
			fk = false;
		}
		else if (now == 8) {
			if (x % 2) fk = true;
			else fk = false;
		}
		else if (x % 4 == 2) fk = true;
		else fk = false;
		
		if (!fk) {
			printf("Case #%d: NO\n", ttt);
			continue;
		}
		
		if (x > 8) x = 8;
		now = 1;
		for (int r = 0; r < x; ++r) {
			for (int i = 0; i < l; ++i) {
				now = mul[now][a[i]];
				if (!fi) {
					if (now == 2) fi = true;
				}
				else if (now == 4) {
					fj = true;
					break;
				}
			}
		}
		if (fi && fj)
			printf("Case #%d: YES\n", ttt);
		else
			printf("Case #%d: NO\n", ttt);
	}
	return 0;
}