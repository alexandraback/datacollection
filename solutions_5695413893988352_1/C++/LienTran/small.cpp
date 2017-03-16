#include <bits/stdc++.h>

using namespace std;

string s, f;
int n;                          
pair<string, string> ans;
long long diff;

long long toLong(string x) {
	stringstream inp;
	inp << x;
	long long num;
	inp >> num;
	return num;
}

void go(int i, int cmp) {
	if (i == n) {
		long long x = toLong(s);
		long long y = toLong(f);
		long long cur = labs(x - y);
		if (cur < diff) {
			diff = cur;
			ans = make_pair(s, f);
		}else
		if (cur == diff) {
			if (make_pair(s, f) < ans) ans = make_pair(s, f);
		}
		return;
	}
	if (s[i] != '?' && f[i] != '?') {
		if (s[i] == f[i]) cmp = 0;
		if (s[i] > f[i]) cmp = 1;
		if (s[i] < f[i]) cmp = -1;
		go(i + 1, cmp);
		return;
	}
	char ss = s[i], ff = f[i];
	if (cmp == 1) {
		//s > f
		if (s[i] == '?' && f[i] == '?') s[i] = '0', f[i] = '9';
		else if (s[i] == '?') s[i] = '0';
		else f[i] = '9';
		go(i + 1, 1);
		return;
	}
	if (cmp == -1) {
		if (s[i] == '?' && f[i] == '?') s[i] = '9', f[i] = '0';
		else if (s[i] == '?') s[i] = '9';
		else f[i] = '0';
		go(i + 1, -1);
		return;
	}
	if (cmp == 0) {
		if (ss == '?' && ff == '?') {
			s[i] = f[i] = '0';
			go(i + 1, 0);
			s[i] = '0'; f[i] = '1';
			go(i + 1, -1);
			s[i] = '1'; f[i] = '0';
			go(i + 1, 1);
			return;
		}
		if (ss == '?') {
			s[i] = ff;
			go(i + 1, 0);
			if (ff > '0') {
				s[i] = ff - 1;
				go(i + 1, -1);
			}
			if (ff < '9') {
				s[i] = ff + 1;
				go(i + 1, 1);
			}
			return;
		}
		if (ff == '?') {
			f[i] = ss;
			go(i + 1, 0);
			if (ss > '0') {
				f[i] = ss - 1;
				go(i + 1, 1);
			}
			if (ss < '9') {
				f[i] = ss + 1;
				go(i + 1, -1);
			}
		}
	}
}

void solve() {
	cin >> s >> f;
	n = s.length();
	ans = make_pair("999999999999999999999", "0");
	diff = (long long)(1e18);
	go(0, 0);
	cout << ans.first << ' ' << ans.second << '\n';
}

int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	int ntest;
	cin >> ntest;
	for(int tc = 1; tc <= ntest; ++tc) {
		cerr << tc << '\n';
		cout << "Case #" << tc << ": ";
		solve();
	}
	return 0;
}
