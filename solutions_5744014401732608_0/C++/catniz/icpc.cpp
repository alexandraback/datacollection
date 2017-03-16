#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <tuple>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstdlib>
#include <stack>
#include <map>

using namespace std;

#define INF 1987654321
#define MAX 60
#define MOD 1000000007
#define CHK 1023

int arr[MAX][MAX];

void set_arr(int n, int set_num) {
	arr[1][set_num] = 1;
	for (int i = set_num; i <= n; i++) {
		for (int k = i + 1; k <= n; k++) {
			arr[i][k] = 1;
		}
	}
}

int main() {

		freopen("B-small.in", "r", stdin);
		freopen("small.out", "w", stdout);

	int TC;
	scanf("%d", &TC);
	long long int dp[MAX] = { 1, 1, 1, };
	for (int i = 3; i < MAX; i++) {
		dp[i] = dp[i - 1] * 2;
	}

	for (int tc = 1; tc <= TC; tc++) {
		memset(arr, 0, sizeof(arr));
		printf("Case #%d: ", tc);
		int b; long long int m;
		scanf("%d %lld", &b, &m);

		if (m > dp[b]) {
			printf("IMPOSSIBLE\n");
			continue;
		}

		printf("POSSIBLE\n");
		for (int i = b - 1; i && m; i--) {
			if (m >= dp[i]) {
				m -= dp[i];
				set_arr(b, b+1-i);
			}
		}
		for (int i = 1; i <= b; i++) {
			for (int k = 1; k <= b; k++) {
				printf("%d", arr[i][k]);
			}
			printf("\n");
		}

	}


	return 0;
}