#include <set>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

const long long mod = 1000000007;
int T, N;
string s[105];
long long f[105] = {1, 1};
int cnt[26];
int a[15];
void solve() {
	memset(cnt, 0, sizeof cnt);
	cin >> N;
	int M = 1;
	int answer = 0;
	for (int i = 0; i < N; ++i) a[i] = i;
	for (int i = 0; i < N; ++i) cin >> s[i];
	set<char> tot;
	for (int i = 0; i < N; ++i) {
		string::iterator it;
		it = unique(s[i].begin(), s[i].end());  
		s[i].resize(distance(s[i].begin(), it));
		for (int j = 0; j < s[i].size(); ++j) tot.insert(s[i][j]);
	}
	// printf("tot = %d\n", tot.size());
	for (int i = 1; i <= N; ++i) M *= i;
	for (int i = 0; i < M; ++i) {
		string t = "";
		for (int i = 0; i < N; ++i) {
			t += s[a[i]];
		}
		string::iterator it;
		it = unique(t.begin(), t.end());  
		t.resize(distance(t.begin(), it));
		// printf("tsize = %d\n", t.size());
		// cout << t << endl;
		if (t.size() > tot.size()) {
			next_permutation(a, a + N);
			continue;
		}
		set<char> h;
		bool flag = true;
		for (int j = 0; j < t.size(); ++j) {
			if (h.find(t[j]) == h.end()) {
				h.insert(t[j]);
			} else {
				flag = false;
				break;
			}
		}
		if (flag) answer ++;
		next_permutation(a, a + N);
	}
	printf("%d\n", answer);
	return;
	for (int i = 0; i < N; ++i) {
		string t = s[i];
		string::iterator it;
		it = unique(t.begin(), t.end());  
		t.resize(distance(t.begin(), it));
		set<char> h;
		for (int j = 0; j < t.size(); ++j) {
			if (h.find(t[j]) == h.end()) {
				h.insert(t[j]);
			} else {
				printf("0\n");
				return;
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		for (char c = 'a'; c <= 'z'; ++c) {
			bool flag = true;
			for (int j = 0; j < s[i].size(); ++j) {
				if (s[i][j] != c) {
					flag = false;
					break;
				}
			}
			if (flag) cnt[c - 'a'] ++;
		}
	}
	bool visited[26];
	memset(visited, false, sizeof visited);
	for (int i = 0; i < N; ++i) {
		int l = s[i].size() - 1, j, k;
		for (j = 1; j < l; ++j) if (s[i][j] != s[i][0]) break;
		for (k = l - 1; k >= 0; --k) if (s[i][k] != s[i][l]) break;
		if (j >= k) continue;
		set<int> h;
		for (l = j; l <= k; ++l) {
			if (visited[s[i][l] - 'a']) {
				printf("0\n");
				return;
			} else {
				h.insert(s[i][l] - 'a');
			}
		}
		for (set<int>::iterator it = h.begin(); it != h.end(); ++it) {
			visited[(*it)] = true;
		}
	}
}
int main() {
	for (int i = 1; i <= 100; ++i)
		f[i] = f[i - 1] * i % mod;
	// freopen("in", "r", stdin);
	freopen("B-small-attempt2.in", "r", stdin);
	freopen("B-small-attempt2.out", "w", stdout);
	cin >> T;
	for (int _ = 1; _ <= T; ++_) {
		printf("Case #%d: ", _);
		solve();
	}
	return 0;
}