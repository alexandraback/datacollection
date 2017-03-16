#define _CRT_SECURE_NO_DEPRECATE

#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <memory.h>

using namespace std;

#define pb push_back
#define pf push_front
#define mp make_pair
#define fi(a, b) for(i=a; i<=b; i++)
#define fj(a, b) for(j=a; j<=b; j++)
#define fo(a, b) for(o=a; o<=b; o++)
#define fdi(a, b) for(i=a; i>=b; i--)
#define fdj(a, b) for(j=a; j>=b; j--)
#define fdo(a, b) for(o=a; o>=b; o--)
#define ZERO(x) memset(x, 0, sizeof(x))
#define COPY(x,y) memcpy(x, y, sizeof(y))
#define LEN(x) (int)x.length()
#define SIZE(x) (int)x.size()

typedef long long int64;

int testq;
int test;

int fx, fy;

void Read() {
	scanf("%d %d", &fx, &fy);
}

int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

int Dist(int x1, int y1, int x2, int y2) {
	return abs(x2 - x1) + abs(y2 - y1);
}

bool Field(int x, int y) {
	if (abs(x) > 150 || abs(y) > 150) return false;
	return true;
}

void Solve() {
	int x, y;
	int x2, y2;
	int l;
	int i;
	string ans;
	vector <pair<int, pair<int, int> > > v;
	map <pair< pair<int, int>, int> , int > p;
	queue <pair< pair <int, int>, int> > qu;
	qu.push(mp(mp(0, 0), 0));
	p[mp(mp(0, 0), 0)] = -1;
	while (!qu.empty()) {
		x = qu.front().first.first;
		y = qu.front().first.second;
		l = qu.front().second;

		if (x == fx && y == fy) break;

		qu.pop();
		v.clear();
		fi(0, 3) {
			x2 = x + dx[i] * (l + 1);
			y2 = y + dy[i] * (l + 1);

			if (!Field(x2, y2)) continue;

			if (p.find(mp(mp(x2, y2), l + 1)) != p.end()) continue;
			v.pb(mp(Dist(x2, y2, fx, fy), mp(x2, y2)));
			p[mp(mp(x2, y2), l + 1)] = i;
		}
		sort(v.begin(), v.end());
		if (SIZE(v) > 30) v.resize(30);
		fi(0, SIZE(v) - 1) {
			qu.push(mp(v[i].second, l + 1));
		}
	}

	if (x != fx || y != fy) {
		printf("Error!\n");
		return;
	}

	int d;

	fdi(l, 1) {
		d = p[mp(mp(x, y), i)];
		if (d == 0)	ans += 'W';
		if (d == 1)	ans += 'S';
		if (d == 2)	ans += 'E';
		if (d == 3)	ans += 'N';
		x += dx[(d + 2) % 4] * i;
		y += dy[(d + 2) % 4] * i;
	}

	reverse(ans.begin(), ans.end());
	printf("%s\n", ans.c_str());
}

int main(int argc, char **argv) {
	if (argc == 1) {
		freopen("input.txt","r",stdin);
	} else {
		freopen(argv[1], "r",stdin);
	}
	freopen("output.txt","w",stdout);
	scanf("%d", &testq);
	for (test = 1; test <= testq; test++) {
		Read();
		printf("Case #%d: ", test);
		Solve();
		fflush(stdout);
	}
	return 0;
}
