#include <cassert>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cstddef>
#include <cctype>
#include <cmath>
#include <cstring>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <numeric>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <bitset>
#include <list>
#include <string>
#include <functional>
#include <utility>
using namespace std;
typedef long long llint;
int const N = 1000;
int n;
int cost[N][2];
bool readin() {
	if (scanf("%d", &n) == EOF) {
		return false;
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &cost[i][0], &cost[i][1]);
	}
	return true;
}
int solve() {
	int ret = 0;
	int stars = 0;
	int n2 = 0;
	vector <bool> u1(n, false);
	vector <bool> u2(n, false);
	while (n2 < n) {
		++ret;
		int idx = -1;
		for (int i = 0; i < n; ++i) {
			if (!u2[i] && cost[i][1] <= stars) {
				idx = i;
				break;
			}
		}
		if (idx != -1) {
			stars += (!u1[idx] ? 2 : 1);
			++n2;
			u1[idx] = true;
			u2[idx] = true;
			continue;
		}
		int maxv = -1;
		idx = -1;
		for (int i = 0; i < n; ++i) {
			if (!u1[i] && cost[i][0] <= stars && cost[i][1] > maxv) {
				idx = i;
				maxv = cost[i][1];
			}
		}
		if (idx == -1) {
			return -1;
		}
		++stars;
		u1[idx] = true;
	}
	return ret;
}
int main() {
	int tc;
	scanf("%d", &tc);
	for (int cc = 1; cc <= tc; ++cc) {
		readin();
		int res = solve();
		printf("Case #%d: ", cc);
		if (res >= 0) {
			printf("%d\n", res);
		} else {
			printf("Too Bad\n");
		}
	}
	return 0;
}
