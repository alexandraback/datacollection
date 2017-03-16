#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <queue>
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
#include <cstring>
#include <ctime>

using namespace std;

double p[100000];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int T;
	scanf("%d", &T);
	for (int test = 0; test < T; test ++) {
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i ++) scanf("%lf", &p[i]);
		double now = 1, ans = m + 2;
		for (int i = n; i >= 0; i --) {
			double tmp = 0;
			tmp += now * (i + m - n + i + 1);
			tmp += (1 - now) * (i + m - n + i + 1 + m + 1);
			if (tmp < ans) ans = tmp;
			if (i > 0) now *= p[n-i];
		}
		printf("Case #%d: %.10lf\n", test + 1, ans);
	}
	
	return 0;
}
