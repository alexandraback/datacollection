#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

const int nm = 20;

char s[nm], s2[nm];
int n;
ll kqa, kqb;

void update(ll a, ll b) {
	if (abs(kqa - kqb) > abs(a - b)) {
		kqa = a;
		kqb = b;
	} else if (abs(kqa - kqb) == abs(a - b) && a < kqa) {
		kqa = a;
		kqb = b;
	} else if (abs(kqa - kqb) == abs(a - b) && a == kqa && b < kqb) {
		kqa = a;
		kqb = b;
	}
}

void testbehon(int i) {
	ll a, b;
	a = 0;
	for (int j = 1; j < i; ++j) {
		if (s[j] != '?')
			a = a * 10ll + (ll) (s[j] - 48);
		else if (s2[j] != '?')
			a = a * 10ll + (ll) (s2[j] - 48);
		else
			a = a * 10ll;
	}
	b = a;
	if (s[i] != '?' && s2[i] != '?' && s[i] < s2[i]) {
		a = a * 10ll + (ll) (s[i] - 48);
		b = b * 10ll + (ll) (s2[i] - 48);
	} else if (s[i] == '?' && s2[i] != '?' && s2[i] > '0') {
		a = a * 10ll + (ll) (s2[i] - 49);
		b = b * 10ll + (ll) (s2[i] - 48);
	} else if (s[i] != '?' && s2[i] == '?' && s[i] < '9') {
		a = a * 10ll + (ll) (s[i] - 48);
		b = b * 10ll + (ll) (s[i] - 47);
	} else if (s[i] == '?' && s2[i] == '?') {
		a = a * 10ll;
		b = b * 10ll + 1ll;
	} else
		return;
	for (int j = i + 1; j <= n; ++j) {
		if (s[j] != '?')
			a = a * 10ll + (ll) (s[j] - 48);
		else
			a = a * 10ll + 9ll;
		if (s2[j] != '?')
			b = b * 10ll + (ll) (s2[j] - 48);
		else
			b = b * 10ll;
	}
	update(a, b);
}

void testtohon(int i) {
	ll a, b;
	a = 0;
	for (int j = 1; j < i; ++j) {
		if (s[j] != '?')
			a = a * 10ll + (ll) (s[j] - 48);
		else if (s2[j] != '?')
			a = a * 10ll + (ll) (s2[j] - 48);
		else
			a = a * 10ll;
	}
	b = a;
	if (s[i] != '?' && s2[i] != '?' && s[i] > s2[i]) {
		a = a * 10ll + (ll) (s[i] - 48);
		b = b * 10ll + (ll) (s2[i] - 48);
	} else if (s[i] == '?' && s2[i] != '?' && s2[i] < '9') {
		a = a * 10ll + (ll) (s2[i] - 47);
		b = b * 10ll + (ll) (s2[i] - 48);
	} else if (s[i] != '?' && s2[i] == '?' && s[i] > '0') {
		a = a * 10ll + (ll) (s[i] - 48);
		b = b * 10ll + (ll) (s[i] - 49);
	} else if (s[i] == '?' && s2[i] == '?') {
		a = a * 10ll + 1ll;;
		b = b * 10ll;
	} else
		return;
	for (int j = i + 1; j <= n; ++j) {
		if (s[j] != '?')
			a = a * 10ll + (ll) (s[j] - 48);
		else
			a = a * 10ll;
		if (s2[j] != '?')
			b = b * 10ll + (ll) (s2[j] - 48);
		else
			b = b * 10ll + 9ll;
	}
	update(a, b);
}

void doi(ll x, string &s) {
	while (x > 0) {
		s = char(x % 10ll + 48ll) + s;
		x /= 10ll;
	}
	while (s.length() < n)
		s = "0" + s;
}

void solve(int test) {
	cout << "Case #" << test << ": ";
	cin >> (s + 1) >> (s2 + 1);
	n = strlen(s + 1);

	bool khac = 0;
	kqa = 1e18;
	kqb = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i + 1] != '?' && s[i + 1] == s2[i + 1])
			continue;
		testbehon(i + 1);
		testtohon(i + 1);
		if (s[i + 1] != '?' && s2[i + 1] != '?' && s[i + 1] != s2[i + 1]) {
			khac = 1;
			break;
		}
	}

	if (!khac) {
		for (int i = 1; i <= n; ++i)
			if (s[i] == '?') {
				if (s2[i] == '?')
					s[i] = s2[i] = '0';
				else
					s[i] = s2[i];
			} else if (s2[i] == '?')
				s2[i] = s[i];
		printf("%s %s\n", s + 1, s2 + 1);
		return;
	}
	string sa, sb;
	doi(kqa, sa);
	doi(kqb, sb);
	cout << sa << " " << sb << "\n";
}

int main() {
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
	freopen("B-large (2).in", "r", stdin);
	freopen("output2.txt", "w", stdout);
#endif
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		solve(i);
}
