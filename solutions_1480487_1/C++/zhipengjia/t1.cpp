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

int s[200];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int T;
	scanf("%d", &T);
	for (int test = 0; test < T; test ++) {
		int n, sum = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i ++) {
			scanf("%d", &s[i]);
			sum += s[i];
		}
		printf("Case #%d: ", test + 1);
		for (int i = 0; i < n; i ++) {
			double head = 0, tail = 1;
			while (head + 1e-10 < tail) {
				double mid = (head + tail) / 2;
				double score = s[i] + mid * sum;
				double need = 0;
				for (int j = 0; j < n; j ++) {
					if (i == j) continue;
					if (s[j] < score) need += (score - s[j]) / sum;
				}
				if (need + mid < 1) head = mid; else tail = mid;
			}
			if (i < n - 1) printf("%.8lf ", tail * 100); else printf("%.8lf\n", tail * 100);
		}
	}
	
	return 0;
}
