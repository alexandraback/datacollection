#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define MAXN 100001
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)

int k, l, n, maxn, c;
string a, s;

inline bool cmp(const string &a) {
	forn(i, s.length())
		if (s[i] != a[a.length() - s.length() + i])
			return 0;
	return 1;
}

void go(const string &t, int cmps) {
	if (int(t.length()) >= l && cmp(t)) {
		//cout << "t = " << t << endl;
		++cmps;
		maxn = max(maxn, cmps);
	}
	if (t.length() == n) {
		c += cmps;
		return;
	}
	forn(i, k)
		go(t + a[i], cmps);
}

void main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int tc;
	cin >> tc;
	forn(ttt, tc) {
		cin >> k >> l >> n;
		cin >> a >> s;
		maxn = c = 0;
		go("", 0);
		///cout << "maxn = " << maxn << endl;
		//cout << "cnt = " << c << endl;
		printf("Case #%d: %.9llf\n", ttt + 1, (maxn - c * 1. / pow(k + 0., n + 0.)));
	}
}