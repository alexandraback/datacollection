#include <cstdio>

const int MAX_N = 105;
int T, N, S, P;
int nums[MAX_N];

int solve() {
	int s_left = S;
	int total = 0;
	for (int i = 0; i < N; ++i) {
		int l_avg = nums[i]/3;
		if (nums[i]%3 == 0) {
			if (l_avg >= P) {total++; continue;}
			if (nums[i] > 0 && l_avg+1 >= P && s_left > 0) {s_left--; total++; continue;}
		} else if (nums[i]%3 == 1) {
			if (l_avg+1 >= P) {total++; continue;}
		} else {
			if (l_avg+1 >= P) {total++; continue;}
			if (l_avg+2 >= P && s_left > 0) {s_left--; total++; continue;}
		}
	}
	return total;
}

int main() {
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		scanf("%d %d %d", &N, &S, &P);
		for (int i = 0; i < N; ++i)
			scanf("%d", &nums[i]);
		printf("Case #%d: %d\n", t, solve());
	}	
}