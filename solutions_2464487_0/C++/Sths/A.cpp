#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

class Interger {
	int s[100];
public:
	Interger(long long t) {
		memset(s, 0, sizeof(s));
		while (t) {
			s[++s[0]] = t % 10;
			t /= 10;
		}
	}
	Interger(int * t) {
		memset(s, 0, sizeof(s));
		for (int i = 0; i < 100; i++) s[i] = t[i];
	}
	void carry() {
		for (int i = 1; i <= s[0]; i++) {
			if (s[i] >= 10) {
				if (i == s[0]) s[0] ++;
				s[i + 1] += s[i] / 10;
				s[i] = s[i] % 10;
			}
			while (s[i] < 0) {
				s[i] = s[i] + 10;
				s[i + 1] --;
			}
		}
		while (s[0] && !s[s[0]]) s[0] --;
	}
	Interger operator * (int t) {
		Interger c(s);
		for (int i = 1; i <= s[0]; i++) c.s[i] *= t;
		c.carry();
		return c;
	}
	Interger operator * (Interger t) {
		Interger c(0LL);
		for (int i = 1; i <= s[0]; i++)
			for (int j = 1; j <= t.s[0]; j++)
				c.s[i + j - 1] += s[i] * t.s[j];
		c.s[0] = s[0] + t.s[0] - 1;
		c.carry();
		return c;
	}
	Interger operator - (int t) {
		Interger c(s);
		c.s[1] -= t;
		c.carry();
		return c;
	}
	Interger operator + (Interger t) {
		Interger c(s);
		for (int i = 0; i <= t.s[0]; i++) c.s[i] += t.s[i];
		c.s[0] = max(c.s[0], t.s[0]);
		c.carry();
		return c;
	}
	Interger operator / (int t) {
		Interger c(s);
		for (int i = c.s[0]; i > 0; i--) {
			if (i > 1) c.s[i - 1] += (c.s[i] % t) * 10;
			c.s[i] /= t;
		}
		c.carry();
		return c;
	}
	bool operator < (Interger t) {
		if (s[0] < t.s[0]) return true;
		if (s[0] > t.s[0]) return false;
		for (int i = s[0]; i > 0; i--) {
			if (s[i] < t.s[i]) return true;
			if (s[i] > t.s[i]) return false;
		}
		return false;
	}
	bool operator <= (Interger t) {
		if (s[0] < t.s[0]) return true;
		if (s[0] > t.s[0]) return false;
		for (int i = s[0]; i > 0; i--) {
			if (s[i] < t.s[i]) return true;
			if (s[i] > t.s[i]) return false;
		}
		return true;
	}
	void print() {
		for (int i = s[0]; i > 0; i--) cout << s[i];
	}
};

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int T, TT = 0;
	cin >> T;
	while (T--) {
		long long r, t;
		cin >> r >> t;
		Interger ll(1), rr(t);
		while (ll < rr) {
			Interger m = (ll + rr + 1) / 2;
			// m.print(); cout << endl;
			Interger f = Interger(r) * 2;
			// f.print(); cout << endl;
			f = f + m * 2;
			// f.print(); cout << endl;
			f = f - 1;
			// f.print(); cout << endl;
			f = f * m;
			// f.print(); cout << endl;
			if (f <= Interger(t)) ll = m;
			else rr = m - 1;
		}
		cout << "Case #" << ++TT << ": ";
		ll.print();
		cout << endl;
	}
	return 0;
}
