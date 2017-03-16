
#include <iostream>

using namespace std;


typedef unsigned long long ll;


struct plac {
	int pos;
	ll mul;
};

struct num {
	ll base;
	int p;
	plac *pl;

	ll maxplac() {
		ll x = 1;
		for (int i = 0; i < p; i++) x *= 10;
		return x;
	}

	ll value(int placs) {
		ll v = base;
		for (int i = 0; i < p; i++) {
			v += pl[i].mul * (placs % 10);
			placs /= 10;
		}
		return v;
	}

	void replace(string &s, int placs) {
		for (int i = 0; i < p; i++) {
			s[pl[i].pos] = '0' + (placs % 10);
			placs /= 10;
		}
	}

	num(const string &s) {
		ll o = 1;

		p = 0;
		for (char c : s) {
			if (c == '?') p++;
		}
		pl = new plac[p];
		p = 0;
		base = 0;

		for (int i = s.length() - 1; i >= 0; i--) {
			if (s[i] == '?') {
				pl[p].pos = i;
				pl[p].mul = o;
				p++;
			} else {
				base += (s[i] - '0') * o;
			}
			o *= 10;
		}
	}
};


void brute2(string &c, string &j) {
	string &bc = c;
	string &bj = j;

	num nc(c);
	num nj(j);

	ll mc = nc.maxplac();
	ll mj = nj.maxplac();

	ll bpc = 0;
	ll bpj = 0;
	ll min = 999999999999999999;
	for (ll pc = 0; pc < mc; pc++) {
		ll vc = nc.value(pc);
		for (ll pj = 0; pj < mj; pj++) {
			ll vj = nj.value(pj);
			ll diff = __builtin_llabs(vc-vj);
			if (diff < min) {
				nc.replace(bc, pc);
				nj.replace(bj, pj);
				min = diff;
				bpc = pc;
				bpj = pj;
			}
		}
	}
}


void partial_brute(string &c, string &j) {

	int l = c.length();
	if (l <= 3) {
		brute2(c, j);
		return;
	}

	string bc = "00";
	string bj = "00";

	bc[0] = c[0];
	bc[1] = c[1];
	bj[0] = j[0];
	bj[1] = j[1];

	for (int i = 0; i < l - 1; i++) {
		bc[i] = c[i];
		bc[i+1] = c[i+1];
		bj[i] = j[i];
		bj[i+1] = j[i+1];

		brute2(bc, bj);
		c[i] = bc[i];
		j[i] = bj[i];
		bc += '0';
		bj += '0';
	}

	c[l-1] = bc[l-1];
	j[l-1] = bj[l-1];
}


int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case #" << t << ": ";

		string c, j;
		cin >> c >> j;

		partial_brute(c, j);

		cout << c << ' ' << j << endl;
	}
	return 0;
}
