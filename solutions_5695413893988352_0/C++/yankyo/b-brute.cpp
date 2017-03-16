
#include <iostream>

using namespace std;


struct plac {
	int pos;
	int mul;
};

struct num {
	int base;
	int p;
	plac *pl;

	int maxplac() {
		int x = 1;
		for (int i = 0; i < p; i++) x *= 10;
		return x;
	}

	int value(int placs) {
		int v = base;
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
		int o = 1;

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


int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case #" << t << ": ";

		string c, j;
		cin >> c >> j;

		string bc = c;
		string bj = j;

		num nc(c);
		num nj(j);

		int mc = nc.maxplac();
		int mj = nj.maxplac();

		int bpc = 0;
		int bpj = 0;
		int min = 99999999;
		for (int pc = 0; pc < mc; pc++) {
			int vc = nc.value(pc);
			for (int pj = 0; pj < mj; pj++) {
				int vj = nj.value(pj);
				int diff = abs(vc-vj);
				if (diff < min) {
					nc.replace(bc, pc);
					nj.replace(bj, pj);
					min = diff;
					bpc = pc;
					bpj = pj;
				}
			}
		}

		//cout << c << ' ' << j << " --> " << bc << ' ' << bj << " (by " << bpc << ' ' << bpj << ": " << min << ")" << endl;
		cout << bc << ' ' << bj << endl;
	}
	return 0;
}
