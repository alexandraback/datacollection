#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <utility>
#include <iomanip>

using namespace std;

const double pi = acos(-1.0);

int tn, ans;
double t, r, area;
long long lft, rgt, m;

double getarea(double m) {
	double ans = 2 * r * m;
	ans += (1 + 1 + (m - 1) * 4) * m / 2;

	return ans;
}

int main() {
	freopen("A-large.in","r",stdin);
	freopen("output.txt","w",stdout);

	scanf("%d", &tn);

	for (int test = 1; test <= tn; test++) {
		scanf("%lf %lf", &r, &t);

		ans = 0;
		
		lft = 1; rgt = 1000 * 1000 * 1000;

		while (lft != rgt) {
			m = (lft + rgt + 1) / 2;

			area = getarea((double)m);

			if (area > t) 
				rgt = m - 1;
			else
				lft = m;
		}

		printf("Case #%d: %d\n", test, lft);
	}

	return 0;
}