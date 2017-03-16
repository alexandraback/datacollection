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

const int SIZE = 128;

int n, s, p;
int sums[SIZE];

int res[SIZE][SIZE];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tests;
	scanf("%d", &tests);
	for (int tt = 1; tt<=tests; tt++) {

		scanf("%d%d%d", &n, &s, &p);
		for (int i = 0; i<n; i++) scanf("%d", &sums[i]);

		memset(res, -63, sizeof(res));
		res[0][0] = 0;
		for (int i = 0; i<n; i++)
			for (int j = 0; j<=s; j++) if (res[i][j] >= 0) {
				int arr[3] = {0};
				for (arr[0] = 0; arr[0]<=10; arr[0]++)
				for (arr[1] = 0; arr[1]<=10; arr[1]++)
				for (arr[2] = 0; arr[2]<=10; arr[2]++) {
					int smin = min(min(arr[0], arr[1]), arr[2]);
					int smax = max(max(arr[0], arr[1]), arr[2]);
					int tsum = arr[0] + arr[1] + arr[2];

					if (tsum != sums[i]) continue;
					if (smax - smin > 2) continue;
					int surp = (smax - smin == 2);
					int score = (smax >= p);

					if (res[i+1][j+surp] < res[i][j] + score)
						res[i+1][j+surp] = res[i][j] + score;
				}
			}

		printf("Case #%d: %d\n", tt, res[n][s]);
		fflush(stdout);
	}
	return 0;
}
