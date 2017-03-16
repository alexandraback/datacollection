#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
using namespace std;

int myabs(int x) {
	return x > 0 ? x : -x;
}

int sign(int x) {
	return x < 0 ? -1 : x > 0;
}

int id[1111];
int l;
long long x;
char str[111111];
const int table[5][5] = {
0, 0, 0, 0, 0,
0, 1, 2, 3, 4,
0, 2, -1, 4, -3,
0, 3, -4, -1, 2,
0, 4, 3, -2, -1
};
int pos;

//int flag = 0;

struct Calc {
	int x;
	Calc(int _x = 0) : x(_x) {}
	Calc operator * (const Calc &p) const {
//if (flag <= 100) {
//++flag;
//cout << endl << x << ' ' << p.x << ' ' << sign(x) * sign(p.x) * table[myabs(x)][myabs(p.x)];
//}
		return sign(x) * sign(p.x) * table[myabs(x)][myabs(p.x)];
	}
} now;

Calc pow(Calc a, long long b) {
	Calc ret(1);
	while (b) {
		if (b & 1LL) ret = ret * a;
		a = a * a, b >>= 1LL;
	}
	return ret;
}

int main() {
	freopen("C_.in", "r", stdin);
	freopen("C.out", "w", stdout);
	int TT;
	scanf("%d", &TT);
	id['i'] = 2;
	id['j'] = 3;
	id['k'] = 4;
	for (int T = 1; T <= TT; ++T) {
		scanf("%d %lld", &l, &x);
		scanf("%s", str + 1);
		pos = 0;
		printf("Case #%d: ", T);
		now = Calc(1);
		if (x <= 16) {
			pos = 0;
			for (int i = 1; i <= x * l; ++i) {
				now = now * Calc(id[str[(i - 1) % l + 1]]);
//assert(now.x);
//assert(2 <= id[str[(i - 1) % l + 1]] && id[str[(i - 1) % l + 1]] <= 4);
				if (pos == 0 && (now.x == id['i'] || now.x == -id['i'])) {
//puts("");
//printf("%d\n", i);
					++pos;
				}
				else if (pos == 1 && (now.x == table[id['i']][id['j']] || now.x == -table[id['i']][id['j']])) {
//printf("%d\n", i);
					++pos;
				}
			}
			if (pos == 2 && now.x == -1) puts("YES");
			else puts("NO");
		}
		else {
			Calc tmp;
			for (int i = 1; i <= 16 * l; ++i) {
				now = now * Calc(id[str[(i - 1) % l + 1]]);
				if (i == l) tmp = now;
				if (pos == 0 && (now.x == id['i'] || now.x == -id['i'])) {
//puts("");
//printf("%d\n", i);
					++pos;
				}
				else if (pos == 1 && (now.x == table[id['i']][id['j']] || now.x == -table[id['i']][id['j']])) {
//printf("%d\n", i);
					++pos;
				}
			}
			if (pos != 2) puts("NO");
			else {
				now = pow(tmp, x);
				if (now.x == -1) puts("YES");
				else puts("NO");
			}
		}
	}
	return 0;
}
