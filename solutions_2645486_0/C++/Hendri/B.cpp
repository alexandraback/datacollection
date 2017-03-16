#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

int T;
int E, R, N;
long long v[10001];
int dp[11][6];

int go(int i, int e) {
	if (i == N)return 0;
	int maxi = -1;
	for (int j = 0; j <= e; j++) {
		int remain = min(E, e - j + R);
		int tempmaxi = j * v[i] + go(i+1, remain);
		maxi = max(maxi, tempmaxi);
	}
	return dp[i][e] = maxi;
}

int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case #" << t << ": ";
		cin >> E >> R >> N;
		int idx;
		long long curmax = -1;
		for (int i = 0; i < N; i++) {
			cin >> v[i];
			if (v[i] > curmax) {
				curmax = v[i];
				idx = i;
			}
		}
		memset(dp, -1, sizeof(dp));
		cout << go(0, E) << endl;
	}
	return 0;
}
