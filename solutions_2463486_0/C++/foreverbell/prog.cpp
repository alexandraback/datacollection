
#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

const int B = 10000, D = 4;
struct bnum_t {
	int l;
	vector<int> b;
	bnum_t(int n) {
		b.push_back(0);
		if (n == 0) {
			l = 1, b.push_back(0);
		} else {
			l = 0;
			for (int i = 1; n; ++i, n /= B) ++l, b.push_back(n % B);
		}
	}
	bnum_t() {
		*this = bnum_t(0);
	}
	bnum_t(const char *str) {
		l = 0, b.push_back(0);
		int temp = strlen(str);
		for (int i = temp - 1; i >= 0; i -= D) {
			int v = 0;
			for (int j = 0, p10 = 1; j < D && i - j >= 0; ++j, p10 *= 10) v += (str[i - j] - '0') * p10;
			++l, b.push_back(v);
		}
	}
	friend ostream &operator<<(ostream &os, const bnum_t &r) {
		os << r.b[r.l];
		for (int i = r.l - 1; i >= 1; --i) os << setfill('0') << setw(D) << r.b[i];
		return os;
	}
	bnum_t operator+(const bnum_t &r) {
		bnum_t f(*this);
		f.l = max(l, r.l);
		f.b.resize(f.l + 5);
		for (int i = 1; i <= min(f.l, r.l); ++i) {
			f.b[i] += r.b[i];
			if (f.b[i] / B) f.b[i + 1] += f.b[i] / B, f.b[i] %= B;
		}
		while (f.b[f.l + 1]) f.l += 1;
		f.b.resize(f.l + 1);
		return f;
	}
	bnum_t operator-(const bnum_t &r) { // assume a > b
		bnum_t f = *this;
		f.l = max(l, r.l);
		for (int i = 1; i <= min(f.l, r.l); ++i) {
			f.b[i] -= r.b[i];
			while (f.b[i] < 0) f.b[i] += B, --f.b[i + 1];
		}
		while (f.b[f.l] == 0) f.l -= 1;
		f.b.resize(f.l + 1);
		return f;
	}
	bnum_t operator*(const bnum_t &r) {
		bnum_t f = 0;
		f.l = l + r.l - 1;
		f.b.resize(f.l + 5);
		for (int i = 1; i <= l; ++i) {
			for (int j = 1; j <= r.l; ++j) {
				f.b[i + j - 1] += b[i] * r.b[j];
				if (f.b[i + j - 1] / B) f.b[i + j] += f.b[i + j - 1] / B, f.b[i + j - 1] %= B;
			}
		}
		while (f.b[f.l + 1]) f.l += 1;
		f.b.resize(f.l + 1);
		return f;
	}
};

vector<string> tbl;
vector<string> tbl2;

void add(string s) {
	bnum_t tmp = bnum_t(s.c_str());
	tmp = tmp * tmp;
	stringstream ss;
	ss << tmp;
	s = ss.str();
	while (s.length() < 101) s = "0" + s;
	tbl.push_back(s);
}

void dfs(int dep, int val, int remain, int n) {
	if (dep == 1) {
		int u = val + 1;
		string s;
		for (int j = 1; j <= n / 2; ++j) {
			if (u % 2 == 1) s += '1';
			else s += '0';
			u /= 2;
		}
		tbl2.push_back(s);
	} else {
		if (remain != 0) {
			dfs(dep - 1, val | (1 << (dep - 1)), remain - 1, n);
		}
		dfs(dep - 1, val, remain, n);
	}
}

void gen() {
	// freopen("C-small-attempt0.in", "r", stdin);
	// freopen("C-small-attempt0.out", "w", stdout);
	add("1"); add("2"); add("3");
	for (int i = 3; i <= 50; i += 2) {
		tbl2.clear();
		dfs(i / 2, 0, 3, i);
		for (vector<string>::iterator it = tbl2.begin(); it != tbl2.end(); ++it) {
			string s = *it, sT;
			sT = s;
			reverse(sT.begin(), sT.end());
			add(s + "0" + sT);
			add(s + "1" + sT);
		}
		tbl2.clear();
		dfs(i / 2, 0, 1, i);
		for (vector<string>::iterator it = tbl2.begin(); it != tbl2.end(); ++it) {
			string s = *it, sT;
			sT = s;
			reverse(sT.begin(), sT.end());
			add(s + "2" + sT);
		}
		string tmp;
		for (int j = 1; j < i / 2; ++j) tmp += '0';
		add("2" + tmp + "0" + tmp + "2");
		add("2" + tmp + "1" + tmp + "2");
	}
	for (int i = 2; i <= 50; i += 2) {
		tbl2.clear();
		dfs(i / 2, 0, 3, i);
		for (vector<string>::iterator it = tbl2.begin(); it != tbl2.end(); ++it) {
			string s = *it, sT;
			sT = s;
			reverse(sT.begin(), sT.end());
			add(s + sT);
		}
		string tmp;
		for (int j = 1; j < i / 2; ++j) tmp += '0';
		add("2" + tmp + tmp + "2");
	}
	sort(tbl.begin(), tbl.end());
	// cout << tbl.size() << endl;
	// for (int i = 0; i < 10; ++i) {
	//  	cout << tbl[i] << endl;
	// }
}

int count(string s) {
	while (s.length() < 101) s = "0" + s;
	return upper_bound(tbl.begin(), tbl.end(), s) - tbl.begin();
}

char buf[1024];

bnum_t read() {
	scanf("%s", buf);
	return bnum_t(buf);
}

int main() {
	int tests;
	gen();
	scanf("%d", &tests);
	for (int tt = 1; tt <= tests; ++tt) {
		bnum_t a = read();
		bnum_t b = read();
		stringstream ss1, ss2;
		ss1 << (a - 1);
		ss2 << b;
		string sa = ss1.str(), sb = ss2.str();
		if (a.l == 1 && a.b[1] == 1) {
			printf("Case #%d: %d\n", tt, count(sb));
		} else {
			printf("Case #%d: %d\n", tt, count(sb) - count(sa));
		}
	}
	return 0;
}
