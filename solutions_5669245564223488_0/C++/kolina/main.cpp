#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <cstdlib>
#include <queue>
#include <set>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <bitset>
#include <sstream>

using namespace std;

long long gcd(long long a, long long b) {
	return b ? gcd(b, a % b) : a;
}

/*vector<bool> busy(10);
vector<int> is(26);
vector<string> s(10);
int n, ans ,last, c;

void per() {
	if (c == n) {
		++ans;
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (!busy[i]) {
			int beg = 0;
			int b, e;
			bool good = true;
			vector<int> inside;
			while (beg < s[i].length()) {
				int cur = beg;
				while (cur < s[i].length() && s[i][cur] == s[i][beg])
					++cur;
				if (beg > 0 && cur < s[i].length())
					if (is[s[i][beg] - 'a']) {
						good = false;
						break;
					}
					else
						inside.push_back(s[i][beg] - 'a');
				if (beg == 0)
					b = s[i][beg] - 'a';
				if (cur == s[i].length())
					e = s[i][beg] - 'a';
				beg = cur;
			}
			if (good) {
				if (is[b] && last != b)
						good = false;
				if (b != e) {
					if (is[e])
						good = false;
					inside.push_back(e);
				}
			}
			if (good) {
				sort(inside.begin(), inside.end());
				for (int j = 0; j + 1 < inside.size(); ++j)
					if (inside[j] == inside[j + 1]) {
						good = false;
						break;
					}
			}
			if (good) {
				++is[b];
				for (int j = 0; j < inside.size(); ++j)
					++is[inside[j]];
				int prev_last = last;
				last = e;
				++c;
				busy[i] = true;
				per();
				--c;
				busy[i] = false;
				last = prev_last;
				--is[b];
				for (int j = 0; j < inside.size(); ++j)
					--is[inside[j]];
			}
		}
	}
}*/

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int p = 0; p < t; ++p) {
		int n;
		cin >> n;
		vector<string> s(n);
		for (int i = 0; i < n; ++i)
			cin >> s[i];
		vector<int> inside(26);
		vector<bool> has(26);
		vector<pair<int, int> > v;
		vector<int> u;
		for (int i = 0; i < n; ++i) {
			int beg = 0;
			int b, e;
			while (beg < s[i].length()) {
				int cur = beg;
				while (cur < s[i].length() && s[i][cur] == s[i][beg])
					++cur;
				if (beg > 0 && cur < s[i].length())
					++inside[s[i][beg] - 'a'];
				if (beg == 0)
					b = s[i][beg] - 'a';
				if (cur == s[i].length())
					e = s[i][beg] - 'a';
				beg = cur;
			}
			if (b == e)
				u.push_back(b);
			else {
				v.push_back(make_pair(b, e));
				has[b] = true;
				has[e] = true;
			}
		}
		bool exist = true;
		for (int i = 0; i < 26; ++i)
			if (inside[i] > 0)
				if (inside[i] > 1)
					exist = false;
				else {
					for (int j = 0; j < v.size(); ++j)
						if (v[j].first == i || v[j].second == i)
							exist = false;
					for (int j = 0; j < u.size(); ++j)
						if (u[j] == i)
							exist = false;
				}
		cout << "Case #" << p + 1 << ": ";
		if (!exist)
			cout << 0;
		else {
			long long mod = 1000 * 1000 * 1000 + 7;
			int m = v.size();
			bool exist = true;
			vector<int> before(m, -1), after(m ,-1);
			for (int i = 0; i < m; ++i)
				for (int j = 0; j < m; ++j) {
					if (i != j && v[i].second == v[j].first) {
						if (after[i] != -1 || before[j] != -1)
							exist = false;
						after[i] = j;
						before[j] = i;
					}
					if (i != j && (v[i].first == v[j].first || v[i].second == v[j].second))
						exist = false;
				}
			if (!exist)
				cout << 0;
			else {
				for (int i = 0; i < m; ++i) {
					if (before[i] != -1) {
						vector<bool> used(m, false);
						int cur = i;
						while (before[cur] != -1) {
							used[cur] = true;
							cur = before[cur];
							if (used[cur]) {
								exist = false;
								break;
							}
						}
					}
				}
				if (!exist)
					cout << 0;
				else {
					vector<int> un(26);
					for (int i = 0; i < u.size(); ++i)
						++un[u[i]];
					int unique = 0;
					long long ans = 1;
					for (int i = 0; i < v.size(); ++i)
						if (before[i] == -1)
							++unique;
					for (int i = 0; i < 26; ++i) {
						if (!has[i] && un[i] > 0)
							++unique;
						for (int j = 1; j <= un[i]; ++j)
							ans = (ans * j) % mod;
					}
					for (int i = unique; i > 0; --i)
						ans = (ans * i) % mod;
					cout << ans;
				}
			}
		}
		cout << endl;
	}

	/*for (int p = 0; p < t; ++p) {
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> s[i];
		ans = 0;
		last = -1;
		is.assign(26, 0);
		busy.assign(10, false);
		c = 0;
		per();
		cout << "Case #" << p + 1 <<": " << ans << endl;
	}*/
	return 0;
}