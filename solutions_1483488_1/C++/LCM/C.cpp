#include<cstdio>

int a, b, c, d, m[15], e, f;
long long re;
bool u[10000001];

void num(int x) {
	re += x ? x * (x - 1) / 2 : x;
}

void make(int x) {
	if(x == d) {
		f = 0;
		for (int i = 0 ; i < d ; i++) {
			e = 0;
			for (int j = i ; j < d + i ; j++) e = e * 10 + m[j % d];
			if (u[e]) break;
			u[e] = true;
			if (e >= b && e <= c) f++;
			else continue;
		}
		num(f);
		return;
	}
	for (int i = 0 ; i <= 9 ; i++) {
		m[x] = i;
		make(x + 1);
	}
}

int digit(int x) {
	int y = 0;
	while (x) {
		x /= 10;
		y++;
	}
	return y;
}

int main() {
	scanf("%d", &a);
	for (int i = 0 ; i < a ; i++) {
		for (int j = 0 ; j <= 10000000 ; j++) u[j] = false;
		re = 0;
		scanf("%d %d", &b, &c);
		d = digit(b);
		make(0);
		printf("Case #%d: %I64d\n", i + 1, re);
	}
	scanf("\n");
	return 0;
}
