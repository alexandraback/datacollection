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
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef long long int64;
const double pi = acos (-1.0);
const double eps = 1.0e-10;

struct node {
	int day;
	int west, east;
	int strength;

	bool operator < (const node &another) const
	{
		return day > another.day;
	}
};

void solve()
{
	int height[1010];
	memset(height, 0, sizeof(height));
	int N, d, n, w, e, s, dd, dp, ds;
	scanf("%d", &N);
	int ans = 0;
	priority_queue<node> Q;
	while (N--) {
		scanf("%d%d%d%d%d%d%d%d",
			&d, &n, &w, &e, &s, &dd, &dp, &ds);
		for (int i = 0; i < n; ++i) {
			node tmp;
			tmp.day = d + i * dd;
			tmp.west = w + i * dp;
			tmp.east = e + i * dp;
			tmp.strength = s + i * ds;
			Q.push(tmp);
		}
	}
	vector <node> today;
	while (!Q.empty()) {
		node tmp = Q.top();
		Q.pop();
		if (today.size() > 0 && today[0].day != tmp.day) {
			for (int i = 0; i < today.size(); ++i) {
				for (int j = today[i].west; j < today[i].east; ++j)
					height[j + 500] = max(height[j + 500], today[i].strength);
			}
			today.clear();
		}
		for (int i = tmp.west; i < tmp.east; ++i) {
			if (height[i + 500] < tmp.strength) {
				ans++;
				//printf("%d %d %d %d\n", tmp.day, tmp.west, tmp.east, tmp.strength);
				break;
			}
		}
		today.push_back(tmp);
	}
	printf("%d\n", ans);
}

int main()
{
	int ncase;
	scanf("%d", &ncase);
	for (int icase = 1; icase <= ncase; ++icase) {
		printf("Case #%d: ", icase);
		solve();
	}
}
