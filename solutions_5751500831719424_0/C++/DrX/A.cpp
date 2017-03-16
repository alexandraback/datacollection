#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


#define clr(x) memset(x, 0, sizeof(x))
#define pb push_back
#define mp make_pair

typedef long long ll;

string f(string s) {
	string ans = "";
	int i, n = s.length();
	for (i = 0; i < n; ++i) {
		ans.push_back(s[i]);
		while (i + 1 < n && s[i+1] == s[i]) i++;
	}
	return ans;
}

vector<int> g(string s) {
	vector<int>stat;
	int i, n = s.length();
	for (i = 0; i < n; ++i) {
		int j = i;
		while (i + 1 < n && s[i+1] == s[i]) i++;
		stat.push_back(i - j + 1);
	}
	return stat;
}

int cal(const vector<int> &a, int k) {
	int ans = 0, m = a.size();
	for (int i = 0; i < m; ++i)
		ans += abs(a[i] - k);
	return ans;
}

int cal_median(const vector<vector<int> > &cnt, int col) {
	vector<int> a;
	int i, j, k, m = cnt.size();
	for (i = 0; i < m; ++i) a.pb(cnt[i][col]);
	sort (a.begin(), a.end());

	if (m&1) return cal(a, a[m/2]);
	else return min(cal(a, a[m/2]), cal(a, a[m/2-1]));
}

int main () {
	int i, j, k, ca, T, n;

	freopen ("A-small-attempt0.in", "r", stdin);
	freopen ("a-out.txt", "w", stdout);


	cin >> T;
	for (ca = 1; ca <= T; ++ca) {
		vector<string>d;
		string s;
		cin >> n;
		for (i = 1; i <= n; ++i) {
			cin >> s;
			d.pb(s);
		}
		string common = f(d[0]);
		for (i = 1; i < n; ++i)
			if (common != f(d[i])) break;

		cout << "Case #" << ca << ": ";
		if (i < n) {
			cout << "Fegla Won" << endl;
			continue;
		}
		vector<vector<int> >cnt;
		for (i = 0; i < n; ++i) {
			vector<int> stat = g(d[i]);
			cnt.pb(stat);
		}
		int m = cnt[0].size(), ans = 0;
		for (j = 0; j < m; ++j) {
			ans += cal_median(cnt, j);
		}
		cout << ans << endl;
	}
}
