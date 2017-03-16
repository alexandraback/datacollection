#include<cstdio>

// 1: 1 i: 2 j: 3 k: 4 -1: -1 -i: -2 -j: -3 -k: -4

const int table[5][5] = {0, 0, 0, 0, 0,
						 0, 1, 2, 3, 4,
						 0, 2, -1, 4, -3,
						 0, 3, -4, -1, 2,
						 0, 4, 3, -2, -1};

int t, l, x, f[40005], b[40005], s[40005], il, kl, am[4], rmq[16][10005];
long long pi[14005], pk[14005];
char c[10005];
bool found;

int abs(int x) {
	return x > 0 ? x : -x;
}

int mul(int x, int y) {
	if (x * y > 0) return table[abs(x)][abs(y)];
	else return -table[abs(x)][abs(y)];
}

int rmq_q(int x, int y) {
	int z = 1;
	for (int i = 14 ; i >= 0 ; i--) {
		if ((y - x + 1) & (1 << i)) {
			z = mul(z, rmq[i][x]);
			x += (1 << i);
		}
	}
	return z;
}

int check_xle4(long long x, long long y, int z) {
	if (x / l == y / l) return rmq_q(x, y);
	else {
		int tmp1 = f[y % l], tmp2 = b[z - l + x % l];
		return mul(mul(tmp2, am[y / l - x / l - 1]), tmp1);
	}
}

int check(long long x, long long y, int z) {
	if (x / l == y / l) return rmq_q(x, y);
	else {
		int tmp1 = f[y % l], tmp2 = b[z - l + x % l];
		return mul(mul(tmp2, am[(y / l - x / l - 1) % 4]), tmp1);
	}
}

char toc (int x) {
	switch (x) {
		case 0: return '0';
		case 1: return '1';
		case 2: return 'i';
		case 3: return 'j';
		case 4: return 'k';
	}
}

int main() {
//	freopen("C-small-attempt2.in", "r", stdin);
//	freopen("C-small-attempt2.out", "w", stdout);
	scanf("%d", &t);
	for (int zzz = 1 ; zzz <= t ; zzz++) {
		il = kl = 0;
		found = false;
		am[0] = am[1] = 1;
		scanf("%d %d", &l, &x);
		scanf("%s", c);
		if (x <= 4) {
			for (int i = 0 ; i < l * x ; i++) s[i] = c[i % l] - 'g';
			for (int i = 0 ; i < l * x ; i++) rmq[0][i] = s[i];
			for (int i = 1 ; i <= 15 ; i++)
				for (int j = 0 ; j + (1 << (i - 1)) < l * x ; j++)
					rmq[i][j] = mul(rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1))]);
			am[1] = rmq_q(0, l - 1);
			am[2] = mul(am[1], am[1]);
			am[3] = mul(am[2], am[1]);
			for (int i = 0 ; i < l * x ; i++) f[i] = rmq_q(0, i);
			for (int i = l * x - 1 ; i >= 0 ; i--) b[i] = rmq_q(i, l * x - 1);
			for (int i = 0 ; i < l * x ; i++) {
				if (f[i] == 2) pi[il++] = i;
				if (b[i] == 4) pk[kl++] = i;
			}
			for (int i = 0 ; i < il && !found ; i++)
				for (int k = 0 ; k < kl && !found ; k++)
					if (pi[i] + 1 < pk[k] && check_xle4(pi[i] + 1, pk[k] - 1, l * x) == 3) found = true;
		}
		else {
			for (int i = 0 ; i < l * 4 ; i++) s[i] = c[i % l] - 'g';
			for (int i = 0 ; i < l * 4 ; i++) rmq[0][i] = s[i];
			for (int i = 1 ; i <= 15 ; i++)
				for (int j = 0 ; j + (1 << (i - 1)) < l * 4 ; j++)
					rmq[i][j] = mul(rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1))]);
			am[1] = rmq_q(0, l - 1);
			am[2] = mul(am[1], am[1]);
			am[3] = mul(am[2], am[1]);
			for (int i = 0 ; i < l * 4 ; i++) f[i] = rmq_q(0, i);
			for (int i = l * 4 - 1 ; i >= 0 ; i--) b[i] = rmq_q(i, l * 4 - 1);
			for (int i = 0 ; i < l * 4 ; i++) {
				if (f[i] == 2) pi[il++] = i;
				if (b[i] == 4) pk[kl++] = i + l * (x - 4);
			}
			for (int i = 0 ; i < il && !found ; i++)
				for (int k = 0 ; k < kl && !found ; k++)
					if (pi[i] + 1 < pk[k] && check(pi[i] + 1, pk[k] - 1, l * 4) == 3) found = true;
/*			for (int i = 0 ; i < l * 4 ; i++) printf("%s%c ", f[i] == abs(f[i]) ? "" : "-", toc(abs(f[i])));
			printf("\n");
			for (int i = 0 ; i < l * 4 ; i++) printf("%s%c ", b[i] == abs(b[i]) ? "" : "-", toc(abs(b[i])));
			printf("\n");
*/		}
		if (found) printf("Case #%d: YES\n", zzz);
		else printf("Case #%d: NO\n", zzz);
	}
	scanf("\n");
	return 0;
}
