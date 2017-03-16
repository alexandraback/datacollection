#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <functional>
using namespace std;

#pragma comment(linker,"/STACK:100000000")

const int MODULO = (int)1e9 + 7;

bool use[205];
long long comb[10005][10005];
long long fact[20005];
string s[205];
int cnt[305], beg[305], end[305];
int type[205];
int inside[205], all[205];

bool check(string cur_str, char c) {
//	cout << cur_str << " " << c << endl;
	bool same = true;
	int len = cur_str.size();
	for (int u = 0; u < len; ++u) {
		if (cur_str[u] != c) {
			same = false;
			break;
		}
	}
	return same;
}

void solve(int T) {
	int n;
	scanf("%d", &n);
	int len = 0;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		len += s[i].size();
		use[i] = false;
	}
	fact[0] = 1;
	for (int i = 1; i <= len; ++i) {
		fact[i] = fact[i - 1] * i % MODULO;
	}
	printf("Case #%d: ", T);
	for (int i = 0; i < n; ++i) {
		inside[i] = 0;
		all[i] = 0;
		for (int j = 0; j < s[i].size(); ++j) {
			if (s[i][j] != s[i][0] && s[i][j] != s[i][s[i].size() - 1]) {
				inside[i] |= (1 << (s[i][j] - 'a'));
			}
			all[i] |= (1 << (s[i][j] - 'a'));
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i != j && (inside[i] & all[j])) {
				printf("0\n");
				return;
			}
		}
	}
	memset(cnt, 0, sizeof(cnt));
	memset(beg, 0xff, sizeof(beg));
	memset(end, 0xff, sizeof(end));
	for (int i = 0; i < n; ++i) {
		if (check(s[i], s[i][0])) {
			type[i] = 1;
			cnt[s[i][0]]++;
		} else {
//			printf("%d %d\n", i, 2);
			type[i] = 2;
			if (beg[s[i][0]] != -1) {
				printf("0\n");
				return;
			} else {
				beg[s[i][0]] = i;
			}
			if (end[s[i][s[i].size() - 1]] != -1) {
				printf("0\n");
				return;
			} else {
				end[s[i][s[i].size() - 1]] = i;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		if (!use[i] && type[i] == 2) {
			int cur = i;
			int start = i;
			while (cur != -1) {
				use[cur] = true;
//				printf("%d %c\n", cur, s[cur][s[cur].size() - 1]);
				cur = beg[s[cur][s[cur].size() - 1]];
				if (cur == start)
					break;
			}
			if (cur != -1) {
				printf("0\n");
				return;
			}
		}
	}
	int block_cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (type[i] == 2 && end[s[i][0]] == -1) {
			block_cnt++;
		}
	}
	set <char> type1;
	for (int i = 0; i < n; ++i) {
		if (type[i] == 1 && beg[s[i][0]] == -1 && end[s[i][0]] == -1) {
			type1.insert(s[i][0]);
		}
	}
	int type1_cnt = type1.size();
	long long ans = 1;
	for (char c = 'a'; c <= 'z'; ++c) {
		ans = ans * fact[cnt[c]] % MODULO;
	}
	ans = ans * fact[block_cnt] % MODULO;
	ans = ans * comb[block_cnt + type1_cnt][block_cnt] % MODULO;
	printf("%lld\n", ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	for (int i = 0; i <= 10000; ++i) {
		comb[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MODULO;
		}
	}
	for (int i = 0; i < T; ++i) {
		solve(i + 1);
	}
	return 0;
}