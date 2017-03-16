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

int sign(double x) {
	if (fabs(x) < 1e-8) return 0;
	return (x > 0) ? 1 : -1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int T;
	scanf("%d", &T);
	for (int test = 0; test < T; test ++) {
		int n;
		scanf("%d", &n);
		int s[6], p[6];
		int tt = 0;
		for (int i = 0; i < n; i ++) {
			char tmp[10];
			scanf("%s%d%d", tmp, &s[i], &p[i]);
			if (tmp[0] == 'R') tt += 1 << i;
		}
		vector<double> L;
		L.push_back(0);
		for (int i = 0; i < n; i ++)
			for (int j = 0; j < n; j ++)
				if (s[i] > s[j]) {
					double t1 = (double)(p[i] - p[j] - 5) / (s[j] - s[i]);
					double t2 = (double)(p[i] - p[j] + 5) / (s[j] - s[i]);
					if (sign(t1) >= 0) L.push_back(t1);
					if (sign(t2) >= 0) L.push_back(t2);
				}
		sort(L.begin(), L.end());
		L.erase(unique(L.begin(), L.end()), L.end());
		vector< vector<int> > f, check;
		f.resize(L.size());
		check.resize(L.size());
		for (int i = 0; i < L.size(); i ++) {
			f[i].assign(1 << n, 0);
			check[i].assign(1 << n, 1);
			if (i == L.size() - 1) continue;
			for (int j = 0; j < 1 << n; j ++) {
				for (int x = 0; x < n; x ++) {
					if (check[i][j] == 0) break;
					for (int y = x + 1; y < n; y ++)
						if ((j & 1 << x) != 0 && (j & 1 << y) != 0 || (j & 1 << x) == 0 && (j & 1 << y) == 0) {
							double p1 = p[x] + s[x] * ((L[i] + L[i+1]) / 2);
							double p2 = p[y] + s[y] * ((L[i] + L[i+1]) / 2);
							if (sign(fabs(p1 - p2) - 5) < 0) {
								check[i][j] = 0;
								break;
							}
						}
				}
			}
		}
		f[0][tt] = 1;
		int ans = 0;
		for (int i = 0; i < L.size() - 1; i ++) {
			while (true) {
				bool flag = false;
				for (int j = 0; j < 1 << n; j ++)
					if (f[i][j] == 1) {
						for (int k = 0; k < n; k ++) {
							int tmp = j ^ (1 << k);
							if (f[i][tmp] == 0 && check[i][tmp] == 1) {
								f[i][tmp] = 1;
								flag = true;
							}
						}
					}
				if (! flag) break;
			}
			for (int j = 0; j < 1 << n; j ++) {
				if (f[i][j] == 1) ans = i;
				if (f[i][j] == 1 && check[i+1][j] == 1) f[i+1][j] = 1;
			}
		}
		if (ans + 1 != L.size() - 1)
			printf("Case #%d: %.10lf\n", test + 1, L[ans+1]);
		else
			printf("Case #%d: Possible\n", test + 1);
	}
	
	return 0;
}
