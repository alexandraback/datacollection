#include<cstdio>

struct data {
	int sign;
	int c;

	data(int _sign = 0, int _c = 0) {
		sign = _sign;
		c = _c;
	}

	data(char ch) {
		if (ch == 'i') {
			sign = 0;
			c = 1;
		}
		if (ch == 'j') {
			sign = 0;
			c = 2;
		}
		if (ch == 'k') {
			sign = 0;
			c = 3;
		}
	}

	void print() {
		if (sign == 1) printf("-");
		switch (c) {
		case 0:
			printf("1\n");
			break;
		case 1:
			printf("i\n");
			break;
		case 2:
			printf("j\n");
			break;
		case 3:
			printf("k\n");
			break;
		}
	}

	data operator*(data b) {
		int _sign = 0;
		int _c = 0;
		if (c == 0) {
			_c = b.c;
		} else if (b.c == 0) {
			_c = c;
		} else if (c == b.c) {
			_sign = 1;
			_c = 0;
		} else {
			if (c % 3 == b.c - 1) {
				_c = c ^ b.c;
			} else {
				_sign = 1;
				_c = c ^ b.c;
			}
		}
		return data(sign ^ b.sign ^ _sign, _c);
	}

	bool operator==(data b) {
		return sign == b.sign && c == b.c;
	}

};

int n;
char c[40000];
long long x;

int main() {

	int t;
	scanf("%d", &t);
	for (int ii = 1;ii <= t;ii++) {
		int n;
		scanf("%d%lld%s", &n, &x, &c);

		data res;
		for (int i = 0;i < n;i++) {
			res = res * data(c[i]);
		}
		data temp;
		for (int i = 0;i < x % 4;i++) {
			temp = temp * res;
		}
		if (temp == data(1, 0)) {

			int p = -1;
			res = data();
			for (int i = 0;i < 4;i++) {
				for (int j = 0;j < n;j++) {
					res = res * data(c[j]);
					if (res == data('i')) {
						p = i * n + j + 1;
						break;
					}
				}
				if (p != -1) {
					break;
				}
			}

			int q = -1;
			res = data();
			for (int i = 0;i < 4;i++) {
				for (int j = 0;j < n;j++) {
					res = data(c[n - 1 - j]) * res;
					if (res == data('k')) {
						q = i * n + j + 1;
						break;
					}
				}
				if (q != -1) {
					break;
				}
			}

			if (p == -1 || q == -1) {
				printf("Case #%d: NO\n", ii);
			} else if (p + q >= n * x) {
				printf("Case #%d: NO\n", ii);
			} else {
				printf("Case #%d: YES\n", ii);
			}

		} else {
			printf("Case #%d: NO\n", ii);
		}
	}

	return 0;
}