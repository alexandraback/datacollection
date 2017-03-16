#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

const int MAXN = 10010;
char buf[MAXN];
int table[10][10];
int v[MAXN];

void init() {
	table[1][1] = 1; table[1][2] = 2; table[1][3] = 3; table[1][4] = 4;
	table[2][1] = 2; table[2][2] = -1; table[2][3] = 4; table[2][4] = -3;
	table[3][1] = 3; table[3][2] = -4; table[3][3] = -1; table[3][4] = 2;
	table[4][1] = 4; table[4][2] = 3; table[4][3] = -2; table[4][4] = -1;
}

int multi(int a, int b)
{
	int flg = 1;
	if (a * b < 0) flg = -1;
	return flg * table[abs(a)][abs(b)];
}

int main() {
	int T;
	long long L, X;
	init();
	cin >> T;
	for (int ca = 1 ; ca <= T ; ++ca) {
		cin >> L >> X >> buf;
		printf("Case #%d: ", ca);
		for (int i = 0 ; buf[i] ; ++i)
			switch (buf[i]) {
				case '1': v[i] = 1; break;
				case 'i': v[i] = 2; break;
				case 'j': v[i] = 3; break;
				case 'k': v[i] = 4; break;
			}
		int tmp = 1, tot = 1;
		int i;
		for (i = 0 ; i < L ; ++i) {
			tmp = multi(tmp, v[i]);
		}
		for (i = 0 ; i < X % 4 ; ++i) {
			tot = multi(tot, tmp);
		}
		if (tot != -1) {
			printf("NO\n");
			continue;
		}

		int pl = 0, pr = 0;
		int lv = 1;
		for (i = 0 ; i < L * 4 ; ++i) {
			lv = multi(lv, v[i%L]);
			if (lv == 2) {pl = i+1; break;}
		}
		if (i == L * 4) {
			printf("NO\n");
			continue;
		}

		int rv = 1;
		for (i = 0 ; i < L * 4 ; ++i) {
			rv = multi(v[L-1-i%L], rv);
			if (rv == 4) {pr = i+1; break;}
		}
		if (i == L * 4) {
			printf("NO\n");
			continue;
		}

		if (pl + pr < L * X) printf("YES\n");
		else printf("NO\n"); 
	}
	return 0;
}
