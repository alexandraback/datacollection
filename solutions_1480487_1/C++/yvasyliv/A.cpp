#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <ctime>
#include <cmath>
#include <stdio.h>
#include <set>
#include <map>
#include <stack>
#include <fstream>
#include <list>

#define SZ(a) (int(a.size()))
#define MEM(a, val) memset(a, val, sizeof(a))

typedef unsigned long long ULL;
typedef long long LL;
typedef long double dbl;

using namespace std;

int n;
vector<int> f, g;

const dbl eps = 1e-10;

dbl X;

bool check(dbl S, dbl mn, int xi) {
	for (int i = 0; i < n; ++i) {
		if (i != xi) {
			if (dbl(f[i]) < mn) {
				S -= (mn - dbl(f[i]));
			}
		}
		if (S < 0.0)
			return true;
	}
	return false;
}

int main()
{
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int I = 1; I <= T;++I) {
		scanf("%d", &n);
		f.clear();
		g.clear();
		int tmp;
		X = 0.0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &tmp);
			f.push_back(tmp);
			g.push_back(tmp);
			X += tmp;
		}
		sort(g.begin(), g.end());
		printf("Case #%d:", I);
		for (int i = 0; i < n; ++i) {
			dbl l = 0.0;
			dbl r = 1.0;
			while (l < r - eps) {
				dbl mid = (l + r) / 2.0;
				if (check((1.0 - mid) * X, dbl(f[i]) + mid * X, i)) {
					r = mid;
				}
				else {
					l = mid;
				}
			}
			dbl ans = (l + r) / 2.0;
			ans *= 100.0;
			printf(" %0.10lf", ans);
		}
		printf("\n");
	}
	return 0;
}