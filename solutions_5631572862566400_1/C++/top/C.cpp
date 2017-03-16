#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e3+10;

int n,t[N];
int in[N],dp[N],cyc[N];
int q[N],f,r;
bool use[N];

inline int solve () {
	scanf ("%d", &n);

	for (int i = 1;i <= n;i ++) {
		in[i] = 0;
		dp[i] = 0;
		cyc[i] = 0;
		use[i] = false;
	}
	f = 0;
	r = -1;

	for (int i = 1;i <= n;i ++) {
		scanf ("%d", &t[i]);
		in[t[i]] ++;
	}

	for (int i = 1;i <= n;i ++) {
		if (in[i] == 0) {
			q[++ r] = i;
		}
	}

	while (f <= r) {
		int u = q[f ++];
		int v = t[u];
		if ((-- in[v]) == 0) {
			q[++ r] = v;
		}

		dp[v] = max (dp[v], dp[u]+1);
	}

	int ans = 0,sum = 0;
	for (int i = 1;i <= n;i ++) {
		if (in[i] != 0 and cyc[i] == 0) {
			int j = t[i],c = 1;
			while (i != j) {
				j = t[j];
				c ++;
			}
			cyc[i] = c;
			j = t[i];
			while (i != j) {
				cyc[j] = c;
				j = t[j];
			}

			ans = max (ans, c);

			if (c == 2) {
				sum += dp[i]+c+dp[t[i]];
			}
		}
	}
	ans = max (ans, sum);
	return ans;
}

int main () {
	int t;
	scanf ("%d", &t);

	for (int i = 1;i <= t;i ++) {
		printf ("Case #%d: %d\n", i, solve ());
	}
}