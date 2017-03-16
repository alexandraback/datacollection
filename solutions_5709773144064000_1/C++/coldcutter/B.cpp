/* Author: coldcutter
 * Problem: B. Cookie Clicker Alpha
 * Tags:
 */
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <iostream>
using namespace std;

double c, f, x;

int main() {
	int test;
	scanf("%d", &test);
	for (int kase = 1; kase <= test; ++kase) {
		scanf("%lf %lf %lf", &c, &f, &x);
		double ans = 1e9, cost = 0, s = 2.0;
		for (int i = 0; i <= (int)x && cost < ans; ++i) {
			if (cost + x / s < ans) {
				ans = cost + x / s;
			}
			cost += c / s;
			s += f;
		}
		printf("Case #%d: %.7lf\n", kase, ans);
	}
	return 0;
}

