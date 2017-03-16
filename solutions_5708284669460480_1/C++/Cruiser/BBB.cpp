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
#include <ctime>

using namespace std;

#define MAXN 100001
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)

int k, l, n, c;
string a, s;

inline bool cmp(const string &a) {
	forn(i, s.length())
		if (s[i] != a[a.length() - s.length() + i])
			return 0;
	return 1;
}

time_t start;

void go(const string &t, int cmps) {
	if (int(t.length()) >= l && t.substr(t.length() - l) == s) {
		//cout << "t = " << t << endl;
		++cmps;
	}
	if (t.length() == n) {
		c += cmps;
		return;
	}
	if (time(0) - start > 4)
		return;
	forn(i, k)
		go(t + a[i], cmps);
}

int off() {
	forn(i, l) {
		if (i > 0) {
			int ok = 1;
			forn(j, l - i) {
				if (s[j] != s[i + j]) {
					ok = 0;
					break;
				}
			}
			if (ok)
				return i;
		}
	}
	return l;
}

int can() {
	forn(i, l) {
		bool ok = 0;
		forn(j, k)
			if (a[j] == s[i]) {
				ok = 1;
				break;
			}
		if (!ok)
			return 0;
	}
	return 1;
}

void main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int tc;
	cin >> tc;
	forn(ttt, tc) {
		cin >> k >> l >> n;
		start = time(0);
		cerr << ttt << endl;
		//n += 3;
		cin >> a >> s;
		int goff = off();
		c = 0;
		go("", 0);
		int cc = l, mx_cnt = 1;
		if (cc > n)
			mx_cnt = 0;
		while(cc + goff <= n) 
			cc += goff, mx_cnt++;
		mx_cnt *= can();
		//cout << "maxn = " << mx_cnt << endl;
		//cout << "cnt = " << c << endl;
		printf("Case #%d: %.9llf\n", ttt + 1, (mx_cnt - c * 1. / pow(k + 0., n + 0.)));
	}
}