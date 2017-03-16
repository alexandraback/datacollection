#include <string>
#include <set>
#include <ctime>
#include <cstdio>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define INF 1000000000

const int MOD = 1000000007;
bool used1[105], used[55];
int n, ans = 0;
int fact[500];
int a[105][105];
int p[105];
int len[105];
string str[105];
int ret = 0;
bool check() {
	int last = -1;
	for (int i = 0; i < 26; ++i) used[i] = false;
	for (int i = 0; i < n; ++i) {
		int u = p[i];
		for (int j = 0; j < len[u]; ++j)
			if (last != a[u][j]) {
				if (last == -1) last = a[u][j];
				else {
					used[last] = true;
					if (used[a[u][j]]) return false;
					last = a[u][j];
				}
			}
	}
	return true;
}

bool check(string s) {
	int last = -1;
	for (int i = 0; i < 26; ++i) used[i] = false;
	for (int i = 0; i < (int)s.size(); ++i) {
		int u = s[i] - 'a';
		if (last != u) {
			if (last == -1) last = u;
			else {
				used[last] = true;
				if (used[u]) return false;
				last = u;
			}
		}
	}
	return true;
}


void rec(int x) {
	if (x == n) {
		if (check()) ret++;
		return ;
	}

	for (int i = 0; i < n; ++i) {
		if (!used1[i]) {
			used1[i] = true;
			p[x] = i;
			rec(x+1);
			used1[i] = false;
		}
	}
}

void cleanUp() {
	int m = 0;
	for (int i = 0; i < n; ++i)
		if (str[i].size() == 0) continue;
		else {
			str[m++] = str[i];
		}
	n = m;
}

void solve() {
	ans = 1;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> str[i];
		len[i] = str[i].size();
		for (int j = 0; j < len[i]; ++j) a[i][j] = str[i][j] - 'a';
	}
	for (int i = 0; i < n; ++i)
		if (!check(str[i])) {
			cout << 0 << endl;
			return;
		}

	for (int i = 0; i < n; ++i) {
		string s = "";
		s = s + str[i][0];
		for (int j = 1; j < (int)str[i].size(); ++j) 
			if (s.back() != str[i][j]) s = s + str[i][j];
		str[i] = s;
	}

	for (int choosen = 0; choosen < 26; ++choosen) {
		vector< int > f;
		for (int i = 0; i < n; ++i) {
			bool isHere = false;
			for (int j = 0; j < (int)str[i].size(); ++j)
				if (str[i][j] - 'a' == choosen) isHere = true;
			if (isHere) {
				f.push_back(i);
			}
		}
		if (f.size() <= 1) continue;
		int multF = 0;
		for (int i = 0; i < (int)f.size(); ++i) 
			if (str[f[i]].size() == 1) {
				str[f[i]] = "";
				multF++;
			}
		vector < int > g;
		for (int i = 0; i < f.size(); ++i)
			if (str[f[i]].size() != 0) {
				g.push_back(f[i]);
			}
		if (g.size() == 0) {
			str[f[0]] = (char)(choosen + 'a');
			ans = (1LL * ans * fact[multF]) % MOD;
			cleanUp();
			continue;
		}
		if (g.size() > 2) {
			ans = 0;
			break;
		}

		if (g.size() == 1) {
			cleanUp();
			ans = (1LL * ans * fact[multF]) % MOD;
			continue;
		}
		char chC = (char)(choosen + 'a');
		if (str[g[0]][0] == chC && str[g[1]].back() == chC) swap(g[0], g[1]);
		if (str[g[0]].back() != chC || str[g[1]][0] != chC) {
			ans = 0;
			break;
		}

		str[g[0]] = str[g[0]] + str[g[1]];
		str[g[1]] = "";
		ans = (1LL * ans * fact[multF]) % MOD;
		cleanUp();
	}
	ans = 1LL * ans * fact[n] % MOD;
	cout  <<  ans << endl;
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	fact[0] = 1;
	for (int i = 1; i <= 255; ++i) 
		fact[i] = (1LL * fact[i - 1] * i) % MOD;
	int t;
	cin >> t;
	for (int tests = 1; tests <= t; ++tests) {
		cout << "Case #" << tests << ": ";
		solve();
	}
	return 0;
}



/*

*/