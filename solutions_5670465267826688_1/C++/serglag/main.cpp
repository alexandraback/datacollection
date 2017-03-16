#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <map>
#include <numeric>
#include <fstream>

using namespace std;

typedef long long ll;

struct q
{
	int val;
	int minus;

	inline bool operator==(const q& o) const { return val == o.val && minus == o.minus; } 
	inline q operator*(const q& o) const;
};

q mul[4][4] = {
	{ { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 } },
	{ { 1, 0 }, { 0, 1 }, { 3, 0 }, { 2, 1 } },
	{ { 2, 0 }, { 3, 1 }, { 0, 1 }, { 1, 0 } },
	{ { 3, 0 }, { 2, 0 }, { 1, 1 }, { 0, 1 } }
};

q q::operator*(const q& o) const
{
	q t = mul[val][o.val];
	return { t.val, (minus + o.minus + t.minus) % 2 };
}

q I = { 1, 0 };
q J = { 2, 0 };
q K = { 3, 0 };
q one = { 0, 0 };
q minus1 = { 0, 1 };

q a[255];

inline int i_pref(const vector<q> &v)
{
	int res = 0;
	q pref = one;
	for ( ; res < v.size(); ++res) {
		pref = pref * v[res];

		if (pref == I)
			return res;
	}

	return res;
}

inline int k_suf(const vector<q> &v)
{
	int res = v.size() - 1;
	q suf = one;
	for ( ; res >= 0; --res) {
		suf = v[res] * suf;

		if (suf == K)
			return res;
	}

	return res;
}

inline q prod(const vector<q> &v)
{
	q res = v[0];

	for (int i = 1; i < v.size(); ++i) {
		res = res * v[i];
	}

	return res;
}

bool pows_to_minus1(const q& p, ll x)
{
	return (x % 4 == 2 && ((p.val == 1) || (p.val == 2) || (p.val == 3))) ||
		(x % 2 == 1 && (p == minus1));
}

int main()
{
	ios::sync_with_stdio(false);

	a['1'] = one;
	a['i'] = I;
	a['j'] = J;
	a['k'] = K;

	ifstream in("d:\\input.txt");
	ofstream out("d:\\output.txt");

	int t;
	in >> t;

	for (int c = 1; c <= t; ++c) {
		int l;
		ll x;
		in >> l >> x;

		string s;
		in >> s;

		int times = (x <= 10LL ? int(x) : 4);

		string ss;
		ss.reserve(times * l);

		for (int i = 0; i < times; ++i) {
			ss.append(s);
		}

		vector<q> v(ss.length());
		for (int i = 0; i < v.size(); ++i) {
			v[i] = a[ss[i]];
		}

		bool ans;
		if (x <= 10) {
			q p = prod(v);
			ans = (p == minus1 && i_pref(v) < k_suf(v));
		}
		else {
			vector<q> single(l);

			for (int i = 0; i < l; ++i) {
				single[i] = a[s[i]];
			}

			q p = prod(single);
			ans = pows_to_minus1(p, x) && (i_pref(v) != v.size()) && (k_suf(v) != -1);
		}

		out << "Case #" << c << ": " << (ans ? "YES" : "NO") << "\n";
	}

	return 0;
}