#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/2)

typedef long long lint;

using namespace std;

int score(int n, vector <double> &a, vector <double> &b)
{
	int result = 0, i = n, lim = n;

	for (int j = n-1; j >= 0; j--) {
		while (i-1 >= 0 && a[i-1] > b[j]) i--;
		lim = min(lim, i + (n-1-j));
		if (lim < n-j) break;
		result = n-j;
	}

	return result;
}

int main(int argc, char ** argv)
{
	int nt;

	scanf("%d", &nt);

	for (int t = 0; t < nt; t++) {
		int n;

		scanf("%d", &n);

		vector <double> a(n, -1), b(n, -1);

		for (int i = 0; i < n; i++) scanf("%lf", &a[i]);
		for (int i = 0; i < n; i++) scanf("%lf", &b[i]);

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		printf("Case #%d: %d %d\n", t+1, score(n, b, a), n - score(n, a, b));
	}

	return 0;
}
