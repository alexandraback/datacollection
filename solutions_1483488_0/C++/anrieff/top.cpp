#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <assert.h>
#include <cmath>
#include <set>
using namespace std;

#define FOR(i,n) for (int i = 0; i < n; i++)
#define abs(x) ((x)<0?(-(x)):(x))
#define REP(i,v) for (unsigned i = 0; i < v.size(); i++)
#define RL(i,v) for (unsigned i = 0; i < v.length(); i++)
typedef long long ll;

void solve(void)
{
	set<pair<int, int> > ss;
	int a, b;
	scanf("%d%d", &a, &b);
	char tmp[32];
	sprintf(tmp, "%d", a);
	int n = (int) strlen(tmp);
	
	for (int x = a; x <= b; x++) {
		string s;
		sprintf(tmp, "%d", x);
		s = tmp;
		for (int i = 1; i < n; i++) {
			string s2 = s.substr(i) + s.substr(0, i);
			if (s2[0] == '0') continue;
			int y;
			sscanf(s2.c_str(), "%d", &y);
			if (y >= a && y <= b && y != x)
				ss.insert(make_pair(min(x, y), max(x, y)));
		}
	}
	printf("%d\n", int(ss.size()));
}

int main(void)
{
	//freopen("/home/vesko/gcj/c.in", "rt", stdin);
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}
