#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int k, l, s, mx;
string ks, ls;
double prob;

bool Find(int idx, string cur) {
	if (int(cur.size()) - idx < int(ls.size()))
		return 0;
	for (int i = 0; i < l; ++i)
		if (cur[i + idx] != ls[i])
			return 0;
	return 1;
}

double calc(string cur) {
	int cnt = 0;
	for (int i = 0; i < int(cur.size()); ++i) {
		if (Find(i, cur))
			++cnt;
	}
	mx = max(mx, cnt);
	return cnt * prob;
}

double solve(int idx, string cur) {
	if (idx == s)
		return calc(cur);
	double ret = 0.0;
	for (int i = 0; i < k; ++i)
		ret += solve(idx + 1, cur + ks[i]);
	return ret;
}

int main() {
	freopen("B-small-attempt0.in", "rt", stdin);
	freopen("B-small-attempt0.out", "wt", stdout);
	int t;
	cin >> t;
	for (int tst = 1; tst <= t; ++tst) {
		cin >> k >> l >> s;
		cin >> ks >> ls;
		prob = 1.0, mx = 0;
		for (int i = 0; i < s; ++i)
			prob *= (1.0 / k);
		double ret = solve(0, "");
		cout << "Case #" << tst << ": ";
		cout << fixed << setprecision(7) << mx - ret << endl;
	}
	return 0;
}
