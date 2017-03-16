#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <utility>

#define MAX 15
#define OFFSET 205

std::vector<std::pair<int, int> > v;
void deal(int t) {
	int N;
	int day, tribe;
	int d[MAX], n[MAX], w[MAX], e[MAX], s[MAX], dd[MAX], dp[MAX], ds[MAX];
	int height[505];
	int newHeight[505];
	int su = 0;
	bool succeed;
	memset(height, 0, sizeof(height));
	memset(newHeight, 0, sizeof(newHeight));
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d%d%d%d%d%d%d%d", &d[i], &n[i], &w[i], &e[i], &s[i], &dd[i], &dp[i], &ds[i]);
	}
	v.clear();
	for (int i = 0; i < N; i++) {
		day = d[i];
		for (int j = 0; j < n[i]; j++) {
			v.push_back(std::make_pair(day, i));
			day += dd[i];
		}
	}
	std::sort(v.begin(), v.end());
	std::vector<std::pair<int, int> >::iterator it;
	day = -1;
	su = 0;
	for (it = v.begin(); it != v.end(); it++) {
		//printf("%d %d\n", it->first, it->second);
		tribe = it->second;
		if (day != it->first) {
			day = it->first;
			for (int i = 0; i < 500; i++) {
				if (height[i] < newHeight[i]) {
					height[i] = newHeight[i];
				}
			}
		}
		succeed = false;
		for (int i = w[tribe]; i < e[tribe]; i++) {
			if (height[i + OFFSET] < s[tribe]) {
				succeed = true;
				if (newHeight[i + OFFSET] <= s[tribe]) {
					newHeight[i + OFFSET] = s[tribe];
				}
			}
		}
		//for (int i = 0; i < 500; i++) {
			//printf("%d ", height[i]);
		//}
		if (succeed) {
			//printf("succeed");
			su++;
		}
		//printf("\n");
		w[tribe] += dp[tribe];
		e[tribe] += dp[tribe];
		s[tribe] += ds[tribe];
	}
	printf("Case #%d: %d\n", t + 1, su);
}
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		deal(i);
	}
}
