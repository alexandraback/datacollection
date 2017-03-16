#include <stdio.h>
typedef long long ll;

ll l, x;
char dat[10001];

inline int min(int a, int b) { return (a<b) ? a : b; }

// must be one of 1, i, j, k, -1, -i, -j, -k
char mul(char a, char b) {
	char sign = (a*b>0) ? 1 : -1;
	a = (a>0) ? a : -a;
	b = (b>0) ? b : -b;
	if (a == '1') return sign*b;
	if (b == '1') return sign*a;
	if (a == b) return -sign*'1';
	bool tmp[3] ={0};
	tmp[a-'i'] = tmp[b-'i'] = 1;
	if (b-a != 1 && b-a != -2) sign *= -1;
	for (int i=0; i<3; ++i)
		if (!tmp[i])
			return sign*(i+'i');
	return -1; // never executed
}

char pow(char base, ll exp) {
	exp %= 4;
	if (exp == 0) return '1';
	if (exp == 1) return base;
	if (exp == 2) return mul(base, base);
	return mul(mul(base, base), base);
}

bool solve() {
	char product = '1';
	for (int i=0; i<l; ++i)
		product = mul(product, dat[i]);
	if (pow(product, x) != -'1') return false;
	ll lx = l*x;
	char t = '1';
	int icut = 4*l;
	for (int i=0; i<l; ++i) {
		t = mul(t, dat[i]);
		for (int j=0; j<4; ++j) {
			if (t == 'i' && i+j*l < icut) icut = i+j*l;
			t = mul(product, t);
		}
	}
	if (icut == 4*l || icut >= lx-2) return false;
	int jcut = 8*l;
	t = '1';
	for (int i=0; i<l; ++i) {
		t = mul(t, dat[i]);
		for (int j=0; j<8; ++j) {
			int tmp = i+j*l;
			if (t == 'k' && tmp < jcut && tmp > icut) jcut = tmp;
			t = mul(product, t);
		}
	}
	if (jcut == 8*l || jcut >= lx) return false;
	return true;
}

int main() {
	freopen("qual\\C-large.in", "r", stdin);
	freopen("qual\\C-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int N=1; N<=T; ++N) {
		scanf("%lld%lld", &l, &x);
		scanf("%s", dat);
		printf("Case #%d: ", N);
		puts(solve() ? "YES" : "NO");
	}
	return 0;
}