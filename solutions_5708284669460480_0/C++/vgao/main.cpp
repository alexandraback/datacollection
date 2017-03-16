#include <iostream>
#include <string>
#include <cstddef>
#include <cstdio>
#include <functional>
#include <algorithm>
#include <unordered_set>
#include <iomanip>

#pragma warning(disable : 4996)

using namespace std;

bool compare(const string & a, size_t off, const string & b) {
	if (a.size() - off < b.size())
		return false;
	for (size_t i = 0; i < b.size(); ++i) {
		if (a[i + off] != b[i])
			return false;
	}
	return true;
}

size_t count(const string & s) {
	size_t mx = 0;
	for (size_t i = 1; i < s.size(); ++i) {
		bool flag = true;
		for (size_t j = 0; j < i; ++j) {
			if (s[j] != s[s.size() - i + j]) {
				flag = false;
				break;
			}
		}
		if (flag)
			mx = max(mx, i);
	}
	return mx;
}

size_t get_max(const string & keys, const string & target, size_t s) {
	static unordered_set<char> v;
	v.clear();
	for (char c : keys)
		v.insert(c);
	for (char c : target) {
		if (v.find(c) == v.end())
			return 0;
	}
	if (target.size() > s)
		return 0;
	size_t ct = count(target);
	return 1 + (s - target.size()) / (target.size() - ct);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	size_t __; cin >> __;
	for (size_t _ = 0; _ < __; ++_) {
		size_t k, l, s; cin >> k >> l >> s;
		string keys, target; 
		cin >> keys >> target;
		string v(s, ' ');
		size_t n = 0, m = 0, mx = get_max(keys, target, s);
		function<void(size_t, char)> dfs;
		dfs = [&](size_t p, char c) {
			v[p] = c;
			if (p + 1 < s) {
				for (char x : keys)
					dfs(p + 1, x);
			}
			else {
				for (size_t i = 0; i < v.size(); ++i) {
					if (compare(v, i, target))
						++n;
				}
				++m;
			}
		};
		for (char x : keys)
			dfs(0, x);
		cout << "Case #" << (_ + 1) << ": " << fixed << setprecision(6) << double(mx) - double(n)/double(m) << endl;
	}
	return 0;
}