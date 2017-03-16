#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

const int N(105), MOD(1000000007);

int ca, n;
int tot[26];
bool bo[26];
int in[N], out[N];
int g[26][26];

int mul(int x, int y) {
	return (long long)x * y % MOD;
}

int jc(int n) {
	return n ? mul(n, jc(n - 1)) : 1;
}

int main() {
	freopen("in.txt", "r", stdin);
	cin >> ca;
	for (int C = 1; C <= ca; ++C) {
		cin >> n;
		memset(tot, 0, sizeof(tot));
		memset(g, 0, sizeof(g));
		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));
		memset(bo, false, sizeof(bo));
		for (int i = 0; i != n; ++i) {
			string s;
			cin >> s;
			bool same = true;
			for (int i = 0; i != s.size(); ++i)
				bo[s[i] - 'a'] = true;
			for (int i = 1; i != s.size(); ++i)
				if (s[i] != s[i - 1]) {
					int u = s[i - 1] - 'a', v = s[i] - 'a';
					++g[u][v];
					++out[u]; ++in[v];
					same = false;
				}
			if (same) ++tot[s[0] - 'a'];
		}
		int ans = 1, in0 = 0;
		for (int i = 0; i != 26; ++i) {
			ans = mul(ans, jc(tot[i]));
			if (in[i] > 1 || out[i] > 1) ans = 0;
			if (in[i] == 0 && bo[i]) ++in0;
		}
		for (int i = 0; i != 26; ++i)
			if (bo[i] && in[i] == 0) {
				bo[i] = false;
				for (int j = i; out[j]; ) {
					for (int k = 0; k != 26; ++k)
						if (g[j][k]) {
							j = k; break;
						}
					bo[j] = false;
				}
			}
		for (int i = 1; i != 26; ++i)
			bo[i] |= bo[i - 1];
		if (bo[25]) ans = 0;
		ans = mul(ans, jc(in0));
		cout << "Case #" << C << ": " << ans << endl;
	}
	return 0;
}