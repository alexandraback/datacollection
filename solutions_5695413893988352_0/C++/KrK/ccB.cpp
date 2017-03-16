#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll Inf = 9000000000000000000ll;
const int Maxd = 10;

struct triple {
	ll a, b, c;
	triple(ll a = 0, ll b = 0, ll c = 0): a(a), b(b), c(c) {}
	bool operator <(const triple &u) const {
		if (a != u.a) return a < u.a;
		if (b != u.b) return b < u.b;
		return c < u.c;
	}
};

int t;
string c, j;

bool Check(char ch, int dig) { return ch == '?' || ch - '0' == dig; }

void Print(int lvl, ll val)
{
	if (lvl == 0) return;
	Print(lvl - 1, val / 10);
	printf("%d", int(val % 10));
}

int main()
{
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		cin >> c >> j;
		ll minc = 0, maxc = 0, curc = 0, minj = 0, maxj = 0, curj = 0;
		ll pw;
		for (int i = c.length() - 1, pw = 1; i >= 0; i--, pw *= 10ll) {
			triple best = triple(Inf);
			// eq
			for (int l = 0; l < Maxd; l++)
				if (Check(c[i], l) && Check(j[i], l)) {
					triple cand = triple(abs(curc - curj), pw * l + curc, pw * l + curj);
					if (cand < best) best = cand;
				}
			// >
			for (int l = 0; l < Maxd; l++)
				for (int z = 0; z < l; z++)
				if (Check(c[i], l) && Check(j[i], z)) {
					triple cand = triple(abs(pw * l + minc - pw * z - maxj), pw * l + minc, pw * z + maxj);
					if (cand < best) best = cand;
				}
			// <
			for (int l = 0; l < Maxd; l++)
				for (int z = l + 1; z < Maxd; z++)
				if (Check(c[i], l) && Check(j[i], z)) {
					triple cand = triple(abs(pw * l + maxc - pw * z - minj), pw * l + maxc, pw * z + minj);
					if (cand < best) best = cand;
				}
			curc = best.b; curj = best.c;
			if (c[i] == '?') minc += pw * 0, maxc += pw * 9;
			else minc += pw * (c[i] - '0'), maxc += pw * (c[i] - '0');
			if (j[i] == '?') minj += pw * 0, maxj += pw * 9;
			else minj += pw * (j[i] - '0'), maxj += pw * (j[i] - '0');
		}
		printf("Case #%d: ", tc); Print(c.length(), curc); printf(" "); Print(j.length(), curj); printf("\n");
	}
	return 0;
}