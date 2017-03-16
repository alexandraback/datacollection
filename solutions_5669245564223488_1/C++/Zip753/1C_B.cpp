#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>

using namespace std;

const long long P = 1000000007;

char s[111][111];
int fact[30];
int pref[30], suf[30];
int inside[30];
int n;
vector<char> block[111];
int f[111]; // next block
int used[111];
int tin[111];

bool sole(char *s) {
	int sz = strlen(s);
	char c = s[0];
	for (int i = 1; i < sz; i++)
		if (c != s[i])
			return false;
	return true;
}

bool many(char *s, char c) {
	vector<int> a;
	int len = strlen(s);
	for (int i = 0; i < len; i++)
		if (s[i] == c)
			a.push_back(i);
	if (a.empty()) return false;
	return a.back() - a[0] != (int)a.size() - 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int qwe;
	scanf("%d\n", &qwe);
	for (int t = 1; t <= qwe; t++) {
		printf("Case #%d: ", t);
		// input
		scanf("%d\n", &n);
		for (int i = 0; i < n; i++)
			scanf("%s", s[i]);
		// zero arrays
		for (int i = 0; i < 26; i++) {
			fact[i] = inside[i] = 0;
			pref[i] = suf[i] = -1;
		}
		for (int i = 0; i < n; i++) {
			block[i].clear();
			f[i] = -1;
			used[i] = tin[i] = 0;
		}
		// check one character many times in one string
		int ans = -1;
		for (int i = 0; ans != 0 && i < n; i++)
			for (char x = 'a'; ans != 0 && x <= 'z'; x++)
				if (many(s[i], x)) {
					ans = 0;
				}
		if (ans == 0) {
			printf("0\n");
			continue;
		}
		// split strings in blocks
		for (int i = 0; i < n; i++) {
			int len = strlen(s[i]);
			int j;
			for (j = 0; j < len;) {
				char c = s[i][j];
				for (j++; j < len && s[i][j] == c; j++);
				block[i].push_back(c);
			}
		}
		// process blocks
		for (int i = 0; ans != 0 && i < n; i++) {
			int sz = (int)block[i].size();
			if (sz == 1) {
				if (inside[block[i][0] - 'a']) {
					ans = 0;
					// printf(">asd %d\n", i);
					break;
				}
				fact[block[i][0] - 'a']++;
			}
			else {
				// add pref
				int c = int(block[i][0] - 'a');
				if (pref[c] != -1 || inside[c]) {
					ans = 0;
					// printf("PREFER\n");
					break;
				}
				else {
					pref[c] = i;
				}
				// add suf
				c = int(block[i].back() - 'a');
				if (suf[c] != -1 || inside[c]) {
					ans = 0;
					// printf("SUFFER\n");
					break;
				}
				else {
					suf[c] = i;
				}
				// process inner
				for (int j = 1; ans != 0 && j < sz - 1; j++) {
					c = int(block[i][j] - 'a');
					if (inside[c] || pref[c] != -1 || suf[c] != -1 || fact[c]) {
						ans = 0;
						// printf("%c INCINERATE\n", c + 'a');
						break;
					}
					else {
						inside[c] = 1;
						// printf("imma in %c\n", c + 'a');
					}
				}
			}
		}
		// for (int i = 0; i < 26; i++)
		// 	printf("%d ", inside[i]);
		if (ans == 0) {
			// printf("blocks ");
			printf("0\n");
			continue;
		}
		// build f
		for (int i = 0; i < 26; i++)
			if (pref[i] != -1 && suf[i] != -1)
				f[pref[i]] = suf[i];
		int tm = 0;
		int comp = 0;
		for (int i = 0; ans != 0 && i < n; i++)
			if (block[i].size() > 1 && !tin[i]) {
				tin[i] = ++tm;
				int cnt = 1;
				bool new_comp = true;
				for (int v = f[i]; v != -1; v = f[v]) {
					cnt++;
					if (tin[v]) {
						if (tm + 2 - tin[v] == cnt)
							ans = 0;
						new_comp = false;
						break;
					}
					else {
						tin[v] = ++tm;
					}
				}
				if (new_comp) comp++;
			}
		if (ans == 0) {
			// printf("dfs ");
			printf("0\n");
			continue;
		}
		// answer
		// printf(">> %d\n", comp);
		// for (int i = 0; i < 26; i++)
		// 	printf("%d ", fact[i]);
		// printf("\n");
		long long answer = 1ll;
		for (int i = 0; i < 26; i++)
			if (fact[i]) {
				if (pref[i] == -1 && suf[i] == -1)
					comp++;
				for (long long j = 1; j <= fact[i]; j++)
					answer = (answer * j) % P;
			}
		// printf(">> new %d\n", comp);
		// printf("> %lld\n", answer);
		for (long long i = 1; i <= comp; i++)
			answer = (answer * i) % P;
		printf("%lld\n", answer);
	}
	return 0;
}
