#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct attack {
	int d;
	int w;
	int e;
	int s;

	attack(int d, int w, int e, int s) : d(d), w(w), e(e), s(s) {}

	bool operator<(const attack& other) const {
		return d < other.d;
	}
};

struct interval {
	int a;
	int b;
	int mini;
	int maxi;
};

static const int intn = (1<<22);
static interval ints[intn];

void update(int intk, int a, int b, int m) {
	if (ints[intk].a >= b || ints[intk].b <= a || ints[intk].mini >= m) return;
	if (ints[intk].a >= a && ints[intk].b <= b && ints[intk].maxi <= m) {
		ints[intk].mini = m;
		ints[intk].maxi = m;
	} else {
		update(2*intk, a, b, m);
		update(2*intk+1, a, b, m);
		ints[intk].mini = min(ints[2*intk].mini, ints[2*intk+1].mini);
		ints[intk].maxi = max(ints[2*intk].maxi, ints[2*intk+1].maxi);
	}
}

int getmin(int intk, int a, int b) {
	if (ints[intk].a >= b || ints[intk].b <= a) return 1000000000;
	if ((ints[intk].mini == ints[intk].maxi) || (ints[intk].a >= a && ints[intk].b <= b)) return ints[intk].mini;
	return min(getmin(2*intk, a, b), getmin(2*intk+1, a, b));
}

int main(void)
{
	int ti, tn;
	cin >> tn;
	for (ti = 1; ti <= tn; ti++) {
		int n;
		cin >> n;
		std::vector<attack> attacks;
		
		for (int i = 0; i < n; i++) {
			int d, x, w, e, s, dd, dp, ds;
			cin >> d >> x >> w >> e >> s >> dd >> dp >> ds;
			for (int j = 0; j < x; j++) {
				attacks.emplace_back(d, w, e, s);
				d += dd;
				w += dp;
				e += dp;
				s += ds;
			}
		}
		sort(attacks.begin(), attacks.end());
		int an = attacks.size();
		int done = 0;
		int ret = 0;
		int ofs = 1000000;
		
		int intk = 1;
		for (int lev = 0; lev < 22; lev++) {
			int a = 0;
			int s = 1<<(21-lev);
			for (int i = 0; i < (1<<lev); i++, intk++) {
				ints[intk].a = a;
				ints[intk].b = a+s;
				a += s;
				ints[intk].mini = 0;
				ints[intk].maxi = 0;
			}
		}
		for (int i = 0; i < an; i++) {
			if (i == 0 || attacks[i].d > attacks[i-1].d) {
				for (int j = done; j < i; j++) {
					update(1, attacks[j].w+ofs, attacks[j].e+ofs, attacks[j].s);
				}
				done = i;
			}
			if (getmin(1, attacks[i].w+ofs, attacks[i].e+ofs) < attacks[i].s) ret++;
		}
		cout << "Case #" << ti << ": " << ret << endl;
	}
	return 0;
}
