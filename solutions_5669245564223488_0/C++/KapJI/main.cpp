#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 100;

char w[MAXN][2];
int p[MAXN];
char train[100 * MAXN];
string ww[MAXN];

void solve() {
	int n;
	scanf("%d\n", &n);
	/*vector<bool> has(26, false);
	vector<int> middle(26, 0);
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		w[i][0] = s[0];
		w[i][1] = s[s.size() - 1];
		has[w[i][0] - 'a'] = true;
		has[w[i][1] - 'a'] = true;
		int l = 0;
		while (l < s.size() && s[l] == w[i][0]) {
			l++;
		}
		int r = s.size() - 1;
		while (r >= 0 && s[r] == w[i][1]) {
			r--;
		}
		//fprintf(stderr, "%c%c\n", w[i][0], w[i][1]);
		for (int j = l; j <= r; ++j) {
			if (j > l && s[j] == s[j - 1]) {
				continue;
			}
			middle[s[j] - 'a']++;
		}
	}
	for (int i = 0; i < 26; ++i) {
		if ((has[i] && middle[i]) || middle[i] > 1) {
			printf("0");
			return;
		}
	}*/
	for (int i = 0; i < n; ++i) {
		string s, s2;
		cin >> s;
		s2 += s[0];
		for (size_t j = 1; j < s.size(); ++j) {
			if (s[j - 1] == s[j]) {
				continue;
			}
			s2 += s[j];
		}
		ww[i] = s2;
		//cerr << ww[i] << endl;
	}
	for (int i = 0; i < n; ++i) {
		p[i] = i;
	}
	int ans = 0;
	bool end[26];
	do {
		memset(end, 0, sizeof(end));
		bool fail = false;

		/*int len = 2 * n;
		for (int i = 0; i < n; ++i) {
			train[2 * i] = w[p[i]][0];
			train[2 * i + 1] = w[p[i]][1];
		}*/
		int len = 0;
		for (int i = 0; i < n; ++i) {
			for (size_t j = 0; j < ww[p[i]].size(); ++j) {
				train[len++] = ww[p[i]][j];
				
			}
		}
		for (int i = 0; i < len; ++i) {
			if (end[train[i] - 'a']) {
				fail = true;
				break;
			}
			if (i < len - 1 && train[i] != train[i + 1]) {
				end[train[i] - 'a'] = true;
			}
		}
		if (!fail) {
			// for (int i = 0; i < len; ++i) {
			// 	fprintf(stderr, "%c", train[i]);
			// }
			// fprintf(stderr, "\n");
			ans++;
		}
	} while (next_permutation(p, p + n));
	printf("%d", ans);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d\n", &t);
	for (int i = 0; i < t; ++i) {
		fprintf(stderr, "Test: %d\n", i + 1);
		printf("Case #%d: ", i + 1);
		solve();
		printf("\n");
	}
	return 0;
}