// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; ++i)

ofstream fout("ans.out");
#define cout fout

const int N = 0, mod = 0;

vector<int> gen(string s, int pos = 0, int cur = 0) {
	if (pos == s.size()) {
		vector<int> res;
		res.push_back(cur);
		return res;
	}
	if (s[pos] != '?')
		return gen(s, pos + 1, cur * 10 + s[pos] - '0');
	vector<int> res;
	rep(i, 10) {
		vector<int> nxt = gen(s, pos + 1, cur * 10 + i);
		for (auto x : nxt)
			res.push_back(x);
	}
	return res;
}

string get(int x, int len) {
	string res = "";
	rep(i, len)
		res += (x % 10) + '0', x /= 10;
	reverse(res.begin(), res.end());
	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	rep(it, tc) {
		cout << "Case #" << it + 1 << ": ";
		string s, t;
		cin >> s >> t;
		vector<int> a = gen(s), b = gen(t);
		int dif = 1e9, c = 0, j = 0;
		for (auto x : a)
			for (auto y : b)
				if (abs(x - y) < dif || (abs(x - y) == dif && x < c) || (abs(x - y) == dif && x == c && y < j)) {
					dif = abs(x - y);
					c = x;
					j = y;
				}
		cout << get(c, s.size()) << ' ' << get(j, s.size())  << endl;
	}
	return 0;
}
