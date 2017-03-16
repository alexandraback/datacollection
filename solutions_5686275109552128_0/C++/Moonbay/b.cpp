/*
 * Author    : ben
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <functional>
#include <numeric>
#include <cctype>
using namespace std;
typedef long long LL;
const int MAXD = 1010;
int p[MAXD], D;

int work() {
	scanf("%d", &D);
	for (int i = 0; i < D; i++) {
		scanf("%d", &p[i]);
	}
	sort(p, p + D);
	int ret = p[D - 1];
	for (int up = p[D - 1] - 1; up > 0; up--) {
		int time = up;
		for (int i = D - 1; i >= 0; i--) {
			if (p[i] <= up) {
				break;
			}
			time += ceil((p[i] + 0.0) / up) - 1;
			if (time >= ret) {
				break;
			}
		}
		if (time < ret) {
			ret = time;
		}
	}
	return ret;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		printf("Case #%d: %d\n", t, work());
	}
	return 0;
}


