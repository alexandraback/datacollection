#include<cstdio>

int t, k, l, s, bb, ans, com;
char key[10], tar[10], str[10];

int max(int x, int y) {
	return x > y ? x : y;
}

int check(char x[], char y[]) {
	int z = 0;
	for (int i = 0 ; i < s ; i++) {
		for (int j = 0 ; ; j++) {
			if (j == l) {
				z++;
				break;
			}
			if (i + j >= s) break;
			if (x[i + j] != y[j]) break;
		}
	}
	return z;
}

void exhaust(int x, char str[]) {
	if (x == s) {
		int temp = check(str, tar);
		bb = max(bb, temp);
		ans += temp;
		com++;
		return;
	}
	for (int i = 0 ; i < k ; i++) {
		str[x] = key[i];
		exhaust(x + 1, str);
	}
}

int main() {
	freopen("B_small.in", "r", stdin);
	freopen("B_small.out", "w", stdout);
	scanf("%d", &t);
	for (int zzz = 1 ; zzz <= t ; zzz++) {
		bb = ans = com = 0;
		scanf("%d %d %d", &k, &l, &s);
		scanf("%s", key);
		scanf("%s", tar);
		for (int i = 0 ; str[i] ; i++) str[i] = 0;
		exhaust(0, str);
		printf("Case #%d: %Lf\n", zzz, bb - ans * 1. / com);
	}
	scanf("\n");
	return 0;
}
