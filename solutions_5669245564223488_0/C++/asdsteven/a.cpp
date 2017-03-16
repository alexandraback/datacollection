#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <vector>
using namespace std;

char s[100][10001];
int len[100];
long long f[10001];
long long M = 1000000007;

long long solve() {
	vector<int> x(26);
	vector<int> head(26);
	vector<int> tail(26);
	map<int, int> z;
	set<int> y;
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf("%s", s[i]);
	for (int i = 0; i < N; ++i) {
		len[i] = strlen(s[i]);
		bool same = true;
		for (int j = 1; j < len[i]; ++j)
			if (s[i][j] != s[i][0])
				same = false;
		if (same)
			++x[s[i][0] - 'a'];
		else if (s[i][0] == s[i][len[i] - 1] || z.count(s[i][0] - 'a'))
			return 0;
		else {
			z[s[i][0] - 'a'] = s[i][len[i] - 1] - 'a';
			++head[s[i][0] - 'a'];
			++tail[s[i][len[i] - 1] - 'a'];
			if (tail[s[i][len[i] - 1] - 'a'] > 1)
				return 0;
			y.insert(s[i][0]);
			y.insert(s[i][len[i] - 1]);
		}
	}
	for (int i = 0; i < N; ++i) {
		int l = 0;
		while (s[i][l] == s[i][0])
			++l;
		int r = len[i] - 1;
		while (s[i][r] == s[i][len[i] - 1])
			--r;
		while (l <= r) {
			char c = s[i][l];
			if (y.count(c))
				return 0;
			y.insert(c);
			while (s[i][l] == c)
				++l;
		}
	}
	long long ans = 1;
	int cnt = 1;
	while (!z.empty()) {
		int i = 0;
		while (i < 26 && (!z.count(i) || tail[i] != 0))
			++i;
		if (i == 26)
			return 0;
		ans = ans * cnt % M;
		ans = ans * f[x[i]] % M;
		ans = ans * f[x[z[i]]] % M;
		x[i] = x[z[i]] = 0;
		while (head[z[i]]) {
			int j = i;
			i = z[i];
			z.erase(j);
			ans = ans * f[x[z[i]]] % M;
			x[z[i]] = 0;
		}
		z.erase(i);
		++cnt;
	}
	for (int i = 0; i < 26; ++i)
		if (x[i] > 0) {
			ans = ans * cnt % M;
			ans = ans * f[x[i]] % M;
			++cnt;
		}
	return ans;
}

int main() {
	f[0] = 1;
	for (int i = 1; i <= 10001; ++i)
		f[i] = i * f[i - 1] % 1000000007;
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; ++i)
		printf("Case #%d: %lld\n", i, solve());
}
