#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

string s, s2;
ll a, b;
string sa, sb;

ll doi(string s) {
	ll res = 0;
	for (int i = 0; i < s.length(); ++i)
		res = res * 10ll + (ll) (s[i] - 48);
	return res;
}

void update() {
	ll a2 = doi(s), b2 = doi(s2);
	if (abs(a2 - b2) < abs(a - b)) {
		a = a2;
		b = b2;
		sa = s;
		sb = s2;
	} else if (abs(a2 - b2) == abs(a - b) && a2 < a) {
		a = a2;
		b = b2;
		sa = s;
		sb = s2;
	} else if (abs(a2 - b2) == abs(a - b) && a2 == a && b2 < b) {
		a = a2;
		b = b2;
		sa = s;
		sb = s2;
	}
}

void thu2(int i) {
	if (i >= s2.length()) {
		update();
		return;
	}
	if (s2[i] != '?') {
		thu2(i + 1);
		return;
	}
	for (int j = 0; j <= 9; ++j) {
		s2[i] = char(j + 48);
		thu2(i + 1);
		s2[i] = '?';
	}
}

void thu(int i) {
	if (i >= s.length()) {
		thu2(0);
		return;
	}
	if (s[i] != '?') {
		thu(i + 1);
		return;
	}
	for (int j = 0; j <= 9; ++j) {
		s[i] = char(j + 48);
		thu(i + 1);
		s[i] = '?';
	}
}

void solve(int test) {
	cout << "Case #" << test << ": ";
	cin >> s >> s2;
	a = 1e18;
	b = 0;
	thu(0);
	cout << sa << " " << sb << "\n";
}

int main() {
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
	freopen("B-small-attempt0 (2).in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i)
		solve(i);
}
