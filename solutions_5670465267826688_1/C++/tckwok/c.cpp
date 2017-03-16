#include <cstdio>

#define N (1 << 17)

const int mul[8][8] = {
{0, 1, 2, 3, 4, 5, 6, 7},
{1, 4, 3, 6, 5, 0, 7, 2},
{2, 7, 4, 1, 6, 3, 0, 5},
{3, 2, 5, 4, 7, 6, 1, 0},
{4, 5, 6, 7, 0, 1, 2, 3},
{5, 0, 7, 2, 1, 4, 3, 6},
{6, 3, 0, 5, 2, 7, 4, 1},
{7, 6, 1, 0, 3, 2, 5, 4}
};

int T, n, tr[256];
long long x;
char s[N];
bool si, sk, sn;

int main() {
	tr['i'] = 1; tr['j'] = 2; tr['k'] = 3;
	scanf("%d", &T);
	for (int r = 1; r <= T; ++r) {
		printf("Case #%d: ", r);
		scanf("%d%lld%s", &n, &x, s);
		for (int i = 0; i < n; ++i)
			s[i] = tr[s[i]];
		for (int j = 1; j < 8; ++j)
			for (int i = 0; i < n; ++i)
				s[j*n + i] = s[i];
		for (int i = 1; i < 8*n; ++i)
			s[i] = mul[s[i - 1]][s[i]];
		si = sk = sn = 0;
		if (x < 8) {
			for (int i = 0; i < x*n; ++i)
				if (s[i] == 1) si = 1;
				else if (s[i] == 3 && si) sk = 1;
			sn = (s[x*n - 1] == 4);
		} else {
			x &= 3;
			for (int i = 0; i < 4*n; ++i)
				if (s[i] == 1) si = 1;
				else if (s[i] == 3) sk = 1;
			sn = (x && s[x*n - 1] == 4);
		}
		if (si && sk && sn) puts("YES");
		else puts("NO");
	}
	return 0;
}
