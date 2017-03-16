#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#define E(c) cerr<<#c
#define Eo(x) cerr<<#x<<" = "<<(x)<<endl

const int SIZE = 512;

int n;
int64 arr[SIZE];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tests;
	scanf("%d", &tests);
	for (int tt = 1; tt<=tests; tt++) {
		scanf("%d", &n);
		for (int i = 0; i<n; i++) scanf("%I64d", &arr[i]);

		vector<pair<int64, int> > subs;
		for (int i = 0; i<1<<n; i++) {
			int64 sum = 0;
			for (int j = 0; j<n; j++) if (i & (1<<j))
				sum += arr[j];
			subs.push_back(make_pair(sum, i));
		}

		sort(subs.begin(), subs.end());

		int ans1 = -1, ans2 = -1;
		for (int i = 1; i<subs.size(); i++)
			if (subs[i].first == subs[i-1].first) {
				ans1 = subs[i-1].second;
				ans2 = subs[i].second;
				break;
			}

		printf("Case #%d: \n", tt);
		if (ans1 < 0) printf("Impossible\n");
		else {
			for (int i = 0; i<n; i++) if (ans1 & (1<<i)) printf("%I64d ", arr[i]);
			printf("\n");
			for (int i = 0; i<n; i++) if (ans2 & (1<<i)) printf("%I64d ", arr[i]);
			printf("\n");
		}
		fflush(stdout);
	}
	return 0;
}
