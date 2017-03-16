#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>

#define si() (scanf("%d", &TEMP), TEMP)

using namespace std;

int TEMP;

int li[2000];
int N;
int m;

int v[1005];
int cy[1005];
int t[1005];
int dp[1005];
int re[1005];
 
void solve() {
	N = si();
	m = -1;
	for (int i = 1; i <= N; i++) {
		li[i] = si();
	}


	for (int i = 1; i <= N; i++) {
		v[i] = 0;
		cy[i] = 0;
	}

	for (int i = 1; i <= N; i++) {
		if (cy[i] > 0) continue;
		
		for (int j = 1; j <= N; j++) {
			v[j] = 0;
		}
		v[i] = 1;

		int s = li[i];
		int c = 1;
		
		while (s != i) {
			if (v[s] || cy[i]) break;
			v[s] = 1;
			c++;
			s = li[s];
		}
		if (s == i) {
			do {
				cy[s] = 1;
			} while (s != i);
			m = max(m, c);
		}
		else {
			cy[i] = -1;
		}
	}

	for (int i = 1; i <= N; i++) {
		v[i] = 0;
	}

	for (int i = 1; i <= N; i++) {
		if (li[li[i]] == i) {
			v[i] = 1;
		}
	}


	for (int i = 1; i <= N; i++) {
		t[i] = 0;
		if (v[i]) {
			t[i] = i;
			dp[i] = 0;
		}
	}
	bool flag = true;
	while (flag) {
		flag = false;

		for (int i = 1; i <= N; i++) {
			if (cy[i] > 0 || t[i] > 0) continue;
			if (t[li[i]] > 0) {
				t[i] = t[li[i]];
				dp[i] = dp[li[i]] + 1;
				flag = true;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		re[i] = 0;
	}
	for (int i = 1; i <= N; i++) {
		re[t[i]] = max(re[t[i]], dp[i]);
	}

	int res = 0;

	for (int i = 1; i <= N; i++) {
		if (v[i]) {
			res++;
			res += re[i];
		}
	}
	
	printf("%d\n", max(res, m));
}

int main(void) {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N = si();
	for (int i = 0; i < N; i++) {
		printf("Case #%d: ", i + 1);
		solve();
	}
}

