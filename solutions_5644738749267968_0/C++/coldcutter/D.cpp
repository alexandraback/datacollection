/* Author: coldcutter
 * Problem: D. Deceitful War
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

const int N = 1005;

int n;
double a[N], b[N];
bool used[N];

int deceitfulWar() {
	memset(used, 0, sizeof(used));
	int score = 0;
	for (int j = n; j >= 1; --j) {
		bool find = 0;
		for (int i = n; i >= 1 && !find; --i) {
			if (!used[i]) {
				if (a[i] > b[j]) {
					++score;
					used[i] = 1;
					find = 1;
					break;
				}
			}
		}
		if (!find) {
			for (int i = 1; i <= n; ++i) {
				if (!used[i]) {
					used[i] = 1;
					break;
				}
			}
		}
	}
	return score;
}

int war() {
	memset(used, 0, sizeof(used));
	int score = 0;
	for (int i = n; i >= 1; --i) {
		bool find = 0;
		for (int j = 1; j <= n && !find; ++j) {
			if (!used[j] && b[j] > a[i]) {
				used[j] = 1;
				find = 1;
				break;
			}
		}
		if (!find) {
			++score;
			for (int j = 1; j <= n; ++j) {
				if (!used[j]) {
					used[j] = 1;
					break;
				}
			}
		}
	}
	return score;
}

int main() {
//	freopen("D.in", "r", stdin);
	int test;
	scanf("%d", &test);
	for (int kase = 1; kase <= test; ++kase) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%lf", &a[i]);
		}
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; ++i) {
			scanf("%lf", &b[i]);
		}
		sort(b + 1, b + n + 1);
		printf("Case #%d: %d %d\n", kase, deceitfulWar(), war());
	}
	return 0;
}

