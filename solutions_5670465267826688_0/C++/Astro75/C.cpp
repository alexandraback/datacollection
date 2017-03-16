#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define REP(i,n) for(int i = 0; i < (n); i++)
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define FORD(i,a,b) for(int i = (a); i >= (b); i--)

using namespace std;

int L, X;
const int MAX = 10000 + 5;
int data[MAX], Left[MAX], Right[MAX];
int table[5][5];

void init() {
	table[1][1] = 1;
	table[2][2] = -1;
	table[3][3] = -1;
	table[4][4] = -1;
	table[1][2] = 2;
	table[1][3] = 3;
	table[1][4] = 4;
	table[2][1] = 2;
	table[3][1] = 3;
	table[4][1] = 4;

	table[2][3] = 4;
	table[3][2] = -4;
	table[2][4] = -3;
	table[4][2] = 3;
	table[3][4] = 2;
	table[4][3] = -2;
}

inline int mult(int a, int b) {
	int sign = 1;
	if (a < 0) {
		sign = -1;
		a = -a;
	}
	if (b < 0) {
		sign = sign * -1;
		b = -b;
	}
	return table[a][b] * sign;
}

bool solve() {
	scanf(" %d %d", &L, &X);
	REP(i, L) {
		char c;
		scanf(" %c", &c);
		if (c == 'i') data[i] = 2;
		if (c == 'j') data[i] = 3;
		if (c == 'k') data[i] = 4;
	}
	if (L*X < 3) return false;
	int cur = 1;
	FOR(i, 0, L-1) {
		cur = mult(cur, data[i]);
		Left[i] = cur;
	}
	cur = 1;
	FORD(i, L-1, 0) {
		cur = mult(data[i], cur);
		Right[i] = cur;
	}
	FOR(i, 1, L) {
		int tmp = i == L ? 1 : Right[i];
		FOR(j, 1, L) {
			tmp = mult(tmp, -data[L-j]);
			int used = 0;
			int a = Left[i-1];
			if (abs(a) != 2) {
				a = mult(Right[0], a);
				used++;
			}
			if (a == -2 && Right[0] != 1) {
				a = 2;
				used += (Right[0] == -1) ? 1 : 2;
			}
			if (a != 2) continue;

			int c = Right[L-j];
			if (abs(c) != 4) {
				c = mult(c, Right[0]);
				used++;
			}
			if (c == -4 && Right[0] != 1) {
				c = 4;
				used += (Right[0] == -1) ? 1 : 2;
			}
			if (c != 4) continue;

			{
				int tmpUsed = used + 2;
				int b1 = i == L ? 1 : Right[i];
				int b2 = j == L ? 1 : Left[L-j-1];
				if (abs(mult(b1,b2)) != 3) {
					b1 = mult(b1, Right[0]);
					tmpUsed++;
				}
				if (mult(b1,b2) == -3 && Right[0] != 1) {
					b1 = -b1;
					tmpUsed += (Right[0] == -1) ? 1 : 2;
				}
				if (mult(b1,b2) == 3)
					if (X >= tmpUsed) {
						if (Right[0] == 1) {
							return true;
						} else if (Right[0] == -1) {
							if ((X - tmpUsed) % 2 == 0)
								return true;
						} else {
							if ((X - tmpUsed) % 4 == 0)
								return true;
						}
					}
			}
			{
				int tmpUsed = used + 1;
				if (i + j >= L) continue;
				// cout << tmp << endl;
				if (tmp == 3)
					if (X >= tmpUsed) {
						if (Right[0] == 1) {
							return true;
						} else if (Right[0] == -1) {
							if ((X - tmpUsed) % 2 == 0)
								return true;
						} else {
							if ((X - tmpUsed) % 4 == 0)
								return true;
						}
					}
			}
		}
	}
	return false;
}

int main() {
	init();
	int t;
	scanf(" %d", &t);
	REP(i, t) {
		printf("Case #%d: %s\n", i+1, solve() ? "YES" : "NO");
	}
}