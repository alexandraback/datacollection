#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007ll;

bool loop;
int n, nn;
string s[128], ss[128];
int f[256];
vector<string> ms;
int num[256];
bool edge[128][128], used[256];
bool visited[128], finished[128];
int gp[128];

bool check() {
	for (int i = 0; i < n; i++) {
		memset(f, 0, sizeof f);
		string us = "";
		char prev = '\0';
		for (int k = 0; k < s[i].length(); k++)
			if (s[i][k] != prev) {
				char curr = s[i][k];
				us += curr;
				prev = curr;
				f[curr]++;
			}
		ss[i] = us;
		for (char c = 'a'; c <= 'z'; c++)
			if (f[c] > 1)
				return false;
		for (int kk = 1; kk < us.length() - 1; kk++) {
			char c = us[kk];
			for (int j = 0; j < n; j++)
				if (i != j) {
					for (int k = 0; k < s[j].length(); k++)
						if (s[j][k] == c)
							return false;
				}
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) {
			memset(f, 0, sizeof f);
			for (int k = 0; k < ss[i].length(); k++)
				f[ss[i][k]]++;
			for (int k = 0; k < ss[j].length(); k++)
				f[ss[j][k]]++;
			int cnt = 0;
			for (char c = 'a'; c <= 'z'; c++)
				if (f[c] > 1)
					cnt++;
			if (cnt >= 2)
				return false;
		}

	// check first letter
	memset(f, 0, sizeof f);
	for (int i = 0; i < n; i++)
		if (ss[i].length() >= 2)
			f[ss[i][0]]++;
	for (char c = 'a'; c <= 'z'; c++)
		if (f[c] > 1)
			return false;

	// check last letter
	memset(f, 0, sizeof f);
	for (int i = 0; i < n; i++)
		if (ss[i].length() >= 2)
			f[ss[i][ss[i].length()-1]]++;
	for (char c = 'a'; c <= 'z'; c++)
		if (f[c] > 1)
			return false;

	return true;
}

void DFS(int u) {
	visited[u] = true;
	for (int v = 0; v < nn; v++)
		if (edge[u][v]) {
			if (!visited[v])
				DFS(v);
			else if (!finished[v])
				loop = true;
		}
	finished[u] = true;
}

int find_parent(int u) {
	if (gp[u] == u)
		return u;
	return gp[u] = find_parent(gp[u]);
}

inline bool chain(const string& s1, const string& s2) {
	return (s1[0] == s2[s2.length()-1]) || (s1[s1.length()-1] == s2[0]);
}

ll get_combo(int n) {
	ll ret = 1ll;
	for (int i = 1; i < n; i++) {
		ret *= 2ll;
		ret %= MOD;
	}
	return ret;
}

bool in_group(char c, int id) {
	memset(f, 0, sizeof f);
	for (int i = 0; i < nn; i++)
		if (find_parent(i) == id)
			for (int k = 0; k < ms[i].length(); k++)
				f[ms[i][k]]++;
	return f[c] > 0;
}

ll fib(int n) {
	ll ret = 1ll;
	for (int i = 2; i <= n; i++) {
		ret *= i;
		ret %= MOD;
	}
	return ret;
}

void solve(int case_no) {
	ll ans = 1ll;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];

	if (!check()) {
		cout << "Case #" << case_no << ": 0" << endl;
		return;
	}

	ms.clear();
	for (int i = 0; i < n; i++)
		if (ss[i].length() >= 2)
			ms.push_back(ss[i]);

	memset(num, 0, sizeof num);
	for (int i = 0; i < n; i++)
		if (ss[i].length() == 1)
			num[ss[i][0]]++;

	memset(edge, 0, sizeof edge);
	nn = ms.size();
	for (int i = 0; i < nn; i++)
		for (int j = 0; j < nn; j++)
			if (i != j && ms[i][ms[i].length()-1] == ms[j][0])
				edge[i][j] = 1;

	loop = false;
	memset(visited, 0, sizeof visited);
	memset(finished, 0, sizeof finished);
	for (int i = 0; i < nn; i++)
		if (!visited[i] && !loop)
			DFS(i);

	if (loop) {
		cout << "Case #" << case_no << ": 0" << endl;
		return;
	}

	for (int i = 0; i < nn; i++)
		gp[i] = i;
	for (int ii = 0; ii < 200; ii++)
		for (int i = 0; i < nn; i++)
			for (int j = 0; j < nn; j++) {
				int pi = find_parent(i);
				int pj = find_parent(j);
				if (pi != pj && chain(ms[i], ms[j])) {
					if (pi < pj)
						gp[pj] = pi;
					else
						gp[pi] = pj;
				}
			}

	memset(used, 0, sizeof used);
	int cnt = 0;
	for (int i = 0; i < nn; i++)
		if (find_parent(i) == i) {
			for (char c = 'a'; c <= 'z'; c++)
				if (num[c] && in_group(c, i)) {
					ans *= fib(num[c]);
					ans %= MOD;
					used[c] = true;
				}
			cnt++;
		}
	for (char c = 'a'; c <= 'z'; c++)
		if (num[c] && !used[c]) {
			cnt++;
			ans *= fib(num[c]);
			ans %= MOD;
		}

	ans *= fib(cnt);
	ans %= MOD;

	cout << "Case #" << case_no << ": " << ans << endl;
}

int main() {
	int t;

	ios::sync_with_stdio(0);

	cin >> t;
	for (int case_no = 1; case_no <= t; case_no++)
		solve(case_no);

	return 0;
}