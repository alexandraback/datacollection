#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 105;
const int MOD = 1e9+7;

int n, vis[N][N], num[N], rec[N];
char s[N], e[N];
bool flag;

void cat (int x, char* str) {
	int len = strlen(str);

	int p = 0, q = len - 1;
	s[x] = str[p];
	e[x] = str[q];

	while (p < len && str[p] == s[x])
		p++;

	while (q >= 0 && str[q] == e[x])
		q--;

	vis[x][s[x]-'a'] = 1;
	vis[x][e[x]-'a'] = 1;

	if (p > q)
		return ;

	if (e[x] == s[x])
		flag = true;

	char ch = str[p];
	vis[x][ch-'a'] = 1;

	for (int i = p; i <= q; i++) {
		if (str[i] != ch) {
			ch = str[i];
			if (vis[x][ch-'a'])
				flag = true;
			vis[x][ch-'a'] = 1;
		}
	}
}

bool handle () {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 30; j++) {

			char ch = j + 'a';
			if (ch == s[i] || ch == e[i])
				continue;

			if (vis[i][j] && rec[j] > 1)
				return true;
		}
	}
	return false;
}

void init () {
	flag = false;
	scanf("%d", &n);

	memset(vis, 0, sizeof(vis));
	memset(rec, 0, sizeof(rec));

	char str[N];
	for (int i = 0; i < n; i++) {

		scanf("%s", str);
		cat(i, str);

		for (int j = 0; j < 30; j++)
			if (vis[i][j])
				rec[j]++;
	}

	if (handle())
		flag = true;
}

bool judge () {
	int v[N];
	memset(v, 0, sizeof(v));

	char tmp = e[num[0]];
	if (s[num[0]] != tmp)
		v[s[num[0]]-'a'] = 1;

	for (int i = 1; i < n; i++) {
		int x = num[i];

		if (s[x] != tmp) {
			if (v[tmp-'a'])
				return false;
			v[tmp-'a'] = 1;
		}

		if (s[x] != e[x]) {
			if (v[s[x]-'a'])
				return false;
			v[s[x]-'a'] = 1;
		}

		tmp = e[x];
	}

	if (v[tmp-'a'])
		return false;
	return true;
}

int solve () {
	if (flag)
		return 0;

	for (int i = 0; i < n; i++)
		num[i] = i;
	int ans = 0;

	do {
		if (judge())
			ans++;
	} while (next_permutation(num, num + n));
	return ans;
}

int main () {
	int cas;
	scanf("%d", &cas);
	for (int i = 1; i <= cas; i++) {
		init ();
		int ans = solve ();

		printf("Case #%d: %d\n", i, ans % MOD);
	}
	return 0;
}
