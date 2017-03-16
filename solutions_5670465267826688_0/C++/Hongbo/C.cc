#include <iostream>
#include <string>
using namespace std;

struct ijk {
	char v;
	bool n;
	ijk(string s) {
		if (s[0] == '-') n = true, v = s[1];
		else v = s[0], n = false;
	}
	ijk(char c, bool d = false): v(c), n(d) {}
	ijk operator * (const ijk &other) const {
		if (v == '1') return ijk(other.v, n ^ other.n);
		if (other.v == '1') return ijk(v, n ^ other.n);	
		if (v == 'i' && other.v == 'j') return ijk('k', n ^ other.n);
		if (v == 'i' && other.v == 'k') return ijk('j', !(n ^ other.n));
		if (v == 'j' && other.v == 'i') return ijk('k', !(n ^ other.n));
		if (v == 'j' && other.v == 'k') return ijk('i', n ^ other.n);
		if (v == 'k' && other.v == 'i') return ijk('j', n ^ other.n);
		if (v == 'k' && other.v == 'j') return ijk('i', !(n ^ other.n));
		return ijk('1', !(n ^ other.n));
	}
	string value() {
		if (n) return string("-") + v;
		else return string("") + v;
	}
};

string solve() {
	bool d[3];
	for (int i = 0; i < 3; i ++)
		d[i] = false;
	int x, l;
	string s;
	cin >> l >> x >> s;

	int cntn = 0, tot = 7;
	string db = "";
	for (int i = 0; i < x; i ++)
		db += s;
	ijk p('1');
	int len = (int)db.length();
	for (int i = 0; i < len; i ++) {
		p = p * ijk(db[i]);
		if (p.v == 'i') {
			d[0] = true;
			cntn += p.n;
			string t = "";
			for (int j = i + 1; j < len; j ++)
				t += db[j];
			db = t;
			break;
		}
	}
	if (!d[0]) return "NO";

	p = ijk('1');
	len = (int)db.length();
	for (int i=  0; i < len; i ++) {
		p = p * ijk(db[i]);
		if (p.v == 'j') {
			d[1] = true;
			cntn += p.n;
			string t = "";
			for (int j = i + 1; j < len; j ++)
				t += db[j];
			db = t;
			break;
		}
	}
	if (!d[1]) return "NO";

	p = ijk('1');
	len = (int)db.length();
	for (int i = 0; i < len; i ++) {
		p = p * ijk(db[i]);
		if (p.v == 'k') {
			d[2] = true;
			cntn += p.n;
			string t = "";
			for (int j = i + 1; j < len; j ++)
				t += db[j];
			db = t;
			break;
		}
	}
	if (!d[2]) return "NO";

	p = ijk('1');
	len = (int)db.length();
	for (int i = 0; i < len; i ++)
		p = p * ijk(db[i]);
	if (p.v != '1') return "NO";
	cntn += p.n;
	if (cntn & 1) return "NO";
	return "YES";
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i ++)
		cout << "Case #" << i << ": " << solve() << endl;
	return 0;
}
