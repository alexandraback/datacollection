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

using namespace std;

#define MAXN 100001
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define ld long double
#define pii pair<ld, ld>


ld dif(ld b, ld a)
{
	if (b > a)
		return a + 360 - b;
	return a - b;
}

void main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int tc;
	cin >> tc;
	forn(ttt, tc) {
		printf("Case #%d: ", ttt + 1);
		vector< pii > a;
		int n;
		cin >> n;
		a.clear();
		forn(i, n) {
			int d, h, m;
			cin >> d >> h >> m;
			forn(j, h) {
				a.push_back(make_pair(m + j, d));
			}
		}
		sort(a.begin(), a.end());
		int res = 0;
		if (a.size() < 2) {
			puts("0");
			continue;
		}
		if (a[0].first == a[1].first) {
			puts("0");
			continue;
		}
		if (a[0].second < a[1].second) {
			long double vel1 = 360. / a[1].first;
			long double vel0 = 360. / a[0].first;
			ld t = (a[1].second - a[0].second) / (vel0 - vel1);
			ld dist = a[0].second + vel0 * t;
			if (dist < 360) {
				a[0].second = a[1].second = dist;
			} else {
				puts("0");
				continue;
			}
		}
		long double vel = 360. / a[1].first;
		long double tm = (360. - a[1].second) / vel;
		long double vel1 = 360. / a[0].first;
		if (tm > (360 + 360 - a[0].second) / vel1)
			res = 1;
		printf("%d\n", res);
	}
}