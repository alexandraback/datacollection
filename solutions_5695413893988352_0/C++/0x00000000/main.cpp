#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <string>
#include <tuple>
#include <queue>
#include <utility>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <limits>
#include <new>
#include <functional>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void fill_nine(string& in, int p) {
	for (int i = p; i < in.size(); i++) {
		if (in[i] == '?') in[i] = '9';
	}
}

void fill_zero(string& in, int p) {
	for (int i = p; i < in.size(); i++) {
		if (in[i] == '?') in[i] = '0';
	}
}

unsigned long long to_int(string in) {
	unsigned long long res = 0;
	unsigned long long p = 1;
	for (int i = 0; i < in.size(); i++) {
		res += p * in[in.size() - 1 - i];
		p *= 10;
	}
	return res;
}

vector<pair<string, string>> opts;

void rs(string a, string b, int p, int s) {
	if (p == s) {
		opts.push_back(make_pair(a, b));
		return;
	}
	if (a[p] == '?' && b[p] == '?') {
		string c = a, d = b;
		c[p] = d[p] = '0';
		rs(c, d, p + 1, s);
		c[p] = '1';
		fill_zero(c, p);
		fill_nine(d, p);
		rs(c, d, s, s);
		c = a;
		d = b;
		c[p] = '0';
		d[p] = '1';
		fill_zero(d, p);
		fill_nine(c, p);
		rs(c, d, s, s);
		return;
	}
	else if (a[p] == '?') {
		string c = a, d = b;
		c[p] = b[p];
		rs(c, d, p + 1, s);
		if (b[p] != '0') {
			c[p] = b[p] - 1;
			fill_zero(d, p);
			fill_nine(c, p);
			rs(c, d, s, s);
		}
		if (b[p] != '9') {
			c = a;
			d = b;
			c[p] = b[p] + 1;
			fill_zero(c, p);
			fill_nine(d, p);
			rs(c, d, s, s);
		}
		return;
	}
	else if (b[p] == '?') {
		string c = a, d = b;
		d[p] = a[p];
		rs(c, d, p + 1, s);
		if (a[p] != '0') {
			d[p] = a[p] - 1;
			fill_zero(c, p);
			fill_nine(d, p);
			rs(c, d, s, s);
		}
		if (a[p] != '9') {
			c = a;
			d = b;
			d[p] = a[p] + 1;
			fill_zero(d, p);
			fill_nine(c, p);
			rs(c, d, s, s);
		}
		return;
	}
	else {
		if (a[p] == b[p]) rs(a, b, p + 1, s);
		else if (a[p] > b[p]) {
			string c = a, d = b;
			fill_zero(c, p);
			fill_nine(d, p);
			rs(c, d, s, s);
		}
		else if (a[p] < b[p]) {
			string c = a, d = b;
			fill_zero(d, p);
			fill_nine(c, p);
			rs(c, d, s, s);
		}
		return;
	}
}

typedef unsigned long long ull;

bool cmp(const pair<string, string>& L, const pair<string, string>& R) {
	ull l1 = to_int(L.first);
	ull l2 = to_int(L.second);
	ull r1 = to_int(R.first);
	ull r2 = to_int(R.second);
	ull ld = (l1 > l2 ? l1 - l2 : l2 - l1);
	ull rd = (r1 > r2 ? r1 - r2 : r2 - r1);
	if (ld != rd) return ld < rd;
	else {
		if (l1 != r1) return l1 < r1;
		else {
			return l2 < r2;
		}
	}
}

int main(void) {
	cin.tie(nullptr);
	cin.sync_with_stdio(false);

	int t;
	cin >> t;
	for (int k = 0; k < t; k++) {
		opts.clear();
		string C, J;
		cin >> C >> J;
		int size = C.size();
		rs(C, J, 0, size);
		sort(opts.begin(), opts.end(), cmp);
		
		cout << "Case #" << k + 1 << ": ";
		cout << opts[0].first << ' ' << opts[0].second;
		cout << endl;
	}

	return 0;
}