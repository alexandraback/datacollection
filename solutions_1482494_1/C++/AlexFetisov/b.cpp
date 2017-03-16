// Alex Fetisov

#include <cstdio>

void initf() {
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
}

#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <sstream>
#include <string>

using namespace std;

const string BAD = "Too Bad";

int n;
set < pair < pair < int, int >, int > > q1, q2;

void solve() {
	scanf("%d", &n);
	q1.clear();
	q2.clear();
	for (int i = 0; i < n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		q1.insert(make_pair(make_pair(x, y), i));
		q2.insert(make_pair(make_pair(y, x), i));
	}
	int ret = 0;
	int numStars = 0;
	pair < pair < int, int >, int > p;
	while (!q2.empty()) {
		// try to get 2 stars
		p = *q2.begin();
		if (p.first.first <= numStars) {
			int x = p.first.second;
			int y = p.first.first;
			int i = p.second;
			q2.erase(q2.begin());
			if (p.first.second < 1000000) {
				q1.erase(make_pair(make_pair(x, y), i));
				numStars += 2;	
			} else {
				++numStars;
			}
			++ret;
			
			continue;
		}
		if (q1.empty()) {
			cout << BAD << endl;
			return;
		}
		// maybe 1 star?
		int id = -1;
		int x = 0, y = 0;
		for (set<pair < pair < int, int >, int > >::iterator it = 
			q1.begin(); it != q1.end(); ++it) {
			p = *it;
			if (p.first.first <= numStars) {
				if (y < p.first.second) {
					x = p.first.first;
					y = p.first.second;
					id = p.second;
				}
			}
		}
		if (id == -1) {
			cout << BAD << endl;
			return;
		}
		q1.erase(make_pair(make_pair(x, y), id));
		q2.erase(make_pair(make_pair(y, x), id));
		q2.insert(make_pair(make_pair(y, 1000000), id));
		++ret;
		++numStars;
	}
	printf("%d\n", ret);
}

int main() {
	initf();
	int T;
	scanf("%d", &T);
	for (int test = 1; test <= T; ++test) {
		printf("Case #%d: ", test);
		solve();
	}
	return 0;
}