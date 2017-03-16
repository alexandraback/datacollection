#include <cstdio>
#include <algorithm>
using namespace std;

#define N 128
#define P 1000000007

int T, n, fre[26], p[N], cc, len[N], e1[26], e2[26], lab[26], t;
char c[N][256], tmpstr[N*256];
bool f, done[N], vis[26], used[26][N];
long long ans, fac[N];

void debug(char *s, int len) {
	printf("DEBUG: ");
	for (int i = 0; i < len; ++i)
		putchar(s[i] + 'a');
	puts("");
}

int anc(int x) {
	while (x != p[x]) x = p[x] = p[p[x]];
	return x;
}

void ins(char *s, int len) {
	for (int j = 0; j < len; ++j)
		tmpstr[t + j] = s[j];
	t += len;
}

int main() {
	fac[0] = 1;
	for (int i = 1; i < N; ++i)
		fac[i] = i*fac[i - 1]%P;
	scanf("%d", &T);
	for (int r = 1; r <= T; ++r) {
		printf("Case #%d: ", r);
		scanf("%d", &n);
		for (int k = 0; k < 26; ++k) {
			fre[k] = 0;
			vis[k] = 0;
			for (int i = 0; i < n; ++i)
				used[k][i] = 0;
		}
		for (int i = 0; i < n; ++i)
			p[i] = i;
		for (int i = 0; i < n; ++i) {
			scanf("%s", c[i]);
			len[i] = -1;
			while (c[i][++len[i]]);
			for (int j = 0; j < len[i]; ++j) c[i][j] -= 'a';
			bool f = 1;
			for (int j = 1; j < len[i]; ++j)
				if (c[i][j] != c[i][j - 1]) {
					vis[c[i][j]] = 1;
					vis[c[i][j - 1]] = 1;
					f = 0;
					used[c[i][j]][i] = used[c[i][j - 1]][i] = 1;
				}
			if (f) {
				++fre[c[i][0]];
				--n;
				--i;
			}
		}
		for (int k = 0; k < 26; ++k) {
			t = -1;
			for (int i = 0; i < n; ++i) if (used[k][i])
				if (t == -1) t = i;
				else p[anc(t)] = anc(i);
		}
		for (int i = 0; i < n; ++i) done[i] = 0;
		ans = 1;
		cc = 0;
		for (int i = 0; i < n; ++i) if (!done[anc(i)]) {
			done[anc(i)] = 1;
			++cc;
			for (int k = 0; k < 26; ++k) e1[k] = e2[k] = -1;
			for (int j = 0; j < n; ++j) if (anc(i) == anc(j)) {
				if (c[j][0] == c[j][len[j] - 1]
						|| e1[c[j][0]] != -1
						|| e2[c[j][len[j] - 1]] != -1) {
					ans = 0;
					break;
				} else {
					e1[c[j][0]] = c[j][len[j] - 1];
					e2[c[j][len[j] - 1]] = c[j][0];
					lab[c[j][0]] = j;
				}
			}
			if (ans == 0) break;
			t = 0;
			for (int k = 0; k < 26; ++k)
				if (e1[k] != -1 && e2[k] == -1) ++t;
			if (t == 0 || t > 1) ans = 0;
			else {
				t = 0;
				for (int k = 0; k < 26; ++k)
					if (e1[k] != -1 && e2[k] == -1) {
						do {
//							puts("");
//							for (int z = 0; z < 26; ++z) printf("%3d", e1[z]); puts("");
//							for (int z = 0; z < 26; ++z) printf("%3d", e2[z]); puts("");
//							puts("");
							ins(c[lab[k]], len[lab[k]]);
//							debug(tmpstr, t);
							if (e1[e1[k]] == -1) break;
							k = e1[k];
						} while (1);
						break;
					}
				t = unique(tmpstr, tmpstr + t) - tmpstr;
//				debug(tmpstr, t);
				for (int k = 0; k < 26; ++k) e1[k] = 0;
				for (int j = 0; j < t; ++j) ++e1[tmpstr[j]];
				for (int k = 0; k < 26; ++k) if (e1[k] > 1) ans = 0;
			}
			if (ans == 0) break;
		}
		for (int k = 0; k < 26; ++k) if (fre[k] && !vis[k]) ++cc;
		ans *= fac[cc];
		for (int k = 0; k < 26; ++k) ans = ans*fac[fre[k]]%P;
		printf("%lld\n", ans);
	}
	return 0;
}
