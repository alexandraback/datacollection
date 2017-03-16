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

int main() {
	freopen("A-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);

	scanf("%d", &tn);

	for (int test = 1; test <= tn; test++) {
		scanf("%lf %lf", &r, &t);

		ans = 0;

		for (; t > 0; r += 2.0) {
			area = (2 * r + 1);
			if (area <= t) {
				ans++;
				t -= area;
			}
			else
				break;
		}

		printf("Case #%d: %d\n", test, ans);
	}

	return 0;
}