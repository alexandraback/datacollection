#define _CRT_SECURE_NO_WARNINGS
#include <functional>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <ctime>
#include <set>
#include <map>

#define ll long long
#define ld long double
#define sqr(x) ((x) * (x))
#define mp make_pair
#define TASKNAME ""

const int inf = (int)1e9;
const int mod = (int)1e9 + 7;
const ll infll = (ll)1e18;
const ld eps = 1e-9;

using namespace std;

set<int> coins;
void mc(const vector<int> &fcoins, int pos, int csum) {
	if (pos == fcoins.size())
		return;
	for (int i = pos; i < fcoins.size(); i++) {
		coins.insert(csum + fcoins[i]);
		mc(fcoins, i + 1, csum + fcoins[i]);
	}
}

void solve() {
	int c, d, v;
	scanf("%d %d %d", &c, &d, &v);
	vector<int> fcoins(d);
	for (int i = 0; i < d; i++)
		scanf("%d", &fcoins[i]);
	coins.clear();
	mc(fcoins, 0, 0);
	set<int> scoins(fcoins.begin(), fcoins.end());
	vector<vector<int> > vs;
	vector<int> countx(31);
	bool f = true;
	while (vs.size() != 0 || f) {
		f = false;
		vs.clear();
		countx.clear();
		countx.resize(31, 0);
		for (int i = 1; i <= v; i++) {
			if (coins.find(i) != coins.end())
				continue;
			vector<int> cur;
			cur.push_back(i);
			countx[i]++;
			for (auto it = coins.begin(); it != coins.end(); it++) {
				int coin = *it;
				if (coin > i)
					break;
				int addc = i - coin;
				if (scoins.find(addc) == scoins.end()){
					countx[addc]++;
					cur.push_back(addc);
				}
			}
			vs.push_back(cur);
		}
		if (vs.size() == 0)
			break;
		int m = vs[0][0];
		for (int i = 0; i < vs[0].size(); i++) {
			int tt = vs[0][i];
			if (countx[tt] > countx[m])
				m = tt;
		}
		scoins.insert(m);
		coins.clear();
		mc(vector<int>(scoins.begin(), scoins.end()), 0, 0);
	}
	for (int i = 0; i < fcoins.size(); i++)
		scoins.erase(fcoins[i]);
	printf("%d", scoins.size());
}

int main() {
#ifdef __DEBUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	clock_t start = clock();
#endif
	int tests;
	scanf("%d", &tests);
	for (int i = 1; i <= tests; i++) {
		printf("Case #%d: ", i);
		solve();
		printf("\n");
		fprintf(stderr, "Case #%d Done\n", i);
	}

#ifdef __DEBUG__
	fprintf(stderr, "\nTime: %Lf\n", ((clock() - start) / (ld)CLOCKS_PER_SEC));
#endif
	return 0;
}