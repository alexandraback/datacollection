#include <bits/stdc++.h>
using namespace std;

int T, i, N;

int main() {
	cin >> T;
	for (int t=1; t<=T; t++) {
		string c, j, s;
		int bcv = 1000, bjv = 0;
		cin >> c >> j;
		int nq = count(c.begin(), c.end(), '?') + count(j.begin(), j.end(), '?');
		int lim = 1;
		for (; nq>0; nq--) lim *= 10;
		for (int i=0; i<lim; i++) {
			int d = i;
			int cv = 0, jv = 0;
			for (auto ch: c)
				if (ch == '?') cv = cv*10 + d%10, d /= 10;
				else cv = cv*10 + (ch-'0');
			for (auto ch: j)
				if (ch == '?') jv = jv*10 + d%10, d /= 10;
				else jv = jv*10 + (ch-'0');

			if (abs(cv-jv) < abs(bcv-bjv) ||
				abs(cv-jv) == abs(bcv-bjv) && cv < bcv ||
				abs(cv-jv) == abs(bcv-bjv) && cv == bcv && jv < bjv)
				bcv = cv, bjv = jv;
		}
		string fmt("Case #%d: %0_d %0_d\n");
		for (int i=0; i<fmt.length(); i++)
			if (fmt[i] == '_') fmt[i] = '0'+c.length();

		printf(fmt.c_str(), t, bcv, bjv);
	}
}
