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

int main(int argc, char ** argv)
{
	int nt;

	scanf("%d", &nt);

	for (int t = 0; t < nt; t++) {
		double c, f, x;

		scanf("%lf %lf %lf", &c, &f, &x);

		double tba = 0.0;
		double result = 1e200;

		for (int nbuy = 0;; nbuy++) {
			if (tba > result)
				break;

			result = min(result, tba + x / (2.0 + nbuy * f));
			tba += c / (2.0 + nbuy * f);
		}

		printf("Case #%d: %.7f\n", t+1, result);
	}

	return 0;
}
