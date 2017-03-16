#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int l;
long long x;
char st[11000];
int c[5][5], s[5][5];

void work() {
	cin >> l >> x;
	scanf("%s", st);
	int nowx = 1, nowy = 1;
	bool flag = false;
	int i, k;
	for (k = 0; k < (int)(min(4LL, x)); ++k) {
		for (i = 0; i < l; ++i) {
			int num = st[i] - 'i' + 2;
			nowy *= s[nowx][num];
			nowx = c[nowx][num];
			if (nowx == 2 && nowy == 1) {
				flag = true;
				break;
			}
		}
		if (flag) break;
	}
	if (!flag) {
		printf("NO\n");
		return;
	}
	nowx = 1; nowy = 1;
	flag = false;
	for (++i; i < l; ++i) {
		int num = st[i] - 'i' + 2;
		nowy *= s[nowx][num];
		nowx = c[nowx][num];
		if (nowx == 3 && nowy == 1) {
			flag = true;
			break;
		}
	}
	if (!flag) {
		++k;
		
		for (; k < (int)(min(8LL, x)); ++k) {
			for (i = 0; i < l; ++i) {
				int num = st[i] - 'i' + 2;
				nowy *= s[nowx][num];
				nowx = c[nowx][num];
				if (nowx == 3 && nowy == 1) {
					flag = true;
					break;
				}
			}
			if (flag) break;
		}
	}
	if (!flag) {
		printf("NO\n");
		return;
	}
	
	nowx = 1; nowy = 1;
	for (++i; i < l; ++i) {
		int num = st[i] - 'i' + 2;
		nowy *= s[nowx][num];
		nowx = c[nowx][num];
	}
	
	int res = (int)(((x - (long long)k - 1LL)) % 4LL);
	int xx = 1, y = 1;
	for (int j = 0; j < l; ++j) {
		int num = st[j] - 'i' + 2;
		y *= s[xx][num];
		xx = c[xx][num];
	}
	
	for (int j = 0; j < res; ++j) {
		nowy *= y * s[nowx][xx];
		nowx = c[nowx][xx];
	}
	if (nowx == 4 && nowy == 1) printf("YES\n"); else printf("NO\n");
}

int main() {
	c[1][1] = 1; c[1][2] = 2; c[1][3] = 3; c[1][4] = 4;
	c[2][1] = 2; c[2][2] = 1; c[2][3] = 4; c[2][4] = 3;
	c[3][1] = 3; c[3][2] = 4; c[3][3] = 1; c[3][4] = 2;
	c[4][1] = 4; c[4][2] = 3; c[4][3] = 2; c[4][4] = 1;
	s[1][1] = 1; s[1][2] = 1; s[1][3] = 1; s[1][4] = 1;
	s[2][1] = 1; s[2][2] = -1; s[2][3] = 1; s[2][4] = -1;
	s[3][1] = 1; s[3][2] = -1; s[3][3] = -1; s[3][4] = 1;
	s[4][1] = 1; s[4][2] = 1; s[4][3] = -1; s[4][4] = -1;
	
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i) {
		printf("Case #%d: ", i + 1);
		work();
	}
	return 0;
}
