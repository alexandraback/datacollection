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
#include <cstring>
#include <cassert>
#include <utility>
#include <iomanip>

using namespace std;

const int MAXN = 10 * 1000500;

int tn;
int n;
int dp[MAXN];
bool used[MAXN];
queue <int> q;

int revNum(int x) {
	int res = 0;
	while (x) {
		res = res * 10 + (x % 10);
		x /= 10;
	}
	return res;
}

int main() {
	//assert(freopen("input.txt","r",stdin));
	//assert(freopen("output.txt","w",stdout));

	scanf("%d", &tn);

	used[1] = true;
	dp[1] = 1;
	q.push(1);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur + 1 < MAXN) {
			if (!used[cur + 1]) {
				dp[cur + 1] = dp[cur] + 1;
				used[cur + 1] = true;
				q.push(cur + 1);
			}
		}
		
		int rev = revNum(cur);
		if (rev < MAXN && !used[rev]) {
			used[rev] = true;
			dp[rev] = dp[cur] + 1;
			q.push(rev);
		}
	}

	for (int test = 1; test <= tn; test++) {
		scanf("%d", &n);
		printf("Case #%d: %d\n", test, dp[n]);
	}

	return 0;
}